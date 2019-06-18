// Main.cpp
// Vector class  
// Introduction to Computer Science
// Semester 2 Exercise 3 Question 3
// Nosson Cotlar - 524859733
// 5/14/19


#include <iostream>
#include <cmath>
#include "poly.h"

using namespace std;

int main() {
	int n;
	float * input;
	cin >> n;

	input = new float[n];
	for (int i = 0; i < n * 2; i++) {
		cin >> input[i];
	}
	
	Poly poly(n, input);
	float perimeter = poly.permimeter();
	cout << perimeter << endl;


	return 0;
}