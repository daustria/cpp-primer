#ifndef LST_H
#define LST_H
#include <iostream>

template <typename T> class List
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
				T &operator*();
			private:
				Node *p;
		};

		Iterator begin() const;
		Iterator end() const;

		void addToFront(const T &);
		void addToBack(const T &);

		T &removeFront();
		T &removeBack();

		const T &ith(int);
		const T &remove(int);
		bool empty() const;
		int getSize() const;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const List<T> &);

#include "list.tt"
#endif //LST_H
