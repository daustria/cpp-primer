#include "node.h"
#include <iostream>
using namespace std;

Node foo()
{
	return Node{5, new Node(7, nullptr)};
}

int main()
{

	Node n1{8, new Node(7, new Node(5, nullptr))};
	Node n2{26, new Node(-943, new Node(283, new Node(747, new Node(-503, nullptr))))};

	Node copy{n1}; //copy constructor
	copy = n2; //copy assignment operator
	
	Node copy2 = std::move(Node(5, nullptr)); // move constructor
//	Node copy2 = foo();
//	copy2 = foo(); //move assignment operator

	cout << copy << endl;
	cout << copy2 << endl;
	
}
