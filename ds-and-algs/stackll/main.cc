#include "istack.h"
#include "list.h"

int main()
{
	IntStack s;

	s.push(3);
//	s.push(5);
	s.pop();

	std::cout << s << std::endl;
}
