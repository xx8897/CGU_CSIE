
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

unsigned char img[3][512][512] , img2[3][512][512];

//I
void HistogramEqualization(float **I){
	double *temp=new double [256];
	float *pdf=new float [256]; 
	float *cdf=new float [256];
	float cdf_min = 1000;
	
	for(int x=0;x<512;x++){
		for(int y=0;y<512;y++){ 
			temp[(int)I[x][y]]++;
		}	
	}
	 
	pdf[0]=temp[0]/(512*512);
	for(int i=1;i<256;i++){
		pdf[i]=temp[i]/(512*512);
		cdf[i]=pdf[i]+cdf[i-1];
		if(cdf[i]<cdf_min&&cdf[i]!=0)
			cdf_min=cdf[i];
	}
	for(int i=0;i<256;i++){ 
		temp[i]=((cdf[i]-cdf_min)*(512*512)/((512*512)-(cdf_min*(512*512)))*255);
	} 
	
	for(int x=0;x<512;x++){ 
		for(int y=0;y<512;y++){ 
			I[x][y]=temp[(int)I[x][y]];
		}
	} 
	delete []temp,pdf,cdf;
};

//S
void GammaTransformation(float **S,float gamma){
	for(int x=0;x<512;x++){
		for(int y=0;y<512;y++){
			S[x][y]=pow((double)S[x][y],gamma);
		}
	}
};

//H
void ExtendedRange(float **H,float m){
	for(int x=0;x<512;x++){
		for(int y=0;y<512;y++){
			for(int i=0;i<255;i++){
				H[x][y]=H[x][y]*m;
				break;
			}
		}
	}
};

void mosaic(int n){
    
    for(int x=0;x<512;x+=n){
        int r=0,g=0,b=0;
        for(int y=0;y<512;y+=n){
            for(int k=0;k<n;k++){
                for(int l=0;l<n;l++){
                    r+=img[0][x+k][y+l];
                    g+=img[1][x+k][y+l];
                    b+=img[2][x+k][y+l];
                }
            }
            r=r/256;
            g=g/256;
            b=b/256;
            for(int k=0;k<n;k++){
                for(int l=0;l<n;l++){
                    img2[0][x+k][y+l]=r;
                    img2[1][x+k][y+l]=g;
                    img2[2][x+k][y+l]=b;
                }
            }
        }
    }
    
}

void fliter(){
    
    for(int x=0;x<512;x++){
        int r=0,g=0,b=0;
        for(int y=0;y<512;y++){
            r=122*x/512;
            g=255*y/512;
            b=img[2][x][y];
            img2[0][x][y]=r;
            img2[1][x][y]=g;
            img2[2][x][y]=b;
        }
    }
}

int main(int argc, char *argv[]){
	float pi=3.14159265;
    unsigned char ch,ch1;
    float R,G,B,value1,value2,m,gamma;
    double theta;
    //dynamic array 
    float **H=new float *[512];
    for(int i=0;i<512;i++){
    	H[i]=new float[512];
	}
	
	float **S=new float *[512];
    for(int i=0;i<512;i++){
    	S[i]=new float[512];
	}
    
    float **I=new float *[512];
    for(int i=0;i<512;i++){
    	I[i]=new float[512];
	}
    
    fstream file1,file2;
    string inputFile,outputFile;
    cout<<"please input read file name:"; 
    cin>>inputFile;
    cout<<"please input output file name:";
    cin>>outputFile; 

    file1.open(inputFile.c_str(), ios_base::in | ios_base::binary);
    if(!file1){
       cout<<"Can not open this file!!!"<<endl;
	   return 0;	
	}
    else{  
        for(int k=0;k<3;k++)
            for(int i=0;i<512;i++){ 
             	for(int j=0;j<512;j++){
					file1.read((char*) &ch, 1);
                    img[k][i][j]=ch; 
                } 
			} 
    }    
    file1.close(); 
    
    for(int x=0;x<512;x++){
    	for(int y=0;y<512;y++){
    		//RGB To HSI
    		R=img[0][x][y];
    		G=img[1][x][y];
    		B=img[2][x][y];
    		//calculate min
    		int min=0;
			if(R-G<=0&&R-B<=0)
				min=R;
			else if(G-R<=0&&G-B<=0)
				min=G;
			else 
				min=B;    		
    		
    		value1=0.5*((R-G)+(R-B));
    		value2=pow(pow(R-G,2)+(R-B)*(G-B),0.5);
    		
    		theta=acos(value1/value2);
    		theta=theta*(180/pi);
    		H[x][y]=(B>G) ? 360-theta : theta;
    		S[x][y]=1-(3/(R+G+B))*min;
    		I[x][y]=(R+G+B)/3;
		}
	}
	cout<<"Please input 1 2 3 4 5 6:";
	int num;
	cin>>num;
	switch(num){
		case 1:
			HistogramEqualization(I);
			break;
		case 2:
			cout<<"please input gamma:";
			cin>>gamma;
			GammaTransformation(S,gamma);
			break; 
		case 3:
			cout<<"please input extend value:";
			cin>>m;
			ExtendedRange(H,m); 
			break;
		case 4:
			cout<<"Expand the range:";
			cin>>gamma;
			cout<<"please input extend value:";
			cin>>m;
			HistogramEqualization(I);
			GammaTransformation(S,gamma);
			ExtendedRange(H,m);
			break;
        case 5:
            mosaic(16);
            break;
        case 6:
            fliter();
            break;
		default:
			return 0;
	}
	
    if(num<5){
	//HSI to RGB
	for(int x=0;x<512;x++){
    	for(int y=0;y<512;y++){
			if(H[x][y]<120 && H[x][y]>=0){
				H[x][y]=H[x][y]*(pi/180);
				R=I[x][y]*(1+(S[x][y]*cos(H[x][y])/cos((pi/3)-H[x][y])));
				B=I[x][y]*(1-S[x][y]);
				G=3*I[x][y]-(R+B);
				
				R=floor(R),G=floor(G),B=floor(B);
				R=min(R,255.0f),G=min(G,255.0f),B=min(B,255.0f);
				img2[0][x][y]=R;
    			img2[1][x][y]=G;
    			img2[2][x][y]=B;		
			}
			else if(H[x][y]>=120 && H[x][y]<240){
				H[x][y]-=120;
				H[x][y]=H[x][y]*(pi/180);
				R=I[x][y]*(1-S[x][y] );
				G=I[x][y]*(1+(S[x][y]*cos(H[x][y])/cos((pi/3)-H[x][y])) );
				B=3*I[x][y]-(R+G);
				
				R=floor(R),G=floor(G),B=floor(B);
				R=min(R,255.0f),G=min(G,255.0f),B=min(B,255.0f);
					
				img2[0][x][y]=R;
    			img2[1][x][y]=G;
    			img2[2][x][y]=B;	
			}
			else {
				H[x][y]-=240;
				H[x][y]=H[x][y]*(pi/180);
				G=I[x][y]*(1-S[x][y]);
				B=I[x][y]*(1+S[x][y]*cos(H[x][y])/cos((pi/3)-H[x][y]) );
				R=3*I[x][y]-(G+B);
				
				R=floor(R),G=floor(G),B=floor(B);
				R=min(R,255.0f),G=min(G,255.0f),B=min(B,255.0f);
	
				img2[0][x][y]=R;
    			img2[1][x][y]=G;
    			img2[2][x][y]=B;	
			}	
		}
	}		
}
    
    file2.open(outputFile.c_str(), ios_base::out | ios_base::binary);
    if(!file2){
       cout<<"Can not open this file!!!"<<endl;
       return 0;
	}
    else{
    	for(int k=0;k<3;k++){
        	for(int i=0;i<512;i++){
            	for(int j=0;j<512;j++){
                	ch1=img2[k][i][j];
					file2.write((char*)&ch1,1);    
                } 
        	}
    	}
	}
	file2.close();
	
	for(int i=0;i<512;i++){
		delete []H[i];
		delete []S[i];
		delete []I[i];
	}
	delete []H;
	delete []S;
	delete []I;
}
