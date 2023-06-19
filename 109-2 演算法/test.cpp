#include <iostream>
#include <time.h>
using namespace std;
int main(){
    cout<<"Hello world!你好世界!\n";
    float start= clock();
    float end = clock();
    float total = end - start;
    printf("%f", total);
    return 0;  
}
