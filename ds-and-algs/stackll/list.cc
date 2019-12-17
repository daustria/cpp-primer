#include <iostream>
#include "list.h"
#include <string>

struct List::Node
{
	int data = 0;
	Node *next = nullptr;
	Node *back = nullptr;

	Node() = default;
	Node(int n, Node *f, Node *b) : data(n), next(f), back(b){}
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
	Node *np = new Node(n, nullptr, nullptr);

	if (empty()) {
		head = np;
		tail = np;
	} else {
		np->next = head;
		head->back = np;
		head = np;
	}
	++size;
}

void List::addToBack(int n)
{
	Node *np = new Node(n, nullptr, nullptr);

	if (empty()) {
		head = np;
		tail = np;
	} else {
		np->back = tail;
		tail->next = np;
		tail = np;
	}
	++size;
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

int List::removeFront()
{
	Node *np = head;
	int retval = np->data;

	if (head->next) {
		head = head->next;
		head->back = nullptr;
	} else {
		tail = head = nullptr;
	}

	np->next = np->back = nullptr;
	delete np;
	--size;
	return retval;

}

int List::removeBack()
{
	Node *np = tail;
	int retval = np->data;

	if (tail->back) {
		tail = tail->back;
		tail->next = nullptr;
	} else {
		tail = head = nullptr;
	}
	np->next = np->back = nullptr;
	delete np;
	--size;
	return retval;
}

bool List::empty() const
{
	return size == 0;
}

int List::getSize() const
{
	return size;
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


