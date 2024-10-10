// Author: Ahmed Khaled, 6 oct 24.
#include <iostream>
using namespace std;

int rpow(int base, int exp){ // fabulous recursive function.
    if (exp == 0){
        return 1;
    }else{
        return base * rpow(base, exp-1);
    }
}
int lpow(int base, int exp){
    int result = 1;
    for(int i=0; i<exp; i++){
        result *= base;
    }
    return result;
}

int main(){

    // How to make your program modular (compasable) ? functions.
    cout<<"2 to the power of 3 is ? "<< lpow(2, 3)<<endl;
    return 0;
}
