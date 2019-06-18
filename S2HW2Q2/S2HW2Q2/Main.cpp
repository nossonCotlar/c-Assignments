// Main.cpp
// Date class with Op overloading
// Introduction to Computer Science
// Semester 2 Exercise 2 Question 2
// Nosson Cotlar - 524859733
// 3/31/19

#include "date.h"
#include <iostream>

using namespace std;

int main() {
	unsigned int x, y, z;
	char a;
	cout << "Enter a date" << endl;
	cin >> x >> a >> y >> a >> z;
	Date date(x, y, z);
	date.print();
	Date t(1, 1, 1970);

	int code;
	do {
		cout << "What do you want to do" << endl;
		cin >> code;
		switch (code) {
		case 1:
			cout << "Enter a date" << endl;
			cin >> x >> a >> y >> a >> z;
			date.setDate(x, y, z);
			date.print();
			break;
		case 2:
			(++date).print();
			break;
		case 3:
			(date++).print();
			break;
		case 4:
			cout << "Enter #days" << endl;
			unsigned int num;
			cin >> num;
			(date += num).print();
			break;
		case 5:
			cout << "Enter a date" << endl;
			cin >> x >> a >> y >> a >> z;
			t.setDate(x, y, z);
			if (date > t) {
				cout << ">: true" << endl;
			}
			else cout << ">: false" << endl;
			break;
		case 6:
			cout << "Enter a date" << endl;
			cin >> x >> a >> y >> a >> z;
			t.setDate(x, y, z);
			if (date < t) {
				cout << "<: true" << endl;
			}
			else cout << "<: false" << endl;
			break;
		case 7:
			cout << "Enter a date" << endl;
			cin >> x >> a >> y >> a >> z;
			t.setDate(x, y, z);
			if (date == t) {
				cout << "==: true" << endl;
			}
			else cout << "==: false" << endl;
			break;
		}
	} while (code != -1);

	return 0;
}