#include <memory>
#include <iostream>

void foo(int *q)
{
	std::cout << "foo" << std::endl;
	std::shared_ptr<int> r(q); //two independent shared pointers now point to the same memory
} //r is destroyed 

int main()
{
	std::shared_ptr<int> p(new int(21)); //reference count is 1
	int *q = p.get(); 
	foo(q);

	std::cout << *p << std::endl; //p points to invalid memory
}
