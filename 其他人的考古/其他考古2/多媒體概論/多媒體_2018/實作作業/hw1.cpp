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

    //�ŧi�ɮ��ܼ�
    string file,newfile;
    fstream in,out;

    char *array;
    string newarray;
    char* string[5];

    //��J�ҭn������
	cout<<"��J���Ϊ���"<<endl;
	cin>>N;
	a=N;
	
	//�ŧi���P����
    double *x,*DCT,*IDCT;
    x = new double [N];
    DCT = new double [N];
    IDCT = new double [N];


    //�����r��
	stringstream ss;
	ss<<a;


	//����ɦW
    file="Nello.wav";
    newfile = file;
    for(int i = 0; i < newfile.size(); i ++){
		if(newfile[i] == '.'){
            newfile.insert(i,"f");
			newfile.insert(i+1,ss.str());
			break;
		}
    }
  //1.Ū���ɮ�
    in.open(file.c_str(), ios::in | ios::binary);					//Ū���G�i���ɮ�
    out.open(newfile.c_str(), ios::out | ios::binary);				//c_str():�NString�����ഫ��C�y���Φ����r��`��

    //seekg�]�^�O���J���w��
    in.seekg(0, ios::end);				//���а򩳬��ɮ�end�A���Ჾ��0 (�Y���ɮת�end)
    len = in.tellg();					//��^�@��int���ƭȡA����ܡ����m���С����ثe��m�C
    in.seekg(0, ios::beg);
    array = new char [len];
    in.read(array, len);//�@��Ū1��block(�Y��1byte)�A��Ū�����׬�len���j�p
    
    //2.Ū��Nbytes�ɮר��ഫ���Ʀr
    for( int i=44 ; i<len-40 ; i+=N ){
         for(int num=0 ; num<N ; num++){
             x[num]=array[i+num];
             if(x[num]<0)
                 x[num] = x[num]+256;           //ASCII�S��������,�N�������ܬ��L����
             if(i==44)
                 cout<<"x["<<num<<"]"<<" "<<x[num]<<"\n";
         }

         //2.��DCT
         for(int k=0 ; k<N ; k++){
             if(k==0)
                 DCT[k]=sqrt(2)/(2*sqrt(N/2));
             else
                 DCT[k]=1/(sqrt(N/2));
             sum=0;
             for(int n=0 ; n<N ; n++){
                 sum = sum + cos( (2*n+1)*k*pi/(2*N) )*x[n];
             }
             //�i���o�i
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
         //3.��IDCT
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

         //4.�N���ܫ᪺����^�쥻���}�C
         for(int num=0 ; num<N; num++){
             IDCT[num] = floor(IDCT[num]+0.5);
             array[i+num]=IDCT[num];
             IDCT[num]=0;
         }
    }


    //5.�g�J�ɮ�
    for( int i=0 ; i<len ; i++ ){
		newarray += array[i];
	}
	out.write(newarray.c_str(), newarray.size());
    in.close();
    out.close();

    system("PAUSE");
    return EXIT_SUCCESS;
}

