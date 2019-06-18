// Main.cpp
// Circle class
// Introduction to Computer Science
// Semester 2 Exercise 1 Question 3
// Nosson Cotlar
// 3/12/19

#include <iostream>
#include <cstring>
#include "circle.h"

using namespace std;


int main() {
	Circle circles[3];

	cout << "enter the center point and radius of 3 circles" << endl;
	for (int i = 0; i < 3; i++) {
		float a, b, c;
		cin >> a >> b >> c;
		Point temp(a, b);
		circles[i].setCenter(temp);
		circles[i].setRad(c);
	}

	cout << "area A:" << circles[0].area()
		<< " B:" << circles[1].area()
		<< " C:" << circles[2].area()
		<< endl
		<< "hekef A:" << circles[0].circ()
		<< " B:" << circles[1].circ()
		<< " C:" << circles[2].circ()
		<< endl;

	 unsigned int countA = 0, countB = 0, countC = 0;

	while (true) {
		float x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		Point temp(x, y); //not sure if itll work multiple times
		if (circles[0].location(temp) == -1 || circles[0].location(temp) == 0) countA++;
		if (circles[1].location(temp) == -1 || circles[1].location(temp) == 0) countB++;
		if (circles[2].location(temp) == -1 || circles[2].location(temp) == 0) countC++;
	}

	cout << "num of points in circle A:" << countA 
		<< " B:" << countB 
		<< " C:" << countC 
		<< endl;

	//system("pause");
	return 0;
}



/*



*/
