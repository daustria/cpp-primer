#ifndef INT_STACK_H
#define INT_STACK_H
#include "list.h"
#include <iostream>

class IntStack
{

	public:
		void push(int);
		int pop();
		bool empty();
	private:
		List ll;

};

std::ostream &operator<<(std::ostream &, const IntStack &);

#endif // INT_STACK_H
