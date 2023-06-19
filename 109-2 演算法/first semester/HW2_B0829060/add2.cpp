#include <iostream>
#include <ctime>
using namespace std;

void matrix_multiplication(int **a, int **b, int **c, int m, int n, int p){ // 課本題目要求;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            c[i][j] = 0;
            for (int k = 0; k < n;k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(){
    clock_t start = 0, end = 0;
    int m = 0, p = 0;
    float total_time = 0.0;

    for (int n = 100; n <= 3000; n+= 100){
        m = n;
        p = m;
        int **a = new int *[n], **b = new int *[n], **c = new int *[n];
        for (int l = 0; l < n; l++){
            a[l] = new int[p];
            b[l] = new int[p];
            c[l] = new int[p];
        }

        start = clock();
        matrix_multiplication(a, b, c, m, n, p);
        end = clock();

        total_time = ((float)(end - start)) /CLOCKS_PER_SEC;
        cout << "n = " << n << " 的 total_time = " <<  total_time << " 秒" << endl;
    }
}