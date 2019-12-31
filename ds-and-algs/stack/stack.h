#ifndef STACK_H
#define STACK_H
#include "list.h"

template <typename T>
class Stack
{

	template <typename U>
	friend std::ostream &operator<<(std::ostream &, const Stack<U> &);
	public:
		void push(const T &t);
		T pop();
		const T &peek();
		bool empty();

	private:
		List<T> ll;
};

template <typename T>
std::ostream &operator<<(std::ostream &, const Stack<T> &);

#include "stack.tt" 
#endif //STACK_H
