// Main.cpp
// Vector class  
// Introduction to Computer Science
// Semester 2 Exercise 3 Question 2
// Nosson Cotlar - 524859733
// 5/14/19


#include <iostream>
#include <cmath>
#include "vector.h"

using namespace std;
enum options {
stop, assignment, isEqual, mult, add, clear, delLast
// 0 1:= 2:== 3:* 4:+ 5 6
};

int main() {
	Vector v1(10),v2(10),v3;
	for (int i = 1; i <= 4; i++) {
		v1.insert(i);
		v2.insert(i + 4);
	}
	int choice;
	cout << "enter your choice 0-6" << endl;
	cin >> choice;
	while (choice) {
		switch (choice) {
		case assignment:
			v3 = v1;
			break;
		case isEqual:
			if (v1 == v2) cout << "v1==v2" << endl;
			else cout << "v1!=v2" << endl;
			break;
		case mult: 
			cout << "v1*v2=" << v1 * v2 << endl;
			break;
		case add:
			v3 = v1 + v2;
			break;
		case clear:
			v1.clear();
			break;
		case delLast:
			v2.delLast();
			break;
		default:
			cout << "ERROR" << endl;
		}
		v1.print();
		v2.print();
		v3.print();
		cout << "enter your choice 0-6" << endl;
		cin >> choice;
	}

	return 0;
}