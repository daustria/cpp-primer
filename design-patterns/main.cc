#include <iostream>
#include "person.h"
#include "personobserver.h"
int main()
{
	Person dominic{21};
	PersonObserver obs1;	
	PersonObserver obs2;

	dominic.suscribe(&obs1);
	dominic.suscribe(&obs2); 


	std::cout << " It's Dominic's Birthday! " << std::endl;
	dominic.setAge(22);
}
