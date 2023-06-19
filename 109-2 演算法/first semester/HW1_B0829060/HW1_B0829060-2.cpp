#pragma clang diagnostic ignored "-Winvalid-source-encoding"
#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;
void bsort(string **array, int size, int word, int start1, int start2);
int main(){
	int x,y; 				//x是組數, y是長度 
	string str,**array;	    //暫存字串與字串的動態陣列

	cout << "你想輸入幾個字串?"<<endl;
	cin >> x;
	array = (string**)malloc(sizeof(string*)* x); //在array配置x格 以string為單位

	cout << "一個字串最多多長?"<<endl; 
	cin >> y;
	cin.ignore();
	
	for (int i=0 ; i<x ; i++){
		array[i] = new string() ;; //每格配置一個string
	}

	for (int i=0 ; i<x ; i++){
		cout << "輸入字串"<< i+1<<endl;
		getline(cin, str);
		if (str.size()>y){
			cout << "超過設定的長度，請重新輸入!"<<endl;  //超過預設的長度
			i--;
		}
		else{
			array[i][0] = str; //成功存取
		}
	}
	bsort(array,x,0,0,0); //進行排序
	cout << "印出排序後的的字串\n";
	for (int i=0 ; i<x ; i++){
		cout << "string"<<i+1 <<":"<<array[i][0] <<endl;
	}
	for (int i=0 ; i<x ; i++){
        free (array[i]);
    }
    free(array); //釋放空間
} 
void bsort(string **array,int size,int word,int start1,int  start2){ //bubble sort
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
