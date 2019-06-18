// Main.cpp
// String class extention 
// Introduction to Computer Science
// Semester 2 Exercise 3 Question 1
// Nosson Cotlar - 524859733
// 5/12/19


#include <iostream>
#include <cmath>
#include "string.h"

using namespace std;

int main() {
	char temp[200];
	int num;

	cin >> temp;
	String a(temp);
	cin >> temp;
	String b(temp);

	cin >> num;

	if (a < b) {
		cout << "a<b" << endl;
	}
	else if (a > b) {
		cout << "a>b" << endl;
	}
	else if (a == b) {
		cout << "a=b" << endl;
	}
	b.insert(num, a);
	b.print();
	
	

	return 0;
}