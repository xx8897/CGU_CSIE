#pragma clang diagnostic ignored "-Winvalid-source-encoding"
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void sort(string **array,int size,int para,int start1,int start2);
int main(){
	int x; //x���r��
	int length1 = 0, maxLength = 0; //length���ťիe����,maxLength���̤j����
	bool space1 = false; //���S���Ĥ@�Ӫť�
	string str,**array;		// �Ȧs�r��P�r�ꪺ�ʺA�}�C

	cout << "�A�Q��J�X�խ^��m�W?"<<endl;
	cin >> x;
	cin.ignore();
	array = new string* [x]; //�r��}�C
	for (int i=0 ; i<x ; i++){
		array[i] = new string() ; 
	}
	int length2[x]; // �s�C�ӦW�l�ťիe������


	for (int i=0 ; i<x ; i++){
		cout << "�ж}�l��J�r��"<< i+1 << endl;
		getline(cin,str);
		array[i][0] = str; //���\�s���r��


		int j = 0; //�ƼƦr
		while(j<str.length()&& (space1==false)){
			if(str.at(j)==' '){
				space1 = true; //������ť�
				length1 = j;
				cout << "length="<<length1 << endl;
			}
			if(length1>maxLength){
				maxLength = length1;
			}
			if(space1){
				length2[i] = j; // �slength�ilength���}�C
			}
			if(!space1){
				length2[i] = str.length(); //�S���ťժ��s�����p
			}
			j++;
		}
		length1 = 0;
		space1 = false;
	}
	cout << "maxLength=" << maxLength << endl;

	sort(array,x,0,0,0);
	cout << "�L�X�Ƨǫ᪺���r��\n";
	for (int i=0 ; i<x ; i++){
		for (int j = 0; j < maxLength - length2[i];j++){
			cout << " ";
		} //�[�ť�
		cout << array[i][0] << endl; 
	}
	for (int i=0 ; i<x ; i++){
        delete [] array[i];
    }
    delete [] array; //�Χ�����Ŷ�
} 

void sort(string **array,int size,int word,int start1,int start2){ //bubble sort �Ƨ�
	string s;
	for (int i = start1; i < size - 1; i++){
		for (int j = start2; j < size - 1 - i; j++){
			if (int (array[j][0][word]) < int (array[j+1][0][word])){
				s = *array[j];
				*array[j]= array[j+1][0];
				*array[j+1] = s;	
			}
			else if (int (array[j][0][word]) == int (array[j+1][0][word])){
				sort(array,size,word+1,i,j);
			}
		}
	}
}
