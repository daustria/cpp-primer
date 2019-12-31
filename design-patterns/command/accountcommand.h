#ifndef BANK_COMMAND_H
#define BANK_COMMAND_H
#include "bankaccount.h"
#include "command.h"

class BankAccountCommand : public Command
{
	public:

		enum Action {deposit, withdraw};

		BankAccountCommand(BankAccount &account, const Action action, const int amount): account(account), action(action), amount(amount) {}

		void call() const override
		{
			switch(action)
			{
				case deposit:
					account.deposit(amount);
					break;
				case withdraw:
					account.withdraw(amount);
					break;	
			}
		}
	private:
		BankAccount &account;
		Action action;
		int amount;
};
#endif //BANK_CMOMAND_H
