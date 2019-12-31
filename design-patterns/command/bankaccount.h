#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <iostream>
class BankAccount
{
	public:
		void deposit(int amount)
		{
			balance += amount;
			std::cout << "deposited " << amount << std::endl;
			std::cout << "balance is now " << balance << std::endl;
		}

		void withdraw(int amount)
		{
			if(balance - amount >= overdraftLimit)
			{
				balance -= amount;
				std::cout << "withdrew " << amount << std::endl;
			}
		}
	private:
		int balance = 0;
		int overdraftLimit = -500;

};
#endif //BANK_ACCOUNT_H
