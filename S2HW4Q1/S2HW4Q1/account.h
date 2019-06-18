#pragma once
#include <iostream>
#include <string>

class Account {
public:
	Account();
	Account(int x, int y, int z);
	Account(const Account& x);

	int getAccount() const;
	int getCode() const;
	int getBalance() const;
	void setBalance(const int x);

	void withdraw(int nis);
	void deposit(int nis);

	friend std::istream& operator>>(std::istream& stream, Account& x);

	static int getSumWithdraw();
	static int getSumDeposit();

private:
	int accountNumber, code, balance;
	static int sumWithdraw, sumDeposit;
};