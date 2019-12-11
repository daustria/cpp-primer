#include <vector>
#include <iostream>

//Exercise 13.45
/*
 * An lvalue reference is a reference that is bound to an lvalue. It is an 'alias'
 * for its initializer. 
 *
 * An rvalue reference on the otherhand, is a reference that is bound to an rvalue.
 * Note that an rvalue cannot be bound to an lvalue, and a (non const) lvalue cannot
 * be bound to an rvalue.
 *
 */
int main()
{
	std::vector<int> vi(100);
	int &r2 = vi[0];
}
