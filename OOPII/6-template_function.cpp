#include <iostream>
using namespace std;

template <class T>
class Person {
    private:
        T nationalId;
    protected:
        string name;
        int age;
    public:
        // Cosnstructor
        Person(T id, string n, int a) : name(n), age(a), nationalId(id) {}

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
        T getNationalId(){
            return this->nationalId;
        }
        void setNationalID(T id){
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


class Employee: public Person<string>{
    private:
        float salary;
    public:
        // nationalId is string
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

        void printInfo(){
            cout << "Name: " << this->name << ", Age: " << this->age << ", National ID: " << this->getNationalId() << ", Salary: " << this->salary << endl;
        }
};

class Student: public Person<int>{
    private:
        double grade;
    public:
        // nationalId is int
        Student(int id, string n, int a, double g): Person(id, n, a) {
            this->grade = g;
        }

        // Getter and Setter for grade
        float getGrade() {
            return this->grade;
        }
        void setGrade(double grad) {
            this->grade = grad;
        }

        // Overriding
        string getRole(){
            return "Student";
        }
        void printInfo(){
            cout << "Name: " << this->name << ", Age: " << this->age << ", National ID: " << this->getNationalId() << ", Grade: " << this->grade << endl;
        }
};


template <class T>
void printPersonDetails(Person<T>& p) {
    cout << "Role: " << p.getRole() << endl;
    p.printInfo();
}



// int main(){
//     Person some_person(990745, "Mohammed", 22); 
//     Employee some_employee("accd550", "Adam", 26, 2000);
//     Student some_student(23100077, "Rawan", 19, 4.0);

//     printPersonDetails(some_person);
//     printPersonDetails(some_employee);
//     printPersonDetails(some_student);

//     return 0;
// }


// // More Uniform main
int main() {
    Person<int>*    p1 = new Person<int>(990745, "Mohammed", 22);       
    Person<string>* p2 = new Employee("accd550", "Adam", 26, 2000);
    Person<int>*    p3 = new Student(23100077, "Rawan", 19, 4.0);       

    printPersonDetails(*p1);
    printPersonDetails(*p2);
    printPersonDetails(*p3);

    delete p1;
    delete p2;
    delete p3;

    return 0;
}