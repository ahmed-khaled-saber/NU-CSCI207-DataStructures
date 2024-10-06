// Author: Ahmed Khaled, 6 oct 24.
#include <iostream>
using namespace std;
int main(){

    // How to let program branch and decide ? Condition.
    int score;
    cout<<"What Score you got ?: ";
    cin>>score;

    if(score < 50){
        cout<<"try another time! \n";
    }else{
        cout<<"you Passed!"<<endl;
    }
    
    return 0;
}
