#include <string>
#include <iostream>
#include <cstddef>

// HasPtr will act like a pointer. We will keep a reference count of how many things
// that point to the thing that HasPtr points to

class HasPtr
{
	public:

		HasPtr(const std::string &s = std::string(), int ii = 0):
			ps(new std::string{s}), i(ii), use(new size_t{1})
		{
		
		}

		//copy constructor
		HasPtr(const HasPtr &rhs): ps(rhs.ps), i(rhs.i), use(rhs.use)
		{
			++*use;
		}

		//copy assignment constructor
		HasPtr &operator=(const HasPtr &rhs)
		{

			std::size_t *newuse = rhs.use;
			++*newuse;

			if (--*use == 0)
			{
				delete use;
				delete ps;
			}

			ps = rhs.ps;
			i = rhs.i;
			use = newuse;
			return *this;
		}


		//destructor
		~HasPtr()
		{
			if (--*use == 0)
			{
				delete use;
				delete ps;
			}
		}

		friend std::ostream &operator<<(std::ostream &out, const HasPtr &rhs);

	private:
		std::string *ps;
		int i;
		std::size_t *use;

};

std::ostream &operator<<(std::ostream &out, const HasPtr &rhs)
{
	out << *(rhs.ps) << " " << rhs.i << " " << *(rhs.use);
}

int main()
{
	std::string s1("hello");
	std::string s2("world");
	int i1 = 5;
	int i2 = -3;
	
	HasPtr hp1{s1, i1};
	HasPtr hp2{s2, i2};

	hp1 = hp1;
	std::cout << hp1 << std::endl;
//	std::cout << hp2 << std::endl;
}
