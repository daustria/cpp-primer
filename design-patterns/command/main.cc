#include "bankaccount.h"
#include "accountcommand.h"
int main()
{
	BankAccount acc;
	BankAccountCommand deposit(acc, BankAccountCommand::Action::deposit, 100);
	deposit.call();
}
