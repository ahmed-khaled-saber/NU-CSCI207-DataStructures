// Author: Ahmed Khaled, 6 oct 24.
/***
 * Why OOP ? 
 * Encapsulation.
 * Abstraction. (Information Hiding) (Ploymorphism)
 * Inheritance. (code reuse)
 */

#include <iostream>
#include <string>
using namespace std;

class Room
{
    private:
        float length;
        float breadth;
        string name;
    public:
        Room();
        Room(float l);
        Room(float l, float b, string n);
        void display_info(){
            cout<<"Room Type is "<<name<<" its lenght by breadth is " << length <<" x "<<breadth<<endl;
        }
        ~Room();
};
Room::Room()
{
    length = 6.9;
    breadth = 4.2;
    name = "bed room";
}
Room::Room(float l)
{
    length = l;
    breadth = 7.2;
    name = "living room";
}
Room::Room(float l, float b, string n)
{
    length = l;
    breadth = b;
    name = n;
}
Room::~Room()
{
    cout << "Item " << name << " destroyed!" << endl;
}


int main(){

    // 
    Room r1;
    Room r2(100.2);
    Room r3(10.5, 10.5, "study room");

    r1.display_info();
    r2.display_info();
    r3.display_info();

    return 0;
}
