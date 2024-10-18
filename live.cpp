#include <iostream>
using namespace std;

template <class T>
class Box{
    private:
        T content;
    public:
        Box(){
            content = -1;
        }
        Box(T c){
            content = c;
        }
        void setcontent(T c){
            content = c;
        }
        T getcontent(){
            return content;
        }
        void reveal(){
            cout << content << endl;
        }
};


template<typename T>
bool compare_boxes(Box<T> b1, Box<T> b2){
    return b1.getcontent() > b2.getcontent();
}


int main(){
    Box<int> b1(5);
    Box<int> b2(10);

    if(compare_boxes(b1, b2)){
        cout<<"equal"<<endl;
    }else{
        cout<<"not equal"<<endl;
    }
    

    return 0;
}