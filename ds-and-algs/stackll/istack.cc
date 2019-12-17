#include "istack.h"
#include <iostream>

void IntStack::push(int n)
{
	ll.addToFront(n);
}

int IntStack::pop()
{
	return ll.removeFront();
}

bool IntStack::empty() const
{
	return ll.empty();
}

int IntStack::size() const
{
	return ll.getSize();
}

std::ostream &operator<<(std::ostream &out, const IntStack &s)
{
	out << s.ll;
	return out;
}

