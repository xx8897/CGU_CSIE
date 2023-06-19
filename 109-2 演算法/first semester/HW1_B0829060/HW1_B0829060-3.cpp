#pragma clang diagnostic ignored "-Winvalid-source-encoding"
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
void sort(string **array,int size,int para,int start1,int start2);
int main(){
	int x; //x為字串
	int length1 = 0, maxLength = 0; //length為空白前長度,maxLength為最大長度
	bool space1 = false; //有沒有第一個空白
	string str,**array;		// 暫存字串與字串的動態陣列

	cout << "你想輸入幾組英文姓名?"<<endl;
	cin >> x;
	cin.ignore();
	array = new string* [x]; //字串陣列
	for (int i=0 ; i<x ; i++){
		array[i] = new string() ; 
	}
	int length2[x]; // 存每個名子空白前的長度


	for (int i=0 ; i<x ; i++){
		cout << "請開始輸入字串"<< i+1 << endl;
		getline(cin,str);
		array[i][0] = str; //成功存取字串


		int j = 0; //數數字
		while(j<str.length()&& (space1==false)){
			if(str.at(j)==' '){
				space1 = true; //偵測到空白
				length1 = j;
				cout << "length="<<length1 << endl;
			}
			if(length1>maxLength){
				maxLength = length1;
			}
			if(space1){
				length2[i] = j; // 存length進length的陣列
			}
			if(!space1){
				length2[i] = str.length(); //沒有空白的存取情況
			}
			j++;
		}
		length1 = 0;
		space1 = false;
	}
	cout << "maxLength=" << maxLength << endl;

	sort(array,x,0,0,0);
	cout << "印出排序後的的字串\n";
	for (int i=0 ; i<x ; i++){
		for (int j = 0; j < maxLength - length2[i];j++){
			cout << " ";
		} //加空白
		cout << array[i][0] << endl; 
	}
	for (int i=0 ; i<x ; i++){
        delete [] array[i];
    }
    delete [] array; //用完釋放空間
} 

void sort(string **array,int size,int word,int start1,int start2){ //bubble sort 排序
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
