#pragma clang diagnostic ignored "-Winvalid-source-encoding"
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void bsort(string **array,int size,int word,int start1,int start2);
int main(){
	int x,y; 				// x���ռ�, y������ 
	string str,**array;		// �Ȧs�r��P�r�ꪺ�ʺA�}�C

	cout << "�A�Q��J�X�Ӧr��?"<<endl;
	cin >> x;
	array = new string* [x]; //�r��}�C
	for (int i=0 ; i<x ; i++){
		array[i] = new string() ; 
	}

	cout << "�@�Ӧr��̦h�h��?"<<endl; 
	cin >> y;
	cin.ignore();

	for (int i=0 ; i<x ; i++){
		cout << "�ж}�l��J�r��"<< i+1 << endl;
		getline(cin, str);
		if (str.size()>y){
			cout << "�W�L�]�w�����סA�Э��s��J!"<<endl; //�W�L�w�]������
			i--;
		}
		else{
			array[i][0] = str; //���\�s���r��
		}
	}

	bsort(array,x,0,0,0); //�i��bubble sort�i��bubble sort
	cout << "�L�X�Ƨǫ᪺���r��\n";
	for (int i=0 ; i<x ; i++){
		cout << "string"<<i+1 <<":"<<array[i][0] <<endl; 
	}
	for (int i=0 ; i<x ; i++){
        delete [] array[i];
    }
    delete [] array; //�Χ��U�h
} 

void bsort(string **array,int size,int word,int start1,int start2){ //bubble sort �Ƨ�
	string s;
	for (int i = start1; i < size - 1; i++){
		for (int j = start2; j < size - 1 - i; j++){
			if (int (array[j][0][word]) < int (array[j+1][0][word])){
				s = *array[j];
				*array[j]= array[j+1][0];
				*array[j+1] = s;	
			}
			else if (int (array[j][0][word]) == int (array[j+1][0][word])){
				bsort(array,size,word+1,i,j);
			}
		}
	}
}
