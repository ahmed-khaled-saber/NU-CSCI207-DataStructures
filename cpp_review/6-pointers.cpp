// Author: Ahmed Khaled, 6 oct 24.
#include <iostream>
using namespace std;
int main(){

    // memory close control ? pointers.
    int x = 10;
    int* ptr;

    ptr = &x;
    cout<<"The value of x accessed by a pointer to x is "<<*ptr<<endl;
    *ptr = 20;
    cout<<"The value of x after update it throught a pointer "<<x<<endl;

    delete ptr;
    return 0;
}
