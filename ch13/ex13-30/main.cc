#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
//Exercise 13.29
/*
 * the calls to swap inside the function are different from swap(HasPtr &, HasPtr &).
 * more precisely, they are std::swap calls that take pointers and integers
 */

class HasPtr
{

	friend std::ostream &operator<<(std::ostream &out, const HasPtr &hp);
	friend void swap(HasPtr &, HasPtr &);

	public:
		HasPtr(const std::string &s = std::string()):
			ps(new std::string(s)), i(0)
		{}

		HasPtr(const HasPtr &p):
			ps(new std::string(*p.ps)), i(p.i)
		{}

		HasPtr &operator=(HasPtr rhs)
		{
			using std::swap;
			swap(*this, rhs);
			return *this;
		}

		~HasPtr() 
		{
			delete ps;
		}

		bool operator<(const HasPtr &other)
		{
			return *ps < *other.ps;
		}

	private:
		std::string *ps;
		int i;
};

inline
void swap(HasPtr &lhs, HasPtr &rhs)
{

	std::cout << "swap" << std::endl;
	std::cout << "	" << lhs << std::endl;
	std::cout << "	" << rhs << std::endl;

	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

std::ostream &operator<<(std::ostream &out, const HasPtr &hp)
{
	out << *hp.ps << ' ' << hp.ps << ' ' << hp.i;
	return out;
}


int main()
{
//	HasPtr hp{"Hello"};
//
//	HasPtr hp2{"World"};
//
//	swap(hp, hp2);
//
//	std::cout << hp << std::endl;
//	std::cout << hp2 << std::endl;
//


	HasPtr hp1{"hello"};
	HasPtr hp2{"meow"};
	HasPtr hp3{"Aardvark"};
	HasPtr hp4{"Cuckoo"};

	std::vector<HasPtr> v{hp1, hp2, hp3, hp4};

	std::sort(v.begin(), v.end());
//	std::cout << v << std::endl;
//


	for (auto &i : v)
	{
		std::cout << i << std::endl;
	}
}
