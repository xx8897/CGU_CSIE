#pragma clang diagnostic ignored "-Winvalid-source-encoding"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Quadratic{
    private:
        int exponent2 = 0;
        int exponent1 = 0;
        int exponent0 = 0;

    public:
        int get_exp0() {return exponent0;}
        int get_exp1() {return exponent1;}
        int get_exp2() {return exponent2;}
        void set_exp0(int i_exp0) { exponent0 = i_exp0; }
        void set_exp1(int i_exp1) { exponent1 = i_exp1; }
        void set_exp2(int i_exp2) { exponent2 = i_exp2; }
        int get_vlaue(int x);
        Quadratic();
        Quadratic(int x, int y, int z);
        friend Quadratic operator+(Quadratic& poly1, Quadratic& poly2);
        friend ostream &operator<<(ostream &outputstream, Quadratic &poly1);
        friend istream &operator>>(istream &inputstream, Quadratic &poly1);

};

int main(){
    Quadratic poly1;
    Quadratic poly2;

    cin >> poly1 >> poly2;
    Quadratic poly3 = poly1 + poly2;
    cout << poly3;

    int in_x;
    cin >> in_x;
    cout << poly3.get_vlaue(in_x) << endl;
}

Quadratic::Quadratic(){
    exponent2 = 0;
    exponent1 = 0;
    exponent0 = 0;
}

Quadratic::Quadratic(int x, int y, int z){
    exponent2 = x;
    exponent1 = y;
    exponent0 = z;
}

Quadratic operator +(Quadratic& poly1,Quadratic& poly2){

    return Quadratic(poly1.get_exp2() + poly2.get_exp2(), poly1.get_exp1() + poly2.get_exp1(), poly1.get_exp0() + poly2.get_exp0());
}

ostream& operator <<(ostream& outputstream, Quadratic& poly1){

    outputstream << poly1.get_exp2() << "x*2+" << poly1.get_exp1() << "x+" << poly1.get_exp0() << endl;
    return outputstream;
}

istream& operator >>(istream& inputstream, Quadratic& poly1){

    string source;
    inputstream >> source;

    int pos_exp_2 = source.find("x^2");
    int pos_exp_1 = source.find("x",pos_exp_2+1);
    int pos_exp_0 = source.find("+",pos_exp_1+1);

    int num_exp2,num_exp1,num_exp0;

        num_exp2 = stoi(source.substr(0, pos_exp_2 - 0));
      
            num_exp1 = stoi(source.substr(pos_exp_2+4, pos_exp_1-pos_exp_2-4));

            if(source.substr(pos_exp_2+3,1)=="-"){
                num_exp1 = 0 - num_exp1;
            }

                if(pos_exp_0==source.npos){
                    pos_exp_0 = source.find("-",pos_exp_1+1);
                    num_exp0 =0-stoi(source.substr(pos_exp_0 + 1)) ;
                    
                }else{
                    num_exp0 =stoi(source.substr(pos_exp_0 + 1)) ;
                }    


    poly1.set_exp2(num_exp2);
    poly1.set_exp1(num_exp1);
    poly1.set_exp0(num_exp0);

    return inputstream;
}

int Quadratic::get_vlaue(int x){
    return exponent2 * x * x + exponent1 * x + exponent0;
}