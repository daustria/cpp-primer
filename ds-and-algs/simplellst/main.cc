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


//	cout << ll << endl;
//
//	cout << ll.ith(0) << endl;
//	cout << ll.ith(3) << endl;
//	cout << ll.remove(3) << endl;
//	cout << ll << endl;

	List::Iterator it = ll.begin();

//	for(List::Iterator it = ll.begin(); it != ll.end(); ++it)
//	{
//		cout << *it << endl;
//		*it = *it + 1;
//	}

	for (int &x : ll)
	{
		x = x + 1;
	}
	cout << ll << endl;
}
