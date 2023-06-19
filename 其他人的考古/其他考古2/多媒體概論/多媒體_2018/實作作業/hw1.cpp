#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <conio.h>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    int len;
	int N;
	int a;


	
    double sum=0,pi=3.1415;

    //宣告檔案變數
    string file,newfile;
    fstream in,out;

    char *array;
    string newarray;
    char* string[5];

    //輸入所要的長度
	cout<<"輸入切割長度"<<endl;
	cin>>N;
	a=N;
	
	//宣告不同指標
    double *x,*DCT,*IDCT;
    x = new double [N];
    DCT = new double [N];
    IDCT = new double [N];


    //整數轉字串
	stringstream ss;
	ss<<a;


	//更改檔名
    file="Nello.wav";
    newfile = file;
    for(int i = 0; i < newfile.size(); i ++){
		if(newfile[i] == '.'){
            newfile.insert(i,"f");
			newfile.insert(i+1,ss.str());
			break;
		}
    }
  //1.讀取檔案
    in.open(file.c_str(), ios::in | ios::binary);					//讀取二進位檔案
    out.open(newfile.c_str(), ios::out | ios::binary);				//c_str():將String物件轉換成C語言形式的字串常數

    //seekg（）是對輸入文件定位
    in.seekg(0, ios::end);				//指標基底為檔案end再往後移動0 (即為檔案的end)
    len = in.tellg();					//返回一個int型數值，它表示“內置指標”的目前位置。
    in.seekg(0, ios::beg);
    array = new char [len];
    in.read(array, len);//一次讀1個block(即為1byte)，並讀取長度為len的大小
    
    //2.讀取Nbytes檔案並轉換為數字
    for( int i=44 ; i<len-40 ; i+=N ){
         for(int num=0 ; num<N ; num++){
             x[num]=array[i+num];
             if(x[num]<0)
                 x[num] = x[num]+256;           //ASCII沒有有號數,將有號數變為無號數
             if(i==44)
                 cout<<"x["<<num<<"]"<<" "<<x[num]<<"\n";
         }

         //2.做DCT
         for(int k=0 ; k<N ; k++){
             if(k==0)
                 DCT[k]=sqrt(2)/(2*sqrt(N/2));
             else
                 DCT[k]=1/(sqrt(N/2));
             sum=0;
             for(int n=0 ; n<N ; n++){
                 sum = sum + cos( (2*n+1)*k*pi/(2*N) )*x[n];
             }
             //進行濾波
           // DCT[k] = DCT[k]*sum*pow(0.98,pow( (k-N/2)/(sqrt(N)/2),2 )); 
            DCT[k] = DCT[k]*sum*pow(0.98,k); 
            //DCT[k] = DCT[k]*sum*pow(0.98,N-1-k); 
            
            
			
			
			//if(k<=0.5*N)
             //	DCT[k] = DCT[k]*sum*1; 
          //  else
        	//	DCT[k] = DCT[k]*sum*0; 
             
           
             if(i==44)
                 cout<<"DCT["<<k<<"] "<<DCT[k]<<endl;
         }
         //3.做IDCT
         for(int n=0 ; n<N ; n++){
             for(int k=0 ; k<N ; k++){
                 if(k==0)
                     IDCT[n] = IDCT[n] + ( sqrt(2)/(2*sqrt(N/2)) ) * cos( (2*n+1)*k*pi/(2*N) )*DCT[k];
                 else
                     IDCT[n] = IDCT[n] + 1/(sqrt(N/2)) * cos( (2*n+1)*k*pi/(2*N) )*DCT[k];
             }
             if(i==44)
                 cout<<"IDCT["<<n<<"] "<<floor(IDCT[n]+0.5)<<endl;
         }

         //4.將改變後的直放回原本的陣列
         for(int num=0 ; num<N; num++){
             IDCT[num] = floor(IDCT[num]+0.5);
             array[i+num]=IDCT[num];
             IDCT[num]=0;
         }
    }


    //5.寫入檔案
    for( int i=0 ; i<len ; i++ ){
		newarray += array[i];
	}
	out.write(newarray.c_str(), newarray.size());
    in.close();
    out.close();

    system("PAUSE");
    return EXIT_SUCCESS;
}

