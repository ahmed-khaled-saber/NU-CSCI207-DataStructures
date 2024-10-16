#include <iostream>
using namespace std;

class Person {
    private:
        string id;
        string name;
        int age;
    public:
        // Cosnstructor
        Person(string id, string name, int age){
            this->id = id;
            this->name = name;
            this->age = age;
        }

        // Getters and Setters
        string getId(){
            return this->id;
        }
        string getName(){
            return this->name;
        }
        int getAge(){
            return this->age;
        }
        void setId(string id){
            this->id = id;
        }
        void setName(string name) {
            this->name = name;
        }
        void setAge(int age) {
            this->age = age;
        }

        // member functions
        string getRole(){
            return "Person";
        }
        void printInfo(){
            cout << "Name: " << this->name << ", Age: " << this->age << ", National ID: " << this->id << endl;
        }
};

int main(){
    Person some_person("29907141401518", "Mohammed", 25);

    cout << some_person.getRole() << endl;
    some_person.printInfo();

    return 0;
}