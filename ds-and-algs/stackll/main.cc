#include "istack.h"
#include "list.h"

int main()
{
	List ll;
	ll.addToFront(3);
	ll.addToFront(5);

	std::cout << ll << std::endl;

}
