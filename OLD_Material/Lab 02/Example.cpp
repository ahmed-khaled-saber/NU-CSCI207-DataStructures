#include<iostream>
using namespace std;

class person
{
	protected:
		int id;
		string name;
	public:
		person(int id,string name)
		{
			this->id = id;
			this->name = name;
		}
};

class Emp : public person
{
	float salary;
	public:
		Emp(int id,string name,float salary) 
		{
			this->id=id;
			this->name=name;
			this->salary = salary;
		}
		void display()
		{
			cout<<"id: "<<id<<endl<<"name: "<<name<<endl<<"salary: "<<salary<<endl;	
		}	
};

int main()
{
	Emp obj(2,"ahmed",2000);
	obj.display();
	return 0;
}
