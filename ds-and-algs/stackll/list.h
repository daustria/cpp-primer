#ifndef LST_H
#define LST_H
#include <iostream>

class List
{
	struct Node;
	Node *head = nullptr;
	Node *tail = nullptr;
	int size = 0;

	public:

		~List();
		class Iterator{
			public:
				Iterator(Node *);
				Iterator operator++();
				bool operator!=(const Iterator &);
				int &operator*();
			private:
				Node *p;
		};

		Iterator begin() const;
		Iterator end() const;

		void addToFront(int);
		void addToBack(int);

		int removeFront();
		int removeBack();

		int ith(int);
		int remove(int);
		bool empty() const;
		int getSize() const;
};

std::ostream &operator<<(std::ostream &, const List &);
#endif //LST_H
