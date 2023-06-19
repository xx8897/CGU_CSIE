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
            cout << "½Ð¿é¤JMatrixªº¤T­Ó¤º®e"<<endl;
            cin >> row ;
            cin.ignore();
            cin >> col;
            cin.ignore();
            cin>>value;
            cin.ignore();
            cout << "¿é¤J§¹¦¨" << endl;
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

        cout << "              ¦C    ¦æ    ­È" <<endl;
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
        //¦bO(terms+cols)ªº®É¶¡¤º¦^¶Ç*thisªºÂà¸m¯x°}
        SparseMatrix b(cols, rows, terms);
        if (terms > 0)
        {
            //«D0ªº¯x°}
            int *rowSize = new int[cols];
            int *rowStart = new int[cols];
            //­pºârowSize[i]=bªº²Äi¦C¤§¶µ¼Æ
            fill(rowSize, rowSize + cols, 0); //ªì©l¤Æ
            for (int i = 0; i < terms; i++)
                rowSize[smArray[i].col]++;
                //rowStart[i]=b¤§þ©l¦ì¸m
                rowStart[0] = 0;
                for (int i = 1; i < cols;i++)
                    rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
                for (int i = 0; i < terms;i++){
                    //±q*this½Æ»s¨ìb
                    int j = rowStart[smArray[i].col];
                    b.smArray[j].row = smArray[i].col;
                    b.smArray[j].col = smArray[i].row;
                    b.smArray[j].value = smArray[i].value;
                    rowStart[smArray[i].col]++;
                }//forµ²§ô
                delete[] rowSize;
                delete[] rowStart;
            }//ifµ²§ô
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
        /*//¦bO(terms+cols)ªº®É¶¡¤º¦^¶Ç*thisªºÂà¸m¯x°}

        SparseMatrix b(cols, rows, terms);
        if(terms>0){
            //«D0ªº¯x°}
            int *rowSize = new int[cols];
            int *rowStart = new int[cols];
            //­pºârowSize[i]=bªº²Äi¦C¤§¶µ¼Æ
            fill(rowSize, rowSize + cols, 0);//ªì©l¤Æ
            for (int i = 0; i < terms; i++)
            rowSize[smArray[i].col]++;
            //rowStart[i]=b¤§þ©l¦ì¸m
            rowStart[0] = 0;
            for (int i = 1; i < cols;i++)
                rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
            for (int i = 0; i < terms;i++){
                //±q*this½Æ»s¨ìb
                int j = rowStart[smArray[i].col];
                b.smArray[j].row = smArray[i].col;
                b.smArray[j].col = smArray[i].row;
                b.smArray[j].value = smArray[i].value;
                rowStart[smArray[i].col]++;
            }//forµ²§ô
            delete[] rowSize;
            delete[] rowStart;
        }//ifµ²§ô
        return b;*/
    }


    private:
        int rows, cols, terms, capacity;
        MatrixTerm *smArray;
};


int main(){
    int r, c, t;
    cout<< "½Ð¿é¤J¦C¼Æ¡B¦æ¼Æ¡B«D¹s¶µ" << endl;
    cin >> r >> c >> t;
    cout << "¦C¼Æ" << r << endl;
    cout << "¦æ¼Æ" << c << endl;
    cout << "«D¹s¶µ" << t << endl;

    SparseMatrix Array = SparseMatrix(r, c, t);

    Array.Read();
    cout << "show in triple" << endl;
    Array.Print();
    Array = Array.ReFastTranspose();

    cout << "After Transpose" << endl;
    Array.Print();
}
