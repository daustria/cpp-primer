#include "list.h"
#include <iostream>
using namespace std;
int main()

{
	List ll;
	ll.addToFront(5);
	ll.addToFront(7);
	ll.addToFront(-3);
	ll.addToFront(0);
	ll.addToFront(20);
	ll.addToFront(-7);

	for (int &x : ll)
		++x;

	cout << ll << endl;
}
