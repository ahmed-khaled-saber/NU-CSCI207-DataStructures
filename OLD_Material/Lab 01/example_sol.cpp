#include <iostream>
using namespace std;

class Room {
   private:
    double length;
    double breadth;
    string room_name;

   public:
    // 1. Constructor with no arguments
    Room() {
        length = 6.9;
        breadth = 4.2;
        room_name = "bed Room";
    }

    // 2. Constructor with three arguments
    Room(double l, double b, string s) {
        length = l;
        breadth = b;
        room_name = s;
    }
    // 3. Constructor with one argument
    Room(double len) {
        length = len;
        breadth = 7.2;
        room_name = "Living Room";
    }


	// Setter function for length
    void setLength(int len) {
      length = len;
    }

    // Setter function for breadth
    void setBreadth(int brth) {
      breadth = brth;
    }
    
    // Setter function for room_name
    void setroom_name(string room_name) {
      room_name = room_name;
    }

    // Getter function for length
    int getLength() {
      return length;
    }

    // Getter function for breadth
    int getBreadth() {
      return breadth;
    }

	// Getter function for room_name
    string getroom_name() {
      return room_name;
    }
    
	// calculate area of Room
    double calculateArea() {
        return length * breadth;
    }
};

int main() {
    Room room1, room2(8.2, 6.6,"kitchen"), room3(8.2);

    cout << "When no argument is passed: " << endl;
    cout << "Area of " << room1.getroom_name() << " : " << room1.calculateArea() << endl;

    cout << "\nWhen (8.2, 6.6,\"kitchen\") is passed." << endl;
    cout << "Area of " << room2.getroom_name() << " : " << room2.calculateArea() << endl;

    cout << "\nWhen pass only length (8.2):" << endl;
    cout << "Area of " << room3.getroom_name() << " : " << room3.calculateArea() << endl;

    return 0;
}
