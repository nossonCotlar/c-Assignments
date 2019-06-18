// Main.cpp
// ATM stuffs
// C++
// Semester 2 Exercise 4 Question 1
// Nosson Cotlar - 524859733
// 5/15/19


#include <iostream>
#include <cmath>
#include <string>
#include "clock.h"
#include "account.h"

using namespace std;

enum action {
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};

action menu();
int findAccount(Account * bank, int size);
void printTransaction(Account a, action ac, Clock& c);
void getBalance(Account * bank, int size, Clock& c);
void checkDeposit(Account * bank, int size, Clock& c);
void cashWithdraw(Account * bank, int size, Clock& c);


int main() {
	const int size = 2;

	Clock c(8);

	Account bank[size];
	cout << "enter account number and code for 10 accounts:" << endl;

	for (int i = 0; i < size; i++) {
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++) {
				if (bank[i].getAccount() == bank[j].getAccount()) {
					throw "account number must be unique!";
				}
			}
		}
		catch (const char * exception) {
			cout << c << '\t';
			cout << "ERROR: " << exception << endl;
			i--;
		}

	}
	action ac = menu();

	while (ac) {
		try {
			switch (ac) {
			case balance:
				getBalance(bank, size, c);
				break;
			case withdraw:
				cashWithdraw(bank, size, c);
				break;
			case deposit:
				checkDeposit(bank, size, c);
				break;
			case sumDeposit:
				c += 60;
				printTransaction(bank[0], sumDeposit, c);
				break;
			case sumWithdraw:
				c += 60;
				printTransaction(bank[0], sumWithdraw, c);
				break;
			}
			ac = menu();
		}
		catch (const char * exception) {
			cout << c << '\t';
			cout << "ERROR: " << exception << endl;
			ac = menu();
		}
	}

	return 0;
}



action menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account * bank, int size) {
	int number, code;
	cout << "please enter account number: ";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccount() != number) {
		i++;
	}
	if (i == size) {
		//at this point it's safe to assume it has not been found
		throw "no such account number!";
	}
	cout << endl << "please enter the code: ";
	cin >> code;
	if (code < 999 || code > 9999) {
		throw "code must be of 4 digits!";
	}
	if (bank[i].getCode() == code) {
		return i;
	}
	else throw "wrong code";
}
void printTransaction(Account a, action ac, Clock& c) {
	cout << c << '\t';
	switch (ac) {
	case balance:
		cout << "account #: " << a.getAccount() << '\t';
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
		cout << "account #: " << a.getAccount() << '\t';
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case withdraw:
		cout << "account #: " << a.getAccount() << '\t';
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
	cout << endl;
}
void getBalance(Account * bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}
void checkDeposit(Account * bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check: ";
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], deposit, c);
}
void cashWithdraw(Account * bank, int size, Clock& c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw: ";
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], withdraw, c);
}