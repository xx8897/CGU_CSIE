#pragma clang diagnostic ignored "-Winvalid-source-encoding"
#include <iostream>
#include <ctime> // 為了 clock_t 和 CLK_TCK 設的;
using namespace std;

void add(int **a, int **b, int **c, int m, int n){ // 課本題目要求;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main(){
    clock_t start = 0, end = 0; // clock_t 型別是 CPU 的時間，是整數;
    int m = 0;
    float total_time = 0.0;

    for (int n = 100; n <= 3000; n += 100){
        m = n;
        int **a = new int *[n], **b = new int *[n], **c = new int *[n];
        for (int k = 0; k < n; k++){
            a[k] = new int[m];
            b[k] = new int[m];
            c[k] = new int[m];
        }

        start = clock(); // clock_t clock(void)，會返回程式所使用的處理器時間之近似值;
        add(a, b, c, m, n);
        end = clock();

        total_time = ((float)(end - start)) / CLOCKS_PER_SEC; // 返回值是 clock_t 型別的 CPU 時間，因為 CPU 的時間為整數，所以要強制轉型成 float，再除以 CLOCKS_PER_SEC 可得到秒值;
        cout << "n = " << n << " 的 total_time = " <<  total_time << " 秒" << endl;
    }
}