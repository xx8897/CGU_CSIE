#pragma clang diagnostic ignored "-Winvalid-source-encoding"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class SparseMatrix;

class MatrixTerm{
    friend class SparseMatrix;
    public:
        void Read(){
            cout << "請輸入Matrix的三個內容"<<endl;
            cin >> row ;
            cin.ignore();
            cin >> col;
            cin.ignore();
            cin>>value;
            cin.ignore();
            cout << "輸入完成" << endl;
        }

    private:
        int row=0;
        int col=0;
        int value = 0;
};
class SparseMatrix{
    friend class MatrixTerm;

public:
    SparseMatrix(int r, int c, int t){
        rows = r;
        cols = c;
        terms = t;
        MatrixTerm *A[t];
        A[t] = new MatrixTerm[t]();

        smArray = A[t];
    }

    void Read(){
        for (int i = 0; i < terms; i++){
            smArray[i].Read();
        }
    }

    void Print(){

        cout << "              列    行    值" <<endl;
        cout << "smArray[0]";
        cout <<"    " <<smArray[0].row << "     " << smArray[0].col << "     " << smArray[0].value << endl;

        for (int i = 1; i < terms;i++){
            cout << "       [" << i << "]";
            cout << "    "<< smArray[i].row << "     " << smArray[i].col << "     " << smArray[i].value << endl;
        }
    }

    SparseMatrix Transpose();

    SparseMatrix Add(SparseMatrix b);

    SparseMatrix Multiply(SparseMatrix b);

    SparseMatrix FastTranspose()
    {
        //在O(terms+cols)的時間內回傳*this的轉置矩陣
        SparseMatrix b(cols, rows, terms);
        if (terms > 0)
        {
            //非0的矩陣
            int *rowSize = new int[cols];
            int *rowStart = new int[cols];
            //計算rowSize[i]=b的第i列之項數
            fill(rowSize, rowSize + cols, 0); //初始化
            for (int i = 0; i < terms; i++)
                rowSize[smArray[i].col]++;
                //rowStart[i]=b之��始位置
                rowStart[0] = 0;
                for (int i = 1; i < cols;i++)
                    rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
                for (int i = 0; i < terms;i++){
                    //從*this複製到b
                    int j = rowStart[smArray[i].col];
                    b.smArray[j].row = smArray[i].col;
                    b.smArray[j].col = smArray[i].row;
                    b.smArray[j].value = smArray[i].value;
                    rowStart[smArray[i].col]++;
                }//for結束
                delete[] rowSize;
                delete[] rowStart;
            }//if結束
            return b;
        }

    SparseMatrix ReFastTranspose(){
        int Acurrent = 0;
        int Bcurrent = 0;
        int RowSizeCurrent = 0;
        int RowSizeCount = 0;

        int RowSize[terms];
        for (int i = 0; i < terms;i++){
            RowSize[i] = 0;
        }

        for (int i = 0; i < terms;i++){
            for (int j = 0; j < terms;j++){
                if(smArray[j].col==i){
                    RowSize[i]++;
                }
            }
        }

        SparseMatrix B(cols, rows, terms);


        while (Bcurrent < terms){
            for (Acurrent = 0; (Acurrent < terms) && (RowSizeCount < RowSize[RowSizeCurrent]); Acurrent++){
                if (smArray[Acurrent].col == RowSizeCurrent){
                    B.smArray[Bcurrent].row = smArray[Acurrent].col;
                    B.smArray[Bcurrent].col = smArray[Acurrent].row;
                    B.smArray[Bcurrent].value = smArray[Acurrent].value;
                    Bcurrent++;
                    RowSizeCount++;
                }
            }
            RowSizeCount = 0;
            RowSizeCurrent++;
        }

        return B;
        /*//在O(terms+cols)的時間內回傳*this的轉置矩陣

        SparseMatrix b(cols, rows, terms);
        if(terms>0){
            //非0的矩陣
            int *rowSize = new int[cols];
            int *rowStart = new int[cols];
            //計算rowSize[i]=b的第i列之項數
            fill(rowSize, rowSize + cols, 0);//初始化
            for (int i = 0; i < terms; i++)
            rowSize[smArray[i].col]++;
            //rowStart[i]=b之��始位置
            rowStart[0] = 0;
            for (int i = 1; i < cols;i++)
                rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
            for (int i = 0; i < terms;i++){
                //從*this複製到b
                int j = rowStart[smArray[i].col];
                b.smArray[j].row = smArray[i].col;
                b.smArray[j].col = smArray[i].row;
                b.smArray[j].value = smArray[i].value;
                rowStart[smArray[i].col]++;
            }//for結束
            delete[] rowSize;
            delete[] rowStart;
        }//if結束
        return b;*/
    }


    private:
        int rows, cols, terms, capacity;
        MatrixTerm *smArray;
};


int main(){
    int r, c, t;
    cout<< "請輸入列數、行數、非零項" << endl;
    cin >> r >> c >> t;
    cout << "列數" << r << endl;
    cout << "行數" << c << endl;
    cout << "非零項" << t << endl;

    SparseMatrix Array = SparseMatrix(r, c, t);

    Array.Read();
    cout << "show in triple" << endl;
    Array.Print();
    Array = Array.ReFastTranspose();

    cout << "After Transpose" << endl;
    Array.Print();
}
