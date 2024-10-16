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
 

int main(){
    Box<string> box1("Help");
    Box<int> box2(1000);
    Box<double> box3(9.3);

    box1.show_content();
    box2.show_content();
    box3.show_content();

    return 0;
}