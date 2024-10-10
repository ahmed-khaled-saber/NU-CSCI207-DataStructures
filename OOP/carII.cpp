#include <iostream>;
using namespace std;

class Car{
    private:
        int speed;
        string model;
    public:
        Car(){
            speed = 0;
            model = "unknown";
        }

        Car(int spd, string mdl){
            speed = spd;
            model = mdl;
        }

        ~Car(){
            cout<<"removed.";
        }

        void setSpeed(int spd){
            speed = spd;
        }

        


}


int main(){
    // Use Class

    return 0;
}