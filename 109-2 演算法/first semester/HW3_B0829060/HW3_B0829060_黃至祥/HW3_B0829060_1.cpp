#pragma clang diagnostic ignored "-Winvalid-source-encoding"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Quadratic{
    private:
        int exp2 = 0;
        int exp1 = 0;
        int exp0 = 0;
    public:
        int get_exp0() {return exp0;}
        int get_exp1() {return exp1;}
        int get_exp2() {return exp2;}
        void set_exp0(int i_exp0) { exp0 = i_exp0; }
        void set_exp1(int i_exp1) { exp1 = i_exp1; }
        void set_exp2(int i_exp2) { exp2 = i_exp2; }
        int get_vlaue(int x);
        Quadratic();
        Quadratic(int x, int y, int z);
        friend Quadratic operator+(Quadratic& q1, Quadratic& q2);
        friend ostream &operator<<(ostream &outputstream, Quadratic &q1);
        friend istream &operator>>(istream &inputstream, Quadratic &q1);
};

int main(){
    Quadratic q1;
    Quadratic q2;
    cin >> q1 >> q2;
    Quadratic q3 = q1 + q2;
    cout << q3;
    int in_x;
    cin >> in_x;
    cout << q3.get_vlaue(in_x) << endl;
}

Quadratic::Quadratic(){
    exp2 = 0;
    exp1 = 0;
    exp0 = 0;
}
Quadratic::Quadratic(int x, int y, int z){
    exp2 = x;
    exp1 = y;
    exp0 = z;
}

Quadratic operator +(Quadratic& q1,Quadratic& q2){
    //cout << q1.get_exp2() << q2.get_exp2() << endl;
    return Quadratic(q1.get_exp2() + q2.get_exp2(), q1.get_exp1() + q2.get_exp1(), q1.get_exp0() + q2.get_exp0());
}

ostream& operator <<(ostream& outputstream, Quadratic& q1){
    outputstream << q1.get_exp2() << "x*2+" << q1.get_exp1() << "x+" << q1.get_exp0() << endl;
    return outputstream;
}

istream& operator >>(istream& inputstream, Quadratic& q1){
    string source;
    inputstream >> source;
    int pos_exp_2 = source.find("x^2");
    int pos_exp_1 = source.find("x",pos_exp_2+1);
    int pos_exp_0 = source.find("+",pos_exp_1+1);
    //cout << pos_exp_2 << pos_exp_1 << pos_exp_0 << endl;
    int num_exp2,num_exp1,num_exp0;
    // if(pos_exp_2!=source.npos){
        num_exp2 = stoi(source.substr(0, pos_exp_2 - 0));
        // if(pos_exp_1!=source.npos){            
            num_exp1 = stoi(source.substr(pos_exp_2+4, pos_exp_1-pos_exp_2-4));
            if(source.substr(pos_exp_2+3,1)=="-"){
                num_exp1 = 0 - num_exp1;
            }
            // if(pos_exp_0!=source.npos){
                if(pos_exp_0==source.npos){
                    pos_exp_0 = source.find("-",pos_exp_1+1);
                    num_exp0 =0-stoi(source.substr(pos_exp_0 + 1)) ;
                }else{
                    num_exp0 =stoi(source.substr(pos_exp_0 + 1)) ;
                }    
                
            // }
        // }
        // else{
        //     num_exp1 = 0;
        //     if(pos_exp_0!=source.npos){
        //         num_exp0 = stoi(source.substr(pos_exp_0 + 1));
        //     }else{
        //         num_exp0 = 0;
        //     }
        // }
    // }
    // else{
    //     num_exp2 = 0;
    //     if(pos_exp_1!=source.npos){
    //         num_exp1 = stoi(source.substr(0, pos_exp_1-0)) ;
    //         if(pos_exp_0!=source.npos){
    //             num_exp0 = stoi(source.substr(pos_exp_0 + 1)) ;
    //         }else{
    //             num_exp0 = 0;
    //         }
    //     }else{
    //         num_exp1 = 0;
    //         num_exp0 = stoi(source);
    //     }
    // }

    q1.set_exp2(num_exp2);
    q1.set_exp1(num_exp1);
    q1.set_exp0(num_exp0);

    //cout << num_exp2 << num_exp1 << num_exp0 << endl;
    return inputstream;
}

int Quadratic::get_vlaue(int x){
    return exp2 * x * x + exp1 * x + exp0;
}