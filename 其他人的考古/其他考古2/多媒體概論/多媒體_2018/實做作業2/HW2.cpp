#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>

using namespace std;

float width=886.81; 
float height=886.81;

void read_RAW(unsigned char* RRAW, unsigned char* GRAW, unsigned char* BRAW) 
{ 
	double r, g, b, H, S, I, Min=999, I_save[256]={0};
	int i=0, j, k, save1, save2, save3, save4, I_count[256]={0}, I_accumulation[256]={0};
	
	unsigned char SAVE[256]; 
	float f=0;
	
/*	for( i=0;i<256;i++)  					//S channel 的加強
    {  										//
        f=(i+0.5)/256;                      //
        f=(float)pow(f,0.5);                //
        SAVE[i]=(f*256-0.5);                //
    }  */ 
	i=0;
	char fname[20], ch;                 //    開啟要寫的檔 
	cout << "file name ??" <<endl;      // 
	cin >> fname;                       // 
	ifstream inputf;                    // 
	inputf.open( fname,ios::binary );   // 
	if( !inputf.is_open() )             // 
		cout << "can't open!!" <<endl;  // 
	
	char ffname[20]; 
	cout << "the name of output file" <<endl; 
	cin >> ffname; 
	ofstream outputf; 
	outputf.open( ffname,ios::binary ); 
	 
	RRAW = new unsigned char[ (int)(width * height) ];
	GRAW = new unsigned char[ (int)(width * height) ];
	BRAW = new unsigned char[ (int)(width * height) ];  
	while( inputf.get(ch) )
	{
		if( i < 262144 )
		{
			RRAW[i]=ch;
		}
			
		if( i > 262144 &&  i< 524288 )
		{
			if( i==262145 )
			{
				save1=i;//記錄初值
				save3=i; 
			}	
			GRAW[i]=ch;
		}
		if( i > 524288 )
		{
			if( i==524289 )
			{
				save2=i;//記錄初值
				save4=i; 
			} 
			BRAW[i]=ch;
		}
		i++;
	}
	
	for(i=0;i<262144;i++ && save1++ && save2++) 
	{
		r=RRAW[i];
		g=GRAW[save1];
		b=BRAW[save2];
	
/*RGB2HSI*/
/**/	I = (r + g + b) / 3.0;     
/**/
/**/	double rn = r / (r + g + b);
/**/	double gn = g / (r + g + b);
/**/	double bn = b / (r + g + b);
/**/
/**/	H = acos((0.5 * ((rn - gn) + (rn - bn))) / (sqrt((rn - gn) * (rn - gn) + (rn - bn) * (gn - bn))));
/**/	if(b > g)
/**/	{
/**/		H = 2 * M_PI - H;	
/**/	}
/**/
/**/	S = 1 - 3 * min(rn, min(gn, bn));
/*RGB2HSI*/

		I_save[(int)I] = I;
		I_count[(int)I]++;
	}
	
	for(j=255;j>=0;j--)
	{
		if(I_count[j]!=0)
		{
			for(k=j;k>=0;k--)
			{
				if(I_count[k] != 0)
					I_accumulation[j] = I_accumulation[j] + I_count[k];
			}
		}
		if(I_accumulation[j] != 0 && I_accumulation[j] < Min)
			Min = I_accumulation[j];			
	}
		
	for(i=0;i<262144;i++ && save3++ && save4++) 
	{
		r=RRAW[i];
		g=GRAW[save3];
		b=BRAW[save4];

		I = (r + g + b) / 3.0;
		I = round((I_accumulation[(int)I]-Min)/(512*512-Min)*255);     //I channel 的加強
	
		double rn = r / (r + g + b);
		double gn = g / (r + g + b);
		double bn = b / (r + g + b);
	
		H = acos((0.5 * ((rn - gn) + (rn - bn))) / (sqrt((rn - gn) * (rn - gn) + (rn - bn) * (gn - bn))));
		if(b > g)
		{
			H = 2 * M_PI - H;	
		}
	
		S = 1 - 3 * min(rn, min(gn, bn));
		
/*HSI2RGB*/		
/**/	double x = I * (1 - S);		
/**/	if(H < 2 * M_PI / 3)
/**/	{
/**/		double y = I * (1 + (S * cos(H)) / (cos(M_PI / 3 - H)));
/**/		double z = 3 * I - (x + y);
/**/		b = x; r = y; g = z;
/**/	}
/**/	else if(H < 4 * M_PI / 3)
/**/	{
/**/		double y = I * (1 + (S * cos(H - 2 * M_PI / 3)) / (cos(M_PI / 3 - (H  - 2 * M_PI / 3))));
/**/		double z = 3 * I - (x + y);
/**/		r = x; g = y; b = z;
/**/	}
/**/	else
/**/	{
/**/		double y = I * (1 + (S * cos(H - 4 * M_PI / 3)) / (cos(M_PI / 3 - (H  - 4 * M_PI / 3))));
/**/		double z = 3 * I - (x + y);
/**/		r = z; g = x; b = y;
/**/	}
/*HSI2RGB*/	
		RRAW[i]=r;			if(r > 255){RRAW[i]=255;r=255;} 
		GRAW[save3]=g;		if(g > 255){GRAW[save3]=255;g=255;} 
		BRAW[save4]=b;		if(b > 255){BRAW[save4]=255;b=255;} 
		
		//RRAW[i]=SAVE[RRAW[i]];		//S channel 的加強
		//GRAW[i]=SAVE[GRAW[i]];		//S channel 的加強
		//BRAW[i]=SAVE[BRAW[i]];		//S channel 的加強
		
		RRAW[save3]=GRAW[save3];
		RRAW[save4]=BRAW[save4];

	}

	outputf.write((char*) RRAW, (int)(width * height) * sizeof(char));
	inputf.close();
	outputf.close();
	delete[] RRAW;
	delete[] GRAW;
	delete[] BRAW;
} 

int main () 
{ 
	unsigned char *Rlum; 
	unsigned char *Glum;
	unsigned char *Blum;
	
	int i=0;
	read_RAW(Rlum,Glum,Blum) ;

	system("pause");
	return 0;
} 
