#include <iostream>
#include "node.h"

class LinkedList
{
	friend std::ostream &operator<<(std::ostream &, const LinkedList &);
	public:
		int insert(int);
		int remove(int);
		int getValue(int);

	private:
		Node *head;
};

std::ostream &operator<<(std::ostream &, const LinkedList &);
