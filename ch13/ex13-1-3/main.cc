#include <string>
#include <iostream>

//Exercise 13.9
/*
 * A destructor is a method that manages the object's destruction.
 * Like the copy and copy assignment constructor, the compiler generates a synthesized
 * destructor when the class does not define its own destructor. When a destructor is called,
 * its function body runs and then the destructors for each of its members are called, in the reverse
 * initialization order. For members that do not have destructors, specifically the built-in types,
 * nothing is done. 
 * Afterwards, space that was allocated for the object is then deallocated.
 *
 * Here are some scenarios of when a destructor would be called on an object:
 * 
 * -The object is stack allocated, and goes out of scope.
 * 
 * -The object is heap allocated, and the delete keyword was called on a pointer that
 * points to that object.
 *
 * -The object is implicitly destroyed as a result of being a data member of an instance
 * of some class whose destructor was called.
 */

//Exercise 13.11

class HasPtr
{
	public:
		//constructor
		HasPtr(const std::string &s = std::string()):
			ps(new std::string(s)), i(0)
		{
		
		}

		//copy constructor
		HasPtr(const HasPtr &rhs)
		{
			//dynamically allocate a new string.
			ps = new std::string(*rhs.ps);
			i = rhs.i;
		}

		//copy assignment constructor
		HasPtr &operator=(const HasPtr &rhs)
		{
			//invoke the copy constructor
			*this = rhs;
		}

		//destructor
		//note that there is no analogous list to the MIL, for destructors.
		~HasPtr()
		{

			//note that destructors do not implicity delete dynamically allocated
			//objects to which pointers point to.
			//hence we must delete them directly.
			delete ps;

		}

		friend std::ostream &operator<<(std::ostream &out, const HasPtr &rhs);

	private:
		std::string *ps;
		int i;

};

std::ostream &operator<<(std::ostream &out, const HasPtr &rhs)
{
	out << *(rhs.ps) << " " << rhs.i << std::endl;
}

int main()
{
	std::string s("hello");
	int i = 5;
	
	HasPtr hp{s}; //default constructor

	std::cout << hp << std::endl;

	HasPtr hp2{hp}; //copy constructor

	std::cout << hp2 << std::endl;

	HasPtr hp3 = hp2; //copy assignment constructor

	std::cout << hp3 << std::endl;


}
