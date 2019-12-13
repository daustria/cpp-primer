#include <iostream>
#include "list.h"
#include <string>

struct List::Node
{
	int data;
	Node *next = nullptr;

	Node() = default;
	Node(int n, Node *np) : data(n), next(np) {}
	~Node() { delete next; }
};

List::Iterator::Iterator(Node *np): p(np) {}

List::Iterator List::Iterator::operator++()
{
	p = p->next;
	return *this;
}

int &List::Iterator::operator*()
{
	return p->data;
}

bool List::Iterator::operator!=(const List::Iterator &other)
{
	return p != other.p;
}


List::Iterator List::begin() const
{
	return List::Iterator{head};
}

List::Iterator List::end() const
{
	return List::Iterator{nullptr};
}

List::~List()
{
	delete head;
}

void List::addToFront(int n)
{
	Node *np = new Node(n, head);
	head = np;
}

int List::ith(int i)
{

	Node *current = head;

	while(i > 0)
	{
		current = current->next;
		--i;	
	}

	return current->data;
}

int List::remove(int i)
{
	Node *current = head;
	Node *prev = nullptr;
	while (i > 0)
	{
		prev = current;
		current = current->next;
		--i;
	}

	int retval = current->data;

	if (prev) 
		prev->next = current->next;
	else
		head = current->next;

	current = nullptr;
	delete current;

	return retval;
}

bool List::empty() const
{
	return head ? false : true;
}


std::ostream &operator<<(std::ostream &out, const List &ll)
{
	if (ll.empty()) {
		out << "empty";
		return out;
	}

	for (auto const &x : ll)
		out << x << ',';

	out << '\b' << ".";
	return out;
}


