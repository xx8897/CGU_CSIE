#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime> // 為了 clock_t 和 CLK_TCK 設的;
#include <cmath>
using namespace std;

void Merge(int *initList, int *mergeList, const int l, const int m, const int n){
    int i1, i2, iResult;//i1,i2定义两个数组的位置
    for (i1 = l, i2 = m + 1, iResult = l; i1 <= m && i2 <= n; iResult++){
        if (initList[i1] <= initList[i2]){
            mergeList[iResult] = initList[i1];
            i1++;
        }
        else{
            mergeList[iResult] = initList[i2];
            i2++;
        }
    }
    copy(initList + i1, initList + m + 1, mergeList + iResult);
    copy(initList + i2, initList + n + 1, mergeList + iResult);
}
void MergePass(int *initList, int *resultList, const int n, const int s){
    int i;
    for (i = 1; i < n - 2 * s + 1; i += 2 * s)//s为数组的长度
        Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);
    if ((i + s - 1) < n)
        Merge(initList, resultList, i, i + s - 1, n);
    else
        copy(initList + i, initList + n + 1, resultList + i);
}
void MergeSort(int *a, const int n){
    int *tempList = new int[n + 1];
    for (int l = 1; l < n; l *=2){
        MergePass(a, tempList, n, l);
        l *=2;
        MergePass(tempList, a, n, l);
    }
    delete[] tempList;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b= temp;
}
void QuickSort(int *A, const int left, const int right){
    int pivot;
    int i, j;
    if(left < right){
        pivot = A[left];
        i = left;
        j = right+1;
        do{
            do{
                i++;
            } while (A[i] < pivot);
            do{
                j--;
            } while (pivot < A[j]);
            if(i<j) //直到i ,j兩軍交會
                swap(A[i], A[j]);
        } while (i < j);
        swap(A[left], A[j]);

        QuickSort(A, left, j-1);
        QuickSort(A, j+1, right);
    }
}
void Insert(const int &e, int *a, int i){
    a[0] = e;
    while(e<a[i]){
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = e;
}
void InsertionSort(int *a, const int n){
    for (int j = 2; j <= n;j++){
        int temp = a[j];
        Insert(temp, a, j - 1);
    }
}
void max_heapify(int *arr, int start, int end) {
    // 建立父節點指標和子節點指標
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { // 若子節點指標在範圍內才做比較
        if (son + 1 <= end && arr[son] < arr[son + 1]) // 先比較兩個子節點大小，選擇最大的
            son++;
        if (arr[dad] > arr[son]) // 如果父節點大於子節點代表調整完畢，直接跳出函數
            return;
        else { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void HeapSort(int *arr, int len) {
    // 初始化，i從最後一個父節點開始調整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 先將第一個元素和已经排好的元素前一位做交換，再從新調整(刚调整的元素之前的元素)，直到排序完畢
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}
int main(){
    clock_t start = 0, end = 0; // clock_t 型別是 CPU 的時間，是整數;
    float total_time = 0.0;
    int input = 0, n = 50;
    int * array;
    int totalNum, num;
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);


    n = 50;

    while(input!=5){
                cout << n << " ";
        while(n<100000){

        if (n < 500)
            n += 50;
        else if (n < 5000)
            n += 200;
        else if (n < 10000)
            n += 500;
        else if (n < 50000)
            n += 1000;
        else if (n < 100000)
            n += 2000;

        cout << n << " ";
    }
    n = 50;
    cout << "請輸入你想要的演算法" << endl;
    cout << "1.合併排序法 2.插入排序法 3.快速排序法 4.堆疊排序法 5.離開" << endl;
    cout << "你輸入的數字是：";
    cin >> input;
    if (input == 5)
    {
        cout << "你已離開";
        break;
        }
        //cout << "請輸入數據數量：";
        n = 50;



        switch(input){
            case 1:
                //cout << "before\n";
                while(n<=100000){
                array = new int [n+1];

                for (int j = 1; j < n + 1; j++){
                    for (int i = 0; i < 10; i++){
                        totalNum = 0;
                        for (int j = 0; j < 5; j++)
                        {
                            num = rand() % 10;
                            totalNum += num * pow(10, j);
                        }
                    } //亂數產生器 totalnum為亂數
                    totalNum = totalNum % 50000 + 1;
                    array[j] = totalNum;
                    //cout << array[j] << " ";
                }
                //cout << "合併排序法排序後" << endl;
                start = clock(); // clock_t clock(void)，會返回程式所使用的處理器時間之近似值;
                MergeSort(array,n);
                end = clock();
                total_time = ((float)(end - start)) / CLOCKS_PER_SEC ;
                cout << total_time << " ";
                if(n<500)
                    n+= 50;
                else if(n<=5000)
                    n += 200;
                else if(n<=10000)
                    n += 500;
                else if(n<=50000)
                    n += 1000;
                else if(n<=100000)
                    n += 2000;
            
                }
                break;
            case 2:
                //cout << "before\n";
                while(n<=100000){
                array = new int [n+1];

                for (int j = 1; j < n + 1; j++){
                    for (int i = 0; i < 10; i++){
                        totalNum = 0;
                        for (int j = 0; j < 5; j++)
                        {
                            num = rand() % 10;
                            totalNum += num * pow(10, j);
                        }
                    } //亂數產生器 totalnum為亂數
                    array[j] = totalNum;
                    //cout << array[j] << " ";
                }
                start = clock(); // clock_t clock(void)，會返回程式所使用的處理器時間之近似值;
                //cout << "插入排序法排序後" << endl;
                InsertionSort(array,n);
                end = clock();
                total_time = ((float)(end - start)) / CLOCKS_PER_SEC ;
                cout << total_time << " ";
                
                if(n<500)
                    n+= 50;
                else if(n<=5000)
                    n += 200;
                else if(n<=10000)
                    n += 500;
                else if(n<=50000)
                    n += 1000;
                else if(n<=100000)
                    n += 2000;
                }
                break;
            case 3:
                while(n<=100000){
                for (int i = 0;i<n+1;i++){
                    array[i] = 1;
                }
                //cout << "before\n";

                for (int j = 1; j < n + 1; j++){
                    for (int i = 0; i < 10; i++){
                        totalNum = 0;
                        for (int j = 0; j < 5; j++)
                        {
                            num = rand() % 10;
                            totalNum += num * pow(10, j);
                        }
                    } //亂數產生器 totalnum為亂數
                    array[j] = totalNum;
                    //cout << array[j] << " ";
                }
                //cout << "快速排序法排序後" << endl;
                start = clock(); // clock_t clock(void)，會返回程式所使用的處理器時間之近似值;
                QuickSort(array,2,n-1);
                end = clock();
                total_time = ((float)(end - start)) / CLOCKS_PER_SEC ;
                cout << total_time << " ";

                if(n<500)
                    n+= 50;
                else if(n<=5000)
                    n += 200;
                else if(n<=10000)
                    n += 500;
                else if(n<=50000)
                    n += 1000;
                else if(n<=100000)
                    n += 2000;
                }
                break;
            case 4:
                while(n<=100000){
                //cout << "before\n";
                array = new int [n+1];

                for (int j = 0; j < n ; j++){
                    for (int i = 0; i < 10; i++){
                        totalNum = 0;
                        for (int j = 0; j < 5; j++)
                        {
                            num = rand() % 10;
                            totalNum += num * pow(10, j);
                        }
                    } //亂數產生器 totalnum為亂數
                    array[j] = totalNum;
                    //cout << array[j] << " ";
                }
                //cout << "堆疊排序法排序後" << endl;
                start = clock(); // clock_t clock(void)，會返回程式所使用的處理器時間之近似值;
                HeapSort(array,n);
                end = clock();
                total_time = ((float)(end - start)) / CLOCKS_PER_SEC ;
                cout << total_time << " ";

                if(n<500)
                    n+= 50;
                else if(n<=5000)
                    n += 200;
                else if(n<=100000)
                    n += 500;
                else if(n<=50000)
                    n += 1000;
                else if(n<=100000)
                    n += 2000;
                }
                break;
            default:
                cout << "輸入為不合法的指令" << endl;
        }

        cout << endl;


        //total_time = ((float)(end - start)) / CLOCKS_PER_SEC ; // 返回值是 clock_t 型別的 CPU 時間，因為 CPU 的時間為整數，所以要強制轉型成 float，再除以 CLOCKS_PER_SEC 可得到秒值;
        //cout << "n = " << n << " 的 total_time = " << total_time << " 秒" << endl;

    }
}