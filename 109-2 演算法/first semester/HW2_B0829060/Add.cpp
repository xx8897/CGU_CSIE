#pragma clang diagnostic ignored "-Winvalid-source-encoding"
#include <iostream>
#include <ctime> // ���F clock_t �M CLK_TCK �]��;
using namespace std;

void add(int **a, int **b, int **c, int m, int n){ // �ҥ��D�حn�D;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

int main(){
    clock_t start = 0, end = 0; // clock_t ���O�O CPU ���ɶ��A�O���;
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

        start = clock(); // clock_t clock(void)�A�|��^�{���ҨϥΪ��B�z���ɶ��������;
        add(a, b, c, m, n);
        end = clock();

        total_time = ((float)(end - start)) / CLOCKS_PER_SEC; // ��^�ȬO clock_t ���O�� CPU �ɶ��A�]�� CPU ���ɶ�����ơA�ҥH�n�j���૬�� float�A�A���H CLOCKS_PER_SEC �i�o����;
        cout << "n = " << n << " �� total_time = " <<  total_time << " ��" << endl;
    }
}