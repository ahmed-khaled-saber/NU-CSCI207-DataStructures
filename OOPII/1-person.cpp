#include <iostream>
using namespace std;

class Person {
    private:
        string nationalId;
        string name;
        int age;
    public:
        // Cosnstructor
        Person(string id, string n, int a) : name(n), age(a), nationalId(id) {}

        // Getters and Setters
        string getName(){
            return this->name;
        }
        void setName(string n) {
            this->name = n;
        }
        int getAge(){
            return this->age;
        }
        void setAge(int a) {
            this->age = a;
        }
        string getNationalId(){
            return this->nationalId;
        }
        void setNationalID(string id){
            this->nationalId = id;
        }

        // member functions
        string getRole(){
            return "Person";
        }
        void printInfo(){
            cout << "Name: " << this->name << ", Age: " << this->age << ", National ID: " << this->nationalId << endl;
        }
};

int main(){
    Person some_person("0990745", "Mohammed", 22);
    cout << some_person.getRole() << endl;
    some_person.printInfo();

    return 0;
}