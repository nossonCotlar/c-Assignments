// HW4Q4.cpp
// sums the expression: (((-1)^(n-1))/ 2 * n - 1) * X ^ (2*n - 1)
// Introduction to Computer Science
// Exercise 4 Question 4
// Nosson Cotlar
// 11/4/18

#include <iostream>
#include <time.h>
using namespace std;

int main() {
	int base, num;
	float parenth = 0, result = 0, sum = 0;
	cout << "enter 2 numbers: " << endl;
	cin >> base >> num; //read value
	while (num <= 0) { //loops while number is illegal
		cout << "ERROR" << endl;
		cin >> num; //re-reads input
	}

	for (int count = 1; count <= num; count++) { //counts which itteration this is, and uses "count" as "n" in the math expresison


		float neg = 1; //(this is set to a float so the later operations will go smoothely)
		for (int i = 0; i < count - 1; i++) { //determines whether this term will be negative by bringing it to the power of n-1
			neg = neg * -1;
		}

		parenth = neg / (2 * count - 1); //the numbers in the parantheses in the math expression are now computed

		float x = 1;
		for (int i = 0; i < 2 * count - 1; i++) { //the X in the expression is now brought to the power of 2n-1
			x = x * base;
		}

		result = parenth * x; //the individual result is computed (specific to each iteration)
		sum += result; //result is added to sum. This process repeats until all the n-s have been satisfied 

	}
	cout << sum << endl; //output total sum

	//system("pause");
}
/*
enter 2 numbers:
 3
 2
-6

enter 2 numbers:
 3
 -2
ERROR
 -42
ERROR
 2
-6
*/