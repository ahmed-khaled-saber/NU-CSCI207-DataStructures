// Author: Ahmed Khaled, 6 oct 24.
#include <iostream>
#include <string>
using namespace std;
int main(){

    // How to build compuond data and access every part of it ? arrays with loops.
    string top5student[5] = {"Ahmed", "Adham", "Rana", "Gamal", "Mina"};
    int scores[5] = {50, 40, 30, 20, 5};

    cout<<"********** Leader Board **********"<<endl;
    for(int i=0; i<5; i++){
        cout<<"Student: "<<top5student[i]<<" with score: "<<scores[i]<<endl;
        cout<<"____________________________________________________________ \n";
    }

    return 0;
}
