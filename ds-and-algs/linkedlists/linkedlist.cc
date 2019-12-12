#include <iostream>
#include "linkedlist.h"

int LinkedList::insert(int k)
{
	Node *np = new Node(k, nullptr);
	np->setNext(head);
	head->setNext(np);
	return k;
}

std::ostream &operator<<(std::ostream &out, const LinkedList &llst)
{
	out << *llst.head;
	return out;
}
