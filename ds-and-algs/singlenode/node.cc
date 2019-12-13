#include "node.h"
#include <iostream>

Node::Node(): data(0), next(nullptr) {}

Node::Node(int val, Node *np): data(val), next(np) {}

Node::Node(const Node &rhs): data(rhs.data), next(rhs.next ? new Node(*rhs.next) : 0) {}

Node &Node::operator=(const Node &rhs)
{

	if (this != &rhs)
	{
		delete next;
		data = rhs.data;
		next = rhs.next ? new Node(*rhs.next) : 0;
	}

	return *this;
}
Node::~Node()
{
	delete next;
}

Node::Node(Node &&rhs): data(rhs.data), next(rhs.next) 
{
	std::cout << "move constructor " << std::endl;

}

Node &Node::operator=(Node &&rhs) 
{
	std::cout << "move assginment" << std::endl;
	if (this != &rhs)
	{
		data = rhs.data;
		Node *temp = next;
		next = rhs.next;
		rhs.next = temp;
	}

	return *this;
}


int Node::value() const
{
	return data;
}

const Node *Node::nextNode() const
{
	return next;
}


void Node::setVal(const int val)
{
	data = val;
}

void Node::setNext(Node *np)
{
	next = np;
}

std::ostream &operator<<(std::ostream &out, const Node &n)
{
	out << n.value();
	const Node *current = n.nextNode();

	while(current)
	{
		out << ',' << current->value();
		current = current->nextNode();
	}

	return out;
}


