#include <iostream>
#include <string>
#include <vector>
#include <list>

//Exercise 16.1
/*
 * Instatiation refers to the compiler instantiating an
 * appropriate function definition for some function template call.
 *
 * The specifics of the function definition are deduced based
 * on the arguments passed to the function call.
 */

//Exercise 16.4

template<typename T, typename U>
int myFind(const T &first, const T &last, const U &val)
{
	int i = 0;

	for(T it = first; it != last; ++it)
	{
		if (*it == val)
			return i;
		++i;
	}

	return -1;
}

int main()
{
	std::vector<int> v{-1, 3, -5, 7, 2};

	auto first = v.begin();
	auto last = v.end();

	std::cout << myFind(first, last, -5) << std::endl;


	std::list<std::string> l{"Dog", "Cat", "Snake", "Bird", "Lion"};

	auto lstFirst = l.begin();
	auto lstLast = l.end();

	std::cout << myFind(lstFirst, lstLast, "Bird") << std::endl;

}
