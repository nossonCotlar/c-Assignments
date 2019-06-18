// Main.cpp
// Cyclical Linked List stuffs
// C++
// Semester 2 Exercise 6 Question 1
// Nosson Cotlar - 524859733
// 5/17/19


#include <iostream>
#include <cmath>
#include <string>
#include "Polygon.h"
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;



int main() {
	int num;
	Polygon * poly1, * poly2;

	cout << "enter number of sides for polygon 1: ";
	cin >> num;
	if (num == 3) {
		int x, y, z;
		cout << "enter sides for polygon: ";
		cin >> x >> y >> z;
		poly1 = new Triangle(x, y, z);
	}
	else if (num == 4) {
		int x, y;
		cout << "enter sides for polygon: ";
		cin >> x >> y;
		poly1 = new Rectangle(x, y);
	}
	else poly1 = new Polygon(num);

	cout << "enter number of sides for polygon 2: ";
	cin >> num;

	if (*poly1 == num) {
		if (num == 3) {
			int x, y, z;
			cout << "enter sides for polygon: ";
			cin >> x >> y >> z;
			poly2 = new Triangle(x, y, z);
		}
		else if (num == 4) {
			int x, y;
			cout << "enter sides for polygon: ";
			cin >> x >> y;
			poly2 = new Rectangle(x, y);
		}
		else poly2 = new Polygon(num);

		if (*poly1 == *poly2) {
			cout << "equal" << endl;
		}
		else cout << "not equal" << endl;
	}
	else cout << "not equal" << endl;
	

	return 0;
}