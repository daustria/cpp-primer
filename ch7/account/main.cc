#include <string>
#include <iostream>
using namespace std;


//Exercise 7.56
/*
 *A static class member is class member seperate from the object, declared
 using the keyword static. It is not tied to the object.

 The main advantage of using static functions and members, is for
 efficiency. Multiple instances of a class can use one member seperate
 from the object rather than multiple members that all have the same value.
 */

//Exercise 7.57
class Account
{
	public:
		//member functions have access to static members
		void calculate () { amount += amount*interestRate; }
		static double rate() { return interestRate; }
		static void rate(double);
	private:
		string owner;
		double amount;
		//cannot initialize a static member inside the class.
		static double interestRate;
		//cannot be declared as const. not bound to object.
		static double initRate();
};

//the static keyword is only used in the declaration inside the class body
void Account::rate(double newRate)
{
	interestRate = newRate;
}

double Account::initRate()
{
	return 0;
}

//Define and initialize a static class member.
//Like any other member definition, interestRate has access to private members.
double Account::interestRate = initRate();

int main()
{
	Account ac1;
	Account *ac2 = &ac1;
	Account::rate(5.7);
	cout << ac1.rate() << endl;
}
