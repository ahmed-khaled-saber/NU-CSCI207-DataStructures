#include <iostream>
using namespace std;

class Person {
    private:
        string nationalId;
    protected:
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


class Employee: public Person{
    private:
        float salary;
    public:
        Employee(string id, string n, int a, float s): Person(id, n, a) {
            this->salary = s;
        }

        // Getter and Setter for salary
        float getSalary() const {
            return this->salary;
        }
        void setSalary(float sal) {
            this->salary = sal;
        }

        // Overriding
        string getRole(){
            return "Employee";
        }
        // why only this->nationalId don't work ? Alter Access Modifiers!, or try using parent public Interface !!
        void printInfo(){
            // cout << "Name: " << this->name << ", Age: " << this->age << ", National ID: " << this->nationalId << ", Salary: " << this->salary << endl;
            cout << "Name: " << this->name << ", Age: " << this->age << ", Salary: " << this->salary << endl;
        }
};

int main(){
    Person some_person("0990745", "Mohammed", 22);
    cout << some_person.getRole() << endl;
    some_person.printInfo();

    Employee some_employee("accd550", "Adam", 26, 2000);
    cout << some_employee.getRole() << endl;
    some_employee.printInfo();

    return 0;
}