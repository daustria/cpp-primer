#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template<int N, int M>
int compare(const char (&p1)[N], const char (&p2)[M])
{
	return strcmp(p1, p2);
}

template<int *n>
int foo()
{
	cout << "bar";
}

int main()
{

	int x = 5;
	constexpr int *p = &x;
	foo<p>();
}
