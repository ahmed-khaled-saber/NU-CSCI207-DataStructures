#include <iostream>
using namespace std;

template <class T>
class Box{
    private:
        T content;
    public:
        // constructor
        Box(){this->content=-1;};
        Box(T content){this->content=content;};
        // getters and setters
        void setcontent(T content){this->content=content;}
        T getcontent(){return this->content;}
        // member function(s)
        void show_content(){cout<< this->content << endl;}
        // destructor
        ~Box(){};
};



template<typename T>
bool compare_boxes(Box<T> b1, Box<T> b2){
    return b1.getcontent() == b2.getcontent();
}
 

int main(){
    Box<string> box1("Help");
    Box<int> box2(10);
    Box<double> box3(9.3);
    Box<int> box4(11);

    if (! compare_boxes(box2, box4)){
        cout<<"Boxes have different CONTENT"<<endl;
    }
    return 0;
}