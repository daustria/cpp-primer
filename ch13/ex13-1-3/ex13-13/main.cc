#include <string>
#include <iostream>

struct X
{
	X()
	{
		std::cout << " X() " << std::endl;
	}

	X(int n)
	{
		std::cout << " X(int n) " << std::endl;
	}

	X(const X &)
	{
		std::cout << " X(const X&) " << std::endl;
	}

	X &operator=(const X &)
	{
		std::cout << " X &operator=(const X&) " << std::endl;
	}

	~X()
	{
		std::cout << " ~X() " << std::endl;
	}
};


void foo()
{
	X x1{};
	X x2{x1};
	X x3;
	x3 = x1;

}


int main()
{
	foo();
}
