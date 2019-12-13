#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
	LinkedList llst;
	llst.addToFront(5);
	llst.addToFront(20);
	llst.addToFront(30);
	cout << llst.ith(0) << endl;
	cout << llst << endl;

	LinkedList l2 = llst;

}

