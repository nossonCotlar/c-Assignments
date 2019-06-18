// Main.cpp
// Polymorphism
// C++
// Semester 2 Exercise 7 Question 1
// Nosson Cotlar - 524859733
// 5/19/19


#include <iostream>
#include <cmath>
#include <string>
#include "Student.h"
#include "Degree.h"


using namespace std;

void printStudents( Student ** x, int size);


int main() {
	const int amount = 7;

	string first, last;

	float grades1[] = { 90, 100, 90 };
	first = "abe";
	last = "avraham";
	BA b1(123, 3, 3, grades1, first, last);

	float grades2[] = { 100, 100, 90, 100, 90, 100, 90, 100, 90, 100 };
	first = "yitzhak";
	last = "avrahamson";
	BA b2(234, 10, 10, grades2, first, last);

	float grades3[] = { 90, 100, 90, 100, 90, 100, 90 };
	first = "yaakov";
	last = "jacobson";
	MA m1(345, 7, 7, grades3, false, first, last);

	float grades4[] = { 90, 100, 90, 100, 90, 100, 90 };
	first = "sara";
	last = "emanu";
	MA m2(456, 7, 7, grades4, true, first, last);

	first = "rivka";
	last = "imanu";
	PHD p1(567, 1, 30, first, last);

	first = "rachel";
	last = "jacobs";
	PHD p2(678, 2, 20, first, last);

	first = "leah";
	last = "jacobs";
	PHD p3(789, 2, 30, first, last);

	Student * students[] = { &b1, &b2, &m1, &m2, &p1, &p2, &p3 };

	printStudents(students, amount);
	

	return 0;
}

void printStudents(Student ** x, int size) {
	for (int i = 0; i < size; i++) {
		if (x[i]->milga()) x[i]->print();
	}
}