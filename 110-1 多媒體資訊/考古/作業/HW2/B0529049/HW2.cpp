#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using std::string;
using std::fstream;
void RGBtoHSI();
void HSItoRGB();
void HistogramEqualization();
void GammaTransformation();
int huttonmin(int a,int b,int c);
double H[512*512],S[512*512],I[512*512],theta[512*512],gamma=1;
unsigned char R[512*512],G[512*512],B[512*512];
int main(void)
{ 
	char right,left;
	int size=512*512*3,i=0,j=0;
	unsigned char buff[size];
	int a;
	FILE *fp1,*fp2,*fp3;
	cout<<"請輸入Gamma Transformation的Gamma值(預設為1)："<<endl;
	cin>>gamma; 
	fp1=fopen("peppers.raw","rb");
    fp2=fopen("tmp.txt","w+");
    fp3=fopen("c.raw","wb");
    fprintf(fp2,"left\tright\n");
    for(i=0;i<512*512*3;i+=size){
		fread(&buff,size,1,fp1);
     
    }
    for(j=0;j<512*512;j++){
        R[j]=buff[j]; 
    }
    for(j=512*512;j<512*512*2;j++){
        G[j-512*512]=buff[j]; 
    }
     for(j=512*512*2;j<512*512*3;j++){
      	B[j-512*512*2]=buff[j];
    }

	RGBtoHSI();
	int test=512*400;
	cout<<"I="<<I[test]<<" S="<<S[test]<<" H="<<H[test]<<" θ="<<theta[test]<<" R="<<(int)R[test]<<" G="<<(int)G[test]<<" B="<<(int)B[test]<<endl;//41 6.782329983125268139064556326626 
   HistogramEqualization();
   GammaTransformation();
	HSItoRGB();  
    cout<<"I="<<I[test]<<" S="<<S[test]<<" H="<<H[test]<<" θ="<<theta[test]<<" R="<<(int)R[test]<<" G="<<(int)G[test]<<" B="<<(int)B[test];
	for(i=0;i<512*512;i++){
		buff[i]=R[i];
		buff[i+512*512]=G[i];
		buff[i+512*512*2]=B[i];
	}
	 for(i=0;i<512*512*3;i+=size){
	
        fwrite(&buff,size,1,fp3); 
    }
    
	fclose(fp1);
    fclose(fp2);
    fclose(fp3);
	return 0;
}
void GammaTransformation(){
	int i;
	for(i=0;i<512*512;i++){
		S[i]=pow(S[i],gamma);
	}
}
void HistogramEqualization(){
	int i;
	int n[256];
	for(i=0;i<256;i++){
		n[i]=0;
	}
	for(i=0;i<512*512;i++){
		n[(int)round(I[i])]++;
	}
	for(i=1;i<256;i++){
		n[i]=n[i]+n[i-1];
	}
	for(i=1;i<256;i++){
		n[i]=n[i]/512.0/512.0*255.0;
			
	}
	for(i=0;i<512*512;i++){
		I[i]=n[(int)round(I[i])];
	}
	//cout<<n[155];
} 
void RGBtoHSI(){
	int i;
	for(i=0;i<512*512;i++){
		theta[i]=acos(0.5*(((int)R[i]-(int)G[i])+((int)R[i]-(int)B[i]))/
		sqrt(pow((int)R[i]-(int)G[i],2.0)+((int)R[i]-(int)B[i])*((int)G[i]-(int)B[i])))/M_PI*180;
		if((int)B[i]>(int)G[i])
			H[i]=360-theta[i];
		else
			H[i]=theta[i]; 
		S[i]=1-3.0*huttonmin((int)R[i],(int)G[i],(int)B[i])/((int)R[i]+(int)G[i]+(int)B[i]);
		I[i]=((int)R[i]+(int)G[i]+(int)B[i])/3.0;
	}
}
void HSItoRGB(){
	int i;
	for(i=0;i<512*512;i++){
			 
		if(H[i]>=0&&H[i]<120){
			R[i]=min(255.0,floor(I[i]*(1+S[i]*cos(H[i]/180*M_PI)/cos((60-H[i])/180*M_PI))));
			B[i]=min(255.0,floor(I[i]*(1-S[i])));
			G[i]=min(255.0,floor(3*I[i]-R[i]-B[i]));

		//cout << "i" << i << ":" << (unsigned int)I[i] << endl;
		//cout << "r" << i << ":" << (unsigned int)R[i] << endl; 
		//cout << "b" << i << ":" << (unsigned int)B[i] << endl; 	
	

		}else if(H[i]>=120&&H[i]<240){
			H[i]=H[i]-120;
			G[i]=min(255.0,floor(I[i]*(1+S[i]*cos(H[i]/180*M_PI)/cos((60-H[i])/180*M_PI))));
			R[i]=min(255.0,floor(I[i]*(1-S[i])));
			B[i]=min(255.0,floor(3*I[i]-G[i]-R[i]));

		}else{ 
			H[i]=H[i]-240;
			B[i]=min(255.0,floor(I[i]*(1+S[i]*cos(H[i]/180*M_PI)/cos((60-H[i])/180*M_PI))));
			G[i]=min(255.0,floor(I[i]*(1-S[i])));
		 	R[i]=min(255.0,floor(3*I[i]-G[i]-B[i]));
		 	}
	}

}
int huttonmin(int a,int b,int c){
	if(a-b<=0&&a-c<=0)
		return a;
	else if(b-a<=0&&b-c<=0)
		return b;
	else 
		return c;
}
