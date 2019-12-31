#include "stack.h"
#include <string>


int main()
{
	Stack<int> s;

	s.push(5);
	s.push(3);
	s.push(7);
	s.push(9);

	s.pop();
	s.pop();
	std::cout << s.peek() << std::endl;
}
