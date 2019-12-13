#include <iostream>
#include "node.h"

class LinkedList
{

	friend std::ostream &operator<<(std::ostream &, const LinkedList &);

	public:
		LinkedList();
		int addToFront(int);
		int remove(int);
		int ith(int);

	private:
		Node *head;
};

std::ostream &operator<<(std::ostream &, const LinkedList &);
