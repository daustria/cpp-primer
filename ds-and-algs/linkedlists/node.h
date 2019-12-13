#ifndef NODE_H
#define NODE_H
#include <iostream>

class LinkedList;

class Node
{
	friend class LinkedList;

	public:
		Node();
		Node(int val, Node *n = nullptr);
		Node(const Node &);
		Node &operator=(const Node &);
		Node(Node &&);
		Node &operator=(Node &&);
		~Node();

		int value() const;
		const Node *nextNode() const;

		void setNext(Node *np);
		void setVal(const int);

	private:
		int data;
		Node *next;
};

std::ostream &operator<<(std::ostream &, const Node &n);

#endif //NODE_H
