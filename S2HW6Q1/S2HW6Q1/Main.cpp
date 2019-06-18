// Main.cpp
// Cyclical Linked List stuffs
// C++
// Semester 2 Exercise 6 Question 1
// Nosson Cotlar - 524859733
// 5/17/19


#include <iostream>
#include <cmath>
#include <string>
#include "RoundList.h"

using namespace std;

enum CHOICES {
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY
};

int main() {
	RoundList ls1;

	int choice;

	cout << "Enter your choice: ";
	cin >> choice;

	while (choice != EXIT) {
		int num;
		switch (choice) {
		case ADD:
			cout << "Enter 5 numbers: ";
			for (int i = 0; i < 5; i++) {
				cin >> num;
				ls1.add(num);
			}
			break;
		case ADD_TO_END:
			cout << "Enter 5 numbers: ";
			for (int i = 0; i < 5; i++) {
				cin >> num;
				ls1.addToEnd(num);
			}
			break;
		case REMOVE_FIRST:
			ls1.removeFirst();
			break;
		case SEARCH:
			cout << "Enter a number: ";
			cin >> num;
			cout << ls1.search(num) << endl;
			break;
		case CLEAR:
			ls1.clear();
			break;
		case EMPTY:
			if (ls1.isEmpty()) {
				cout << "Empty" << endl;
			}
			else cout << "Not empty" << endl;
			break;
		default: cout << "ERROR!" << endl;
			break;
		}
		//ls1.print(cout);
		cout << "Enter your choice: ";
		cin >> choice;
	}


	return 0;
}