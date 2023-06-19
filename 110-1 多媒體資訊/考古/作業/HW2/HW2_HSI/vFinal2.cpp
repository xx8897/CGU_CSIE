#include<iostream>
#include<windows.h>
#include<cmath>
#define Height 512
#define Width 512
using namespace std;
float Gamma = 0.75 ;
int HisEqual =  2 ; //v1.0 or v2.0
//linker -Wl,--stack,7777777
float cosA(float angle)
{
	return cos(angle*(2*M_PI)/360.0) ;
}
int acosA(float x)
{
	return acos(x)*360.0/(2*M_PI) ;
}
int main(int argc, char *argv[])
{
	char FileName[MAX_PATH] ;
	if (argc!=1)
	{
		size_t len = strlen(argv[1]);
		memcpy( FileName, argv[1], len );
	}
	else 
	{	
		INIT:
		cout<<"FileName: "; 
		cin>> FileName ;
	}
	unsigned char RRR[Height][Width];
	unsigned char GGG[Height][Width];
	unsigned char BBB[Height][Width];
	FILE *getFile = fopen(FileName ,"rb") ;
	{
	
		if (getFile == 0) 
		{
			cout<<"Can not open file: " << FileName <<endl;
			goto INIT ;
		}
		else cout<<"Open File: "<< FileName <<endl;
		
		for ( int i = 0 ; i < Height ; i++ )
			for ( int j = 0 ; j < Width ; j++ )
				RRR[i][j] = fgetc(getFile);
	
		for ( int i = 0 ; i < Height ; i++ )
			for ( int j = 0 ; j < Width ; j++ )
				GGG[i][j] = fgetc(getFile);
			
		for ( int i = 0 ; i < Height ; i++ )
			for ( int j = 0 ; j < Width ; j++ )
				BBB[i][j] = fgetc(getFile);
	}
	/*------------*/
	int R,G,B ;
	short HHH[Height][Width] ;//0~360
	unsigned char SSS[Height][Width] ;//0~255
	unsigned char III[Height][Width] ;//0~255
	short mini, sum, theta;
	float Upp, Downn,temp;
	short H;
	float S,I ;
	cout<< "Convert to HSI ..." <<endl;	
	for ( int i = 0 ; i < Height ; i++ )
	{
		for ( int j = 0 ; j < Width ; j++ )		
		{
			sum = RRR[i][j] + GGG[i][j] + BBB[i][j] ;
			mini = min( min(RRR[i][j] , GGG[i][j]) , BBB[i][j] ) ;
			Upp = 0.5*(RRR[i][j] - GGG[i][j] + RRR[i][j] - BBB[i][j]) ;
			Downn = ((RRR[i][j] - GGG[i][j]) * (RRR[i][j] - GGG[i][j])) 
				  + ((RRR[i][j] - BBB[i][j]) * (GGG[i][j] - BBB[i][j])) ;
			if(Downn <= 0) temp = 0 ; 
			else temp = Upp / sqrt(Downn)  ;
			
			if (BBB[i][j] <= GGG[i][j])
				HHH[i][j] = acosA(temp) ;
			else if (BBB[i][j] > GGG[i][j])
				HHH[i][j] = 360 - acosA(temp) ;
			
			if (sum == 0 )
				SSS[i][j] = 0 ;
			else	
				SSS[i][j] = 255 - 255 * (3*mini) / sum ;
				
			III[i][j] = sum / 3 ; 
		}
	}	
	/*------------*/
	if (HisEqual == 1)
	{
		cout<< "Histogram Equalization ..." <<endl;
		int equal[256] = {0};
		for ( int i = 0 ; i < Height ; i++ )
			for ( int j = 0 ; j < Width ; j++ )		
				for ( int t = III[i][j] ; t < 256 ; t++ )
					equal[t] ++ ;	
		for ( int i = 0 ; i < Height ; i++ )
		{
			for ( int j = 0 ; j < Width ; j++ )		
			{
				unsigned char t = III[i][j] ;	
				t = 255.0*equal[t]/Height/Width;
				III[i][j] = t ;
			}
		}
	}
	/*------------*/
	cout<< "Gamma Transformation ..." <<endl;
	for ( int i = 0 ; i < Height ; i++ )
	{
		for ( int j = 0 ; j < Width ; j++ )		
		{
			SSS[i][j] = 255 * pow(SSS[i][j], Gamma) / pow(255.0 , Gamma);
			//III[i][j] = 0;
		}
	}
	/*------------*/
	cout<< "Convert to RGB ..." <<endl;	
	for ( int i = 0 ; i < Height ; i++ )
	{
		for ( int j = 0 ; j < Width ; j++ )		
		{
			H = HHH[i][j] ;
			S = SSS[i][j] ;
			I = III[i][j] ;
			if ( (0 <= H) && (H < 120) )
			{
				R = I * ( 255 + (S * cosA(H) / cosA(60-H)) ) / 255 ;
				B = I * (255 - S) / 255 ;
				G = 3*I - R - B ;
			}
			else if ( (120 <= H) && (H < 240) )
			{
				H = H - 120 ;
				R = I * (255 - S) / 255 ;
				G = I * ( 255 + (S * cosA(H) / cosA(60-H)) ) / 255 ;
				B = 3*I - R - G ;
			}
			else if ( (240 <= H) && (H <= 360) )
			{
				H = H - 240 ;
				G = I * (255 - S) / 255 ;
				B = I * ( 255 + (S * cosA(H) / cosA(60-H)) ) / 255 ;
				R = 3*I - G - B ;
			}			
			RRR[i][j] = min(255,R) ;
			GGG[i][j] = min(255,G) ;
			BBB[i][j] = min(255,B) ;
		}	
	}	
	/*------------*/
	if (HisEqual == 2)
	{
		cout<< "Histogram Equalization v2.0 ..." <<endl;
		int equalR[256] = {0};
		int equalG[256] = {0};
		int equalB[256] = {0};
		for ( int i = 0 ; i < Height ; i++ )
		{
			for ( int j = 0 ; j < Width ; j++ )		
			{
				for ( int t = RRR[i][j] ; t < 256 ; t++ )
					equalR[t] ++ ;	
				for ( int t = GGG[i][j] ; t < 256 ; t++ )
					equalG[t] ++ ;	
				for ( int t = BBB[i][j] ; t < 256 ; t++ )
					equalB[t] ++ ;	
			}
		}
		for ( int i = 0 ; i < Height ; i++ )
		{
			for ( int j = 0 ; j < Width ; j++ )		
			{
				RRR[i][j] = 255.0*equalR[ RRR[i][j] ]/Height/Width;
				GGG[i][j] = 255.0*equalG[ GGG[i][j] ]/Height/Width;
				BBB[i][j] = 255.0*equalB[ BBB[i][j] ]/Height/Width;
			}
		}
	}
	/*------------*/
	cout<< "Save to File ..." <<endl;
	FILE *putFile = fopen("out.raw","wb") ;
	{
		for ( int i = 0 ; i < Height ; i++ )
			for ( int j = 0 ; j < Width ; j++ )		
				fputc(RRR[i][j],putFile);
		
		for ( int i = 0 ; i < Height ; i++ )
			for ( int j = 0 ; j < Width ; j++ )		
				fputc(GGG[i][j],putFile);
		
		for ( int i = 0 ; i < Height ; i++ )
			for ( int j = 0 ; j < Width ; j++ )		
				fputc(BBB[i][j],putFile);
	}
	/*------------*/
	system("pause") ;
	return 0; 
} 
/*
http://monkeycoding.com/?p=919
https://openhome.cc/Gossip/CGossip/Datatype.html
https://msdn.microsoft.com/zh-tw/library/e9s326kw.aspx
http://ip119.pixnet.net/blog/post/15621049-%E4%BB%A5-exact-hsi-%E8%89%B2%E5%BD%A9%E6%A8%A1%E5%9E%8B%E5%81%9A%E5%BD%A9%E8%89%B2%E5%BD%B1%E5%83%8F%E5%BC%B7%E5%8C%96
https://msdn.microsoft.com/zh-tw/library/4hwaceh6.aspx
linker ¤j¤p
fputc fputs
 R=G=B >> theta bang
http://lbt95.pixnet.net/blog/post/33699758-%5Bc%23%5D-rgb%E3%80%81hsi%E8%89%B2%E5%BD%A9%E7%A9%BA%E9%96%93%E4%BA%92%E8%BD%89%E8%A6%81%E6%B3%A8%E6%84%8F%E7%9A%84%E5%9C%B0%E6%96%B9
255*(1-A) != 255-255*A 
*/
