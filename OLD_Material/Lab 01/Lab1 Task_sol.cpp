#include <iostream>
using namespace std;

class Cuboid {
   private:
    int l;
    int w;
    int h;

   public:
    // 1. Constructor with no arguments
    Cuboid() {
        l = 2;
        w = 3;
        h = 5;
    }

    // 2. Constructor with three arguments
    Cuboid(int len, int wid, int heig) {
        l = len;
        w = wid;
        h = heig;
    }
   


	// Setter function for length
    void setLength(int len) {
      l = len;
    }

    // Setter function for width
    void setWidth(int width) {
      w = width;
    }
    
    // Setter function for height
    void setHeight(int height) {
      h = height;
    }


    // Getter function for length
    int getLength() {
      return l;
    }

    // Getter function for width
    int getWidth() {
      return w;
    }

	// Getter function for height
    int getHeight() {
      return h;
    }
    
    
	// calculate volume 
    int calcVolume() {
        return l * w * h;
    }
    
    // calculate area 
    int calcSurfArea() {
        return 2* h * (l + w);
    }
};


int main() {
    Cuboid cuboid1, cuboid2(10,20,30);

    cout << "cuboid 1: " << endl;
    cout << "volume =  " << cuboid1.calcVolume() << endl;
    cout << "Lateral suface area =  " << cuboid1.calcSurfArea() << endl;

    cout << "cuboid 2: " << endl;
    cout << "volume =  " << cuboid2.calcVolume() << endl;
    cout << "Lateral suface area =  " << cuboid2.calcSurfArea() << endl;

    return 0;
}
