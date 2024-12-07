#include<iostream>
using namespace std;

class animal
{
	protected:
		string color = "default color";
	public:
		void display_color()
		{
			cout<<color<<endl;	
		} 
		
};

class Dog : public animal
{
	public:
		void update_color()
		{
			color = "Brown";
		}
};

class Cat : public animal
{
	public:
		void update_color()
		{
			color = "White";
		}
};

int main()
{
	Dog dog;
	Cat cat;
	dog.update_color();
	dog.display_color();
	cat.update_color();
	cat.display_color();
	return 0;
}
