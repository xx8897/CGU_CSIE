#include <iostream>
#include <fstream>
#include <math.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define _USE_MATH_DEFINES

class Demo{
	public:
		Demo(int n);
		~Demo();
		void ReadFile(char name[]);
		void WriteFile(char name[]);
		void OutputArray(int arr[],int num);
		int* GetArray(int arr[],int num,bool option);
		void GetHeader();
		void GetBody(int n);
		void GetEnd();
		
		float *DCT(int arr[],int num);
		int *InverseDCT(float arr[],int num);
		float *Filtering(float arr[],int num);
		int* Float_to_Int(float arr[],int num);
		
		void SetVolumn(float f);
		float *Change(float arr[],int num);

		void Basic(int option);
		void Base(int num,int option);
	private:
		int TotalLength,HeaderLength,BodyLength,EndLength;
		int N;
		int *header,*out2,*body,*end;
		float *out;
		float VolumnFactor;
		ifstream input;
		ofstream output;

};
Demo::Demo(int n){
	N=n;
	HeaderLength=44;
	header = new int[HeaderLength];
	body = new int [N];
	out = new float [N];
	out2 = new int [N];
	VolumnFactor=0.8;
}
Demo::~Demo(){
	delete header;
	delete body;
	delete end;
	delete out;
	delete out2;
	input.close();
	output.close();
}
void Demo::ReadFile(char name[]){
	input.open(name,ios::in | ios::binary);
	if(!input){
		cout<<"Can't open file!";
	}
}
void Demo::WriteFile(char name[]){
	output.open(name,ios::out | ios::binary);
	if(!output){
		cout<<"Can't open file!";
	}
}
void Demo::OutputArray(int arr[],int num){
	for(int i=0;i<num;i++){
		output.put(arr[i]);
	}
}
int* Demo::GetArray(int arr[],int num,bool option){
	char ch;
	unsigned char ch2;
	//option 0=header||end 1=body
	for(int i=0;i<num;i++){
		BodyLength=(option)?BodyLength-1:BodyLength;
		input.get(ch);
		ch2=ch;
		arr[i]=(int)ch2;
	}
	return arr;
}
void Demo::GetHeader(){
	header=GetArray(header,HeaderLength,0);
	BodyLength=(int)(header[40]+header[41]*pow(16,2)+header[42]*pow(16,4)+header[43]*pow(16,6));
	TotalLength=(int)(header[4]+header[5]*pow(16,2)+header[6]*pow(16,4)+header[7]*pow(16,6))+8;
	EndLength=TotalLength-BodyLength-HeaderLength;
}
void Demo::GetBody(int n){
	body=GetArray(body,n,1);
}
void Demo::GetEnd(){
	end = new int[EndLength];
	end = GetArray(end,EndLength,0);
}
float* Demo::DCT(int arr[],int num){
	float f,ck;
	float *arr2 = new float [num];
	for(int k=0;k<num;k++){
		f=0;
		ck=(k==0)?sqrt(2)/2:1;
		for(int n=0;n<num;n++){
			f+=cos((2*n+1)*k*M_PI/(2*num))*arr[n];
		}
		arr2[k]=ck*f/sqrt(num/2);
	}
	return arr2;
}
int* Demo::InverseDCT(float arr[],int num){
	float f,ck;
	int *arr2 = new int [num];
	int temp;
	for(int n=0;n<num;n++){
		f=0.0;
		for(int k=0;k<num;k++){
			ck=(k==0)?sqrt(2)/2:1;
			f+=ck/sqrt(num/2)*cos((2*n+1)*k*M_PI/2/num)*arr[k];
		}
		if((int)(f*10)%10>=5){
			temp=(int)f+1;
		} 
		else{
			temp=(int)f;
		}
		arr2[n]=temp;
	}
	return arr2;
}
float* Demo::Filtering(float arr[],int num){
	float *arr2 = new float [num];
	int h[num];
	for(int i=0; i<num; i++) h[i] = (i<=0.5*num)? 1:0;
	for(int j=0; j<num; j++){
		float y = 0;
		for(int k=0; k<num; k++){
			if(j-k>=0) y += h[k] * arr[j-k];
		}
		arr2[j] = y;
	}
	return arr2;
}
int* Demo::Float_to_Int(float arr[],int num){
	int* arr2 = new int [num];
	for(int i=0;i<num;i++){
		arr2[i]=(int)arr[i];
	}
	return arr2;
}
void Demo::SetVolumn(float f){
	VolumnFactor=f;
}
float* Demo::Change(float arr[],int num){
	float *arr2 = new float [num];
	arr2[0]=arr[0];
	arr2[1]=arr[1];
	for(int k=2;k<num;k++){
		arr2[k]=arr[k-1];
	}
	return arr2;
}
void Demo::Base(int num,int option){
	GetBody(num);
	switch(option){
	
		case 1:
			out=DCT(body,num);
			out2=Float_to_Int(out,num);
			break;
		case 2:
			out=DCT(body,num);
			out2=InverseDCT(out,num);
			break;
		case 3:
			out=DCT(body,num);
			out=Filtering(out,num);
			out2=InverseDCT(out,num);
			break;
		case 4:
			out=DCT(body,num);
			out=Change(out,num);
			out2=InverseDCT(out,num);
			break;
		default:
		exit(1);
	}
	OutputArray(out2,num);
}
void Demo::Basic(int option){
	GetHeader();
	OutputArray(header,HeaderLength);
	
	do{
		Base(N,option);
	}while(BodyLength-N>0);
	out=new float [BodyLength];
	out2=new int [BodyLength];
	body=new int [BodyLength];
	Base(BodyLength,option);
	if(EndLength>0){
		GetEnd();
		OutputArray(end,EndLength);
	}
}

int main(){
	char name[10]={};
	int n,option;
	float vf;
	cout<<"Input Write File Name: ";
	cin>>name;
	cout<<"Input N(32/64/128/256): "; 
	cin>>n;
	cout<<"----------OPTION----------"<<endl;
	cout<<"]: 1=DCT\n]: 2=DCT and InverseDCT\n]: 3=Filtering\n]: 4=Change Voice\n]:  ";
	cin>>option;
	if(option<5){
		Demo DD(n);
		DD.ReadFile("Nello.wav");
		DD.WriteFile(name);
		if(option==4)
			DD.SetVolumn(vf);
		DD.Basic(option);
	}
	return 0;
}
