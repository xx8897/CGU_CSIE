#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

class RAW 
{ 
		float width=886.81; 
		float height=886.81;
	public: 
		unsigned char* Rlum; 
		unsigned char* Glum;
		unsigned char* Blum;
		double R;
		double G;
		double B;
		double H;
		double S;
		double I;
		void read_RAW(); 
		void show_RAW(); 
}; 

void RAW::read_RAW() 
{ 
	int i=0,j,k;
	char fname[20],ch; 
	cout << "file name ??\n"; 
	cin >> fname; 
	ifstream inputf; 
	inputf.open(fname,ios::binary); 
	if(!inputf.is_open()) 
		cout <<"can't open!!\n"; 
/*	cout << "RAW width = "; 
	cin >> width; 
	cout << "RAW height = "; 
	cin >> height; */
	
	char ffname[20]; 
	cout <<"the name of output file"; 
	cin >> ffname; 
	ofstream outputf; 
	outputf.open(ffname,ios::binary); 
	 
	Rlum = new unsigned char[(int)(width * height)];
	Glum = new unsigned char[(int)(width * height)];
	Blum = new unsigned char[(int)(width * height)];  
	while(inputf.get(ch))
	{
		if( i < 262144 )
		{
			Rlum[i]=ch;
			//R[i]=Rlum[i];
		}
			
		if( i > 262144 &&  i< 524288 )
		{
			if(i==262145)
				j=i;//記錄出值 
			Glum[i]=ch;
			//G[i]=Glum[i];
		}
		if( i > 524288 )
		{
			if(i==524289)
				k=i;//記錄出值 
			Blum[i]=ch;
			//B[i]=Blum[i];
		}
		i++;
	}
	
	//outputf.write((char*) Rlum, (int)(width * height) * sizeof(char)); 
	//outputf.write((char*) Glum, (int)(width * height) * sizeof(char));
	//outputf.write((char*) Blum, (int)(width * height) * sizeof(char));
	
	inputf.close();
	outputf.close();
} 
/*
void RAW::show_RAW() 
{ 
	char fname[20]; 
	cout <<"the name of output file"; 
	cin >> fname; 
	ofstream outputf; 
	outputf.open(fname,ios::binary); 
	outputf.write((char*) lum, (int)(width * height) * sizeof(char)); 
	outputf.close();  
} 	
*/

inline void RGB2HSI(double r, double g, double b, double* h, double* s, double* i)
{
   	*i = (r + g + b) / 3.0;

	double rn = r / (r + g + b);
	double gn = g / (r + g + b);
	double bn = b / (r + g + b);

	*h = acos((0.5 * ((rn - gn) + (rn - bn))) / (sqrt((rn - gn) * (rn - gn) + (rn - bn) * (gn - bn))));
	if(b > g)
	{
		*h = 2 * M_PI - *h;	
	}

	*s = 1 - 3 * min(rn, min(gn, bn));
}

void AA(int* a)
{
	*a=2;
	//return a;
	/*int A;
	A=5;
	AA(&A);
	cout<<A;*/
}
int main () 
{ 
	RAW p1; 
	//p1.read_RAW(); 
	//此時p1是你從.raw檔中讀出的資料 你可以對它們做處理 
	//p1.show_RAW(); 
	
	//p1.R = p1.Rlum[0];
	int i=0;
	double b;
	//b=p1.Rlum[0];
	//for(i=0;i<25;i++)
	//RGB2HSI(p1.R, p1.G, p1.B, p1.H, p1.S, p1.I);
	//cout<<p1.R;
	
	
	
	
	
} 
