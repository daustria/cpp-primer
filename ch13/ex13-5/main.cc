#include <string>
#include <iostream>
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

			ps = new std::string(*rhs.ps);
			i = rhs.i;
		}

		

	private:
		std::string *ps;
		int i;

};

int main()
{
	std::string s("hello");
	int i = 5;
	
	HasPtr hp(s); //default constructor
	HasPtr hp2 = hp; //copy constructor


}
