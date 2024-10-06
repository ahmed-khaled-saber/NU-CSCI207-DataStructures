// Author: Ahmed Khaled, 6 oct 24.
#include <iostream>
using namespace std;
int main(){

    // Compound Information ?  struct.
    struct date
    {
        int d, m, y;
    };
    date today = {6, 10, 2024};
    cout<<"Tommorow is "<<today.d+1<<" - "<<today.m<<" - "<<today.y<<endl;
    
    return 0;
}
