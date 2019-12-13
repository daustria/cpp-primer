#include <string>
#include <iostream>
#include <cassert>
#include "linkedlist.h"

LinkedList::LinkedList(): head(nullptr) {}


int LinkedList::addToFront(int k)
{
	Node *np = new Node(k, head ? head : nullptr);
	head = np;
	return k;
}

int LinkedList::ith(int i)
{
	Node *current = head;
	while(i > 0)
	{
		assert(current);
		current = current->next;
		--i;
	}

	return current->data;
}

int LinkedList::remove(int pos)
{
	
	Node *current = head;
	Node *prev = nullptr;

	while(pos > 0)
	{
		assert(current); //current should always be valid if pos is a valid index
		prev = current;
		current = current->next;
		--pos;
	}

	if (prev)
		prev->next = current->next;
	else
		head = current->next;
	
	current->next = nullptr;
	int retval = current->data;
	delete current;
	return retval;
	
}

std::ostream &operator<<(std::ostream &out, const LinkedList &llst)
{
	if (llst.head)
		out << *llst.head;
	else
		out << "empty";

	return out;
}
