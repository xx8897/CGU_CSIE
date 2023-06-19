#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

void HistogramEqualization(float **I);
void GammaTransformation(float **S,float gamma);
void ExtendedRange(float **H,float m);
int Min(int a,int b,int c);

void HistogramEqualization(float **I)//直方圖均衡化 I channel
{
	double *temp=new double [256];
	float *pdf=new float [256]; 
	float *cdf=new float [256];
	float cdf_min = 1000;
	
	for(int x=0;x<512;x++)
		for(int y=0;y<512;y++)
			temp[(int)I[x][y]]++;
	
	pdf[0] = temp[0] / (512*512);
	for(int i=1;i<256;i++)
	{
		pdf[i] = temp[i] / (512*512);
		cdf[i] = pdf[i] + cdf[i-1];
		if(cdf[i]<cdf_min && cdf[i]!=0)
			cdf_min=cdf[i];
	}
	for(int i=0;i<256;i++)
		temp[i]= ((cdf[i]-cdf_min)*(512*512) / ((512*512) - (cdf_min*(512*512)))*255);
	
	for(int x=0;x<512;x++)
		for(int y=0;y<512;y++)
			I[x][y] = temp[ (int)I[x][y]];
	
	delete []temp,pdf,cdf;
}
void GammaTransformation(float **S,float gamma)//S channel 
{
	for(int x=0;x<512;x++)
	{
		for(int y=0;y<512;y++)
		{
			S[x][y]=pow((double)S[x][y],gamma);
		}
	}
}
void ExtendedRange(float **H,float m)//H Channel 
{
	for(int x=0;x<512;x++)
	{
		for(int y=0;y<512;y++)
		{
			for(int i=0;i<255;i++)
			{
				H[x][y]=H[x][y]*m;
				break;
			}
		}
	}
}
int Min(int a,int b,int c){
	if(a-b<=0&&a-c<=0)
		return a;
	else if(b-a<=0&&b-c<=0)
		return b;
	else 
		return c;
}


unsigned char image[3][512][512] , image2[3][512][512];
#define PI 3.14159265358979323846
int main(int argc, char *argv[])
{
    int i,j,k,x,y,n;
    unsigned char ch,ch1;
    float R,G,B,value1,value2,m,gamma;
    double theta;
    //動態陣列 
    float **H=new float *[512];
    for(int i=0;i<512;i++)
    {
    	H[i]=new float[512];
	}
	
	float **S=new float *[512];
    for(int i=0;i<512;i++)
    {
    	S[i]=new float[512];
	}
    
    float **I=new float *[512];
    for(int i=0;i<512;i++)
    {
    	I[i]=new float[512];
	}
    
    fstream file1,file2;
    string ifile,ofile;
    cout<<" 請輸入讀取的檔名: "; 
    cin>>ifile;
    cout<<" 請輸入輸出的檔名: ";
    cin>>ofile; 

    file1.open(ifile.c_str(), ios_base::in | ios_base::binary);
    if(!file1)
       cout<<" file open fail!"<<endl;
    else
    {  
        for(k=0;k<3;k++)
            for(i=0;i<512;i++)
             	for(j=0;j<512;j++)
                {
					file1.read((char*) &ch, 1);
                    image[k][i][j]=ch; 
                }  
    }    
    file1.close(); 
    
    for(x=0;x<512;x++)
    {
    	for(y=0;y<512;y++)
    	{
    		//RGB To HSI
    		R=image[0][x][y];
    		G=image[1][x][y];
    		B=image[2][x][y];
    		
    		value1=0.5*( (R-G) + (R-B) );
    		value2=pow( pow(R-G,2) + (R-B)*(G-B) , 0.5);
    		
    		theta=acos(value1/value2);
    		theta=theta*(180/PI);
    		H[x][y] = (B>G) ? 360-theta : theta;
    		
    		S[x][y]=1 - (3/(R+G+B)) * Min(R,G,B);
    		
    		I[x][y]=(R+G+B)/3;
		}
	}
	cout<<"1.直方圖均化  2.gamma轉換  3.擴大值域  4.全部  5.exit"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
			HistogramEqualization(I);
			break;
		case 2:
			cout<<"請輸入gamma值"<<endl;
			cin>>gamma;
			GammaTransformation(S,gamma);
			break; 
		case 3:
			cout<<"請輸入擴大值"<<endl;
			cin>>m;
			ExtendedRange(H,m); 
			break;
		case 4:
			cout<<"請輸入gamma值"<<endl;
			cin>>gamma;
			cout<<"請輸入擴大值"<<endl;
			cin>>m;
			HistogramEqualization(I);
			GammaTransformation(S,gamma);
			ExtendedRange(H,m);
			break;
		case 5:
			return 0;
		default:
			return 0;
	}
			
	
				
	for(x=0;x<512;x++)
    {
    	for(y=0;y<512;y++)
    	{
    		//RGB To HSI
			if(H[x][y]<120 && H[x][y]>=0)
			{
				H[x][y]=H[x][y]*(PI/180);
				R = I[x][y] * ( 1 + (S[x][y]*cos(H[x][y]) / cos((PI/3)-H[x][y])) );
				B = I[x][y] * ( 1 - S[x][y]);
				G = 3 * I[x][y] - ( R + B );
				
				R=floor(R);
				G=floor(G);
				B=floor(B);
				R=min(R,255.0f);
				G=min(G,255.0f);
				B=min(B,255.0f);
				image2[0][x][y] = R;
    			image2[1][x][y] = G;
    			image2[2][x][y] = B;		
			}
			else if(H[x][y]>=120 && H[x][y]<240)
			{
				H[x][y]-=120;
				H[x][y]=H[x][y]*(PI/180);
				R = I[x][y] * ( 1 - S[x][y] );
				G = I[x][y] * ( 1 + ( S[x][y]*cos(H[x][y]) / cos((PI/3)-H[x][y])) );
				B = 3 * I[x][y] - ( R + G );
				
				R=floor(R);
				G=floor(G);
				B=floor(B);
				R=min(R,255.0f);
				G=min(G,255.0f);
				B=min(B,255.0f);
					
				image2[0][x][y] = R;
    			image2[1][x][y] = G;
    			image2[2][x][y] = B;	
			}
			else 
			{
				H[x][y]-=240;
				H[x][y]=H[x][y]*(PI/180);
				G = I[x][y] * ( 1 - S[x][y] );
				B = I[x][y] * ( 1 + S[x][y]*cos(H[x][y]) / cos((PI/3)-H[x][y]) );
				R = 3 * I[x][y] - ( G + B );
				
				R=floor(R);
				G=floor(G);
				B=floor(B);
				R=min(R,255.0f);
				G=min(G,255.0f);
				B=min(B,255.0f);
	
				image2[0][x][y] = R;
    			image2[1][x][y] = G;
    			image2[2][x][y] = B;	
			}
			
		}
	}		
	//釋放記憶體 
	for(int i=0;i<512;i++)
		delete []H[i];
	delete []H;
	
	for(int i=0;i<512;i++)
		delete []S[i];
	delete []S;
	for(int i=0;i<512;i++)
		delete []I[i];
	delete []I;
	
    file2.open(ofile.c_str(), ios_base::out | ios_base::binary);
    if(!file2)
       cout<<" file open fail!"<<endl;
    else
    {
    	for(k=0;k<3;k++)
        	for(i=0;i<512;i++)
            	for(j=0;j<512;j++)
                {
                	ch1=image2[k][i][j];
					file2.write((char*) &ch1, 1);    
                } 
	}
	file2.close();
    system("PAUSE");
    return 0;
}
