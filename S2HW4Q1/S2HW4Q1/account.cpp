#include "account.h"

Account::Account() {
	accountNumber = 0;
	code = 0;
	balance = 0;
}
Account::Account(int x, int y, int z) {
	accountNumber = x;
	code = y;
	balance = z;
}
Account::Account(const Account& x) {
	accountNumber = x.getAccount();
	code = x.getCode();
	balance = x.getBalance();
}
int Account::getAccount() const { return accountNumber; }
int Account::getCode() const { return code; }
int Account::getBalance() const { return balance; }
void Account::setBalance(const int x) {
	if (x < -6000) throw "cannot have less than -6000 NIS!";
	balance = x;
}
void Account::withdraw(int nis) {
	if (nis > 2500) throw "cannot withdraw more than 2500 NIS!";
	setBalance(getBalance() - nis);
	Account::sumWithdraw += nis;
}
void Account::deposit(int nis) {
	if (nis > 10000) throw "cannot deposit more than 10000 NIS!";
	setBalance(getBalance() + nis);
	Account::sumDeposit += nis;
}
std::istream& operator>>(std::istream& stream, Account& x) {
	int number, password;
	stream >> number;
	stream >> password;
	if (password < 999 || password > 9999) {
		throw "code must be of 4 digits!";
	}
	//this method is a friend so it can access these bois
	x.accountNumber = number;
	x.code = password;
	return stream;
}
int Account::getSumWithdraw() { return Account::sumWithdraw; }
int Account::getSumDeposit() { return Account::sumDeposit; }

int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;