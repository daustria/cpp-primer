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


	for (int &x : ll)
		cout << x << endl;
}
