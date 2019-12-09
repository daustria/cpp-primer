#include <string>
#include <iostream>

class Employee
{

	friend std::ostream &operator<<(std::ostream &out, const Employee &);

	public:
		Employee(): name(""), id(counter++) {}
	
		Employee(const std::string &employeeName): name(employeeName), id(counter++) {}

		Employee(const Employee &other): name(other.name), id(counter++) {}	

		//The copy assignment constructor is implicitly deleted because this class has a const member
		//
		
		~Employee()
		{
			if (id == counter - 1)
			{
				--counter;
			}
		}

	private:
		std::string name;
		const int id;
		static int counter;

};

std::ostream &operator<<(std::ostream &out, const Employee &e)
{
	std::cout << e.name << ' ' << e.id;
	return out;
}

int Employee::counter = 0;

int main()
{
	Employee bob("Bob");
	Employee alice("Alice");
	Employee alice2 = alice; 

	std::cout << bob << std::endl;
	std::cout << alice << std::endl;
	std::cout << alice2 << std::endl;

	alice2.~Employee();

	Employee dominic("Dominic");
	
	std::cout << dominic << std::endl;
}
