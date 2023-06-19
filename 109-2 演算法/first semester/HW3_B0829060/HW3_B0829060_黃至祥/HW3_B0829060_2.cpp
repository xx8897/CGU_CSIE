#include <iostream>
using namespace std;

class SparseMatrix{
    private:
        int **data;
        int cols, rows, terms;

    public:
        SparseMatrix(int **i_data, int x, int y);
        void FastTranspose();
};

int main(){
    int x, y;
    cin >> x >> y;
    int **data = new int *[x];
    for (int i = 0; i < x;i++){
        data[i] = new int[y];
    }
    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            cin >> data[i][j];
        }
    }

    SparseMatrix m1(data,x,y);
    m1.FastTranspose();
}

SparseMatrix::SparseMatrix(int **i_data, int x, int y){
    data = new int* [x * y];
    for (int i = 0; i < x * y;i++){
        data[i] = new int[3];
    }

    rows = x;
    cols = y;
    terms = 0;
    //trsport normal array into <row,col,value> type.
    for (int i = 0; i < x;i++){
        for (int j = 0; j < y;j++){
            if(i_data[i][j]!=0){
                data[terms][0] = i;
                data[terms][1] = j;
                data[terms][2] = i_data[i][j];
                terms++;
            }
        }
    }
    cout << "Show in triple : " << endl;
    for (int i = 0; i < terms;i++){
        for (int j = 0; j < 3;j++){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void SparseMatrix::FastTranspose(){
    int *row_start = new int[rows];
    for (int i = 0; i < terms;i++){
        row_start[i] = 0; //initialize 0
    }
    //calculate row_start
    //cout << data[11][0] << endl;

    //fill row_size into row_start
    for (int i = 0; i < terms; i++){
        row_start[data[i][1]]++;
    }
    //start calculatin row_start
    int temp1 = row_start[0];
    row_start[0] = 0;
    for (int i = 1; i < cols;i++){
        int temp2 = row_start[i];
        row_start[i] = temp1 + row_start[i-1];
        temp1 = temp2;
    }

    // cout << "Finish Calculate Row_start" << endl;
    // for (int i = 0; i < rows;i++){
    //     cout << row_start[i];
    // }
    // cout << endl;

    int **temp_data = new int *[terms];
    for (int i = 0; i < terms;i++){
        temp_data[i] = new int[3];
    }
    //start transpose
    for (int i = 0; i < terms;i++){
        temp_data[row_start[data[i][1]]][2] = data[i][2];
        temp_data[row_start[data[i][1]]][0] = data[i][1];
        temp_data[row_start[data[i][1]]][1] = data[i][0];
        row_start[data[i][1]]++;
    }

    // cout << "Finish FastTranspose" << endl;
    // for (int i = 0; i < rows * terms;i++){
    //     delete[] data[i];
    // }
    data = temp_data;

    cout << "After transpose : " << endl;
    for (int i = 0; i < terms;i++){
        for (int j = 0; j < 3;j++){
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}