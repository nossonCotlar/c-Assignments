// Main.cpp
// Rational class with Op overloading
// Introduction to Computer Science
// Semester 2 Exercise 2 Question 1
// Nosson Cotlar - 524859733
// 3/31/19

#include "rational.h"

using namespace std;

int main() {
	int x, y;
	char z;
	cout << "Enter two rational numbers" << endl;

	cout << "a: ";
	cin >> x >> z >> y;
	Rational a(x, y);

	cout << endl << "b: ";
	cin >> x >> z >> y;
	Rational b(x, y);

	cout << endl << "b-a: ";
	(b - a).print();

	cout << "a!=b: ";
	if (a != b) cout << "true" << endl;
	else cout << "false" << endl;

	cout << "a<b: ";
	if (a < b) cout << "true" << endl;
	else cout << "false" << endl;

	cout << "a>b: ";
	if (a > b) cout << "true" << endl;
	else cout << "false" << endl;

	cout << "a>=b: ";
	if (a >= b) cout << "true" << endl;
	else cout << "false" << endl;

	cout << "a++: ";
	(a++).print();
	cout << "--a: ";
	(--a).print();
	cout << "a--: ";
	(a--).print();

	b = a; //assign

	cout << endl << "b-a: ";
	(b - a).print();

	cout << "b/a: ";
	(b / a).print();

	cout << "a!=b: ";
	if (a != b) cout << "true" << endl;
	else cout << "false" << endl;

	cout << "a<b: ";
	if (a < b) cout << "true" << endl;
	else cout << "false" << endl;

	cout << "a>=b: ";
	if (a >= b) cout << "true" << endl;
	else cout << "false" << endl;


	return 0;
}