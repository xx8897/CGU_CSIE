#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime> // 為了 clock_t 和 CLK_TCK 設的;
#include <cmath>
using namespace std;

int main(){
    int n=10;
    int totalNum, num;
    int * array;
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    array = new int [n+1];
    for (int j = 0; j < n;j++){
        for (int i = 0; i < 10; i++){
            totalNum = 0;
            for (int j = 0; j < 5; j++){
                num = rand() % 10;
                totalNum += num * pow(10, j);
            }
        } //亂數產生器 totalnum為亂數
        array[j] = totalNum;
        cout << array[j]<<endl;
    }
    
}