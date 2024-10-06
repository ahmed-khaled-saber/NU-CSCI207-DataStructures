#include <iostream>
using namespace std;

class Car {
private:
    int speed;       // Encapsulation: speed, model are private
    string model;    

public:
    // Default constructor
    Car::Car(){
        speed = 0;
        model = "Unknown"
    }

    // Parametrized constructor
    Car::Car(int spd, string mdl){
        speed = spd;
        model = mdl;
    }
    // Destructor
    ~Car() {
        cout << "Car object destroyed. Model = " << model << endl;
    }

    // Setter for speed
    void setSpeed(int spd) {
        speed = spd;
    }

    // Getter for speed
    int getSpeed() {
        return speed;
    }

    // Setter for model
    void setModel(string mdl) {
        model = mdl;
    }

    // Getter for model
    string getModel() {
        return model;
    }

    // Overloaded function: Calculate time to travel x miles

    // Polymorphism: Overload for integer miles
    void calculateTime(int miles) {
        if (speed > 0) {
            double time = (double)miles / speed;
            cout << "It will take " << time << " hours to travel " << miles << " miles." << endl;
        } else {
            cout << "Speed must be greater than 0!" << endl;
        }
    }

    // Overloaded function: Calculate time to travel x miles (double version)
    void calculateTime(double miles) {
        if (speed > 0) {
            double time = miles / speed;
            cout << "It will take " << time << " hours to travel " << miles << " miles." << endl;
        } else {
            cout << "Speed must be greater than 0!" << endl;
        }
    }
};

int main() {
     
    Car car1;   // default constructor

    Car car2(60, "Toyota"); // parametrized constructor

    // Set the speed and model for car1 using setters [Encapsulation]
    car1.setSpeed(50);
    car1.setModel("Honda");

    // Display the details of car1 using getters
    cout << "Car 1: " << car1.getModel() << ", Speed: " << car1.getSpeed() << " mph" << endl;

    // Calculate the time to travel 120 miles
    car1.calculateTime(120);    // Integer overload
    car2.calculateTime(150.5);  // Double overload

    return 0;
}
