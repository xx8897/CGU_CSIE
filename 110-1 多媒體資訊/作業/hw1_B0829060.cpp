#include <iostream>
#include <complex>
#include <fstream>
#include <math.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

#define _USE_MATH_DEFINES
#define pi 3.141592608

class DFT_Project{
	public:
		DFT_Project(int n);
		~DFT_Project();
		void openReadFile(char const name[]);
		void openWriteFile(char name[]);
		void SaveFile(int arr[],int num);
		int* LoadFile(int arr[],int num,bool option);
		void GetHeader();
		void GetBody(int n);
		void GetEnd();
		
		complex<float> *DFT(int arr[],int num);
		complex<float> *InverseDFT(complex<float> arr[],int num);
		complex<float> *low_pass(complex<float> arr[],int num);
		int* Float_to_Int(complex<float> arr[],int num);
		
		void SetVolumn(float f);
		float *Change(float arr[],int num);

		void Main();
		void Block(int num);
	private:
		int TotalLength,HeaderLength,BodyLength,EndLength;
		int N;
		int *header,*out2,*body,*end;
		complex<float> *out;
		float VolumnFactor;
		ifstream input;
		ofstream output;

};
DFT_Project::DFT_Project(int n){
	N=n;
	HeaderLength=44;
	header = new int[HeaderLength];
	body = new int [N];
	out = new complex<float> [N];
	out2 = new int [N];
	VolumnFactor=0.8;
}
DFT_Project::~DFT_Project(){
	delete header;
	delete body;
	delete end;
	delete out;
	delete out2;
	input.close();
	output.close();
}
void DFT_Project::openReadFile(char const name[]){
	input.open(name,ios::in | ios::binary);
	if(!input){
		cout<<"input failed!";
	}
}
void DFT_Project::openWriteFile(char name[]){
	output.open(name,ios::out | ios::binary);
	if(!output){
		cout<<"output failed!";
	}
}
void DFT_Project::SaveFile(int arr[],int num){
	for(int i=0;i<num;i++){
		output.put(arr[i]);
	}
}
int* DFT_Project::LoadFile(int arr[],int num,bool option){
	char buffer;
	unsigned char ch2;
	for(int i=0;i<num;i++){
		BodyLength=(option)?BodyLength-1:BodyLength;	// reading header and end,length--
		input.get(buffer);
		ch2=buffer;
		arr[i]=(int)ch2;
	}
	return arr;
}
void DFT_Project::GetHeader(){
	printf("geting header\n");
	header=LoadFile(header,HeaderLength,0);
	BodyLength=(int)(header[40]+header[41]*pow(16,2)+header[42]*pow(16,4)+header[43]*pow(16,6));
	TotalLength=(int)(header[4]+header[5]*pow(16,2)+header[6]*pow(16,4)+header[7]*pow(16,6))+8;
	EndLength=TotalLength-BodyLength-HeaderLength;
}
void DFT_Project::GetBody(int n){
	body=LoadFile(body,n,1);
}
void DFT_Project::GetEnd(){
	printf("geting end\n");
	end = new int[EndLength];
	end = LoadFile(end,EndLength,0);
}
complex<float>* DFT_Project::DFT(int arr_origin[],int num){
	complex<float> f,ck;
	complex<float> *arr_transform = new complex<float> [num];
	for(int k=0;k<num;k++){
		f=0;
		for(int n=0;n<num;n++){
			f.real(f.real()+cos(2*pi*k*n/num)*arr_origin[n]);
			f.imag(f.imag()+sin(2*pi*k*n/num)*arr_origin[n]);
		}
		arr_transform[k]=f;
	}
	return arr_transform;
}
complex<float>* DFT_Project::InverseDFT(complex<float> arr_transform[],int num){
	complex<float> f;
	complex<float> *arr_origin = new complex<float> [num];
	std::complex<float> temp2;
	for(int n=0;n<num;n++){
		f=0;
		for(int k=0;k<num;k++){
			temp2.real(cos(2*pi*k*n/num));
			temp2.imag(0-sin(2*pi*k*n/num));
			temp2*=arr_transform[k];
			f+=temp2;
		}
		f.real(f.real()/num);
		f.imag(f.imag()/num);
		arr_origin[n]=f;
	}
	return arr_origin;
}

complex<float>* DFT_Project::low_pass(complex<float> arr[],int num){
	complex<float> *arr_filtered = new complex<float> [num];
	std::complex<float> factor;
	for(int k=0;k<num;k++){
		factor.real(pow(0.98,k));
		factor.imag(pow(0.98,k));
		arr_filtered[k] = arr[k]*factor;
	}
	return arr_filtered;
}

int* DFT_Project::Float_to_Int(complex<float> arr[],int num){
	int* int_arr = new int [num];
	for(int i=0;i<num;i++){
		int_arr[i]=arr[i].real();
	}
	return int_arr;
}

void DFT_Project::SetVolumn(float f){
	VolumnFactor=f;
}

//float* DFT_Project::Change(float arr[],int num){
//	float *arr2 = new float [num];
//	arr2[0]=arr[0];
//	arr2[1]=arr[1];
//	for(int k=2;k<num;k++){
//		arr2[k]=arr[k-1];
//	}
//	return arr2;
//}

void DFT_Project::Block(int num){
	GetBody(num);	
	
	//printf("Start DFT transform\n");
	out=DFT(body,num);
	
	//printf("Start low_pass\n");
	out=low_pass(out,num);//�C�q�o�i �����O���ؤG �}�ҬO���ؤT 

//	printf("change voice"); not work!!
//	out=Change(out,num);

	//printf("Start invDFT transform\n");
	out=InverseDFT(out,num);
	out2=Float_to_Int(out,num);
	
	//printf("Writing back file\n");
	SaveFile(out2,num);
}
void DFT_Project::Main(){
	GetHeader();
	SaveFile(header,HeaderLength);
	
	printf("start calculating\n");
	do{
		Block(N);
		//printf("%d\t",BodyLength);
	}while(BodyLength-N>0);
	
	printf("writing end\n");
	
	if(EndLength>0){
		GetEnd();
		SaveFile(end,EndLength);
	}
	
	printf("finish!\n");
}

int main(){
	// set input file
	string wav_url = "Nello.wav";
    char const *wav_url_arr = wav_url.c_str();
    
    // set output file
	string out_name = "Nello3.wav";
	char name[out_name.length()+1];
	strcpy(name, out_name.c_str());
	
	int n = 512;	// k have same value as n
	DFT_Project fftpr(n);
	fftpr.openReadFile(wav_url_arr);
	fftpr.openWriteFile(name);
	fftpr.Main();
	
	return 0;
}
