#include <iostream>
using namespace std;

class Person {
    private:
        string id;
        string name;
        int age;
    public:
        // Cosnstructor using Initializer Syntax
        Person(string id, string n, int a) : name(n), age(a), id(id) {}

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

// reuse parent constructor; as it's a public Interface
class Employee: public Person{
    public:
        Employee(string id, string n, int a): Person(id, n, a) {}
};

int main(){
    Person some_person("29907141401518", "Mohammed", 22);
    cout << some_person.getRole() << endl;
    some_person.printInfo();

    Employee some_employee("accd550", "Adam", 26);
    cout << some_employee.getRole() << endl;
    some_employee.printInfo();

    // How Employee Class has fields id, name, age ?, How methos getRole and prinInfo even works ? INHERITANCE.
    return 0;
}