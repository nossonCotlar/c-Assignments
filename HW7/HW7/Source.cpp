// HW7Q3.cpp
// sorts top and bottom triangles of a 100x100 matrix seperately
// Introduction to Computer Science
// Exercise 7 Question 3
// Nosson Cotlar
// 11/27/18

#include <iostream>
#include <cmath>
using namespace std;

void cinLoad(char x[], int size);
void printList(const char x[], int size);
void printMatrix(const char x[][5], const int size, const int amount);
void sort(char x[][5], int size);
void swap(char x[], char y[]);

int main() {
	const int N = 10, len = 5;
	char words[N][len];

	cout << "enter 10 words" << endl;
	for (int i = 0; i < N; i++) {
		cinLoad(words[i], len);
	}

	sort(words, 10);

	cout << "after sorting: " << endl;
	printMatrix(words, N, len);

	system("pause");
	return 0;
}

void cinLoad(char x[], int size) { //this cinLoad inputs strictly descending and nonrepeating elements
	for (int i = 0; i < size; i++) { //inputs into the array 
		cin >> x[i];
	}
	
}

void sort(char x[][5], int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			for (int q = 0; q < 5; q++) {
				if (x[j][q] > x[j + 1][q]) {
					swap(x[j], x[j + 1]);
					break;
				}
			}
		}
	}
}

void swap(char x[], char y[]) {
	char temp[5];

	for (int i = 0; i < 5; i++) {
		temp[i] = x[i];
	}
	for (int i = 0; i < 5; i++) {
		x[i] = y[i];
	}
	for (int i = 0; i < 5; i++) {
		y[i] = temp[i];
	}
}

void printList(const char x[], const int size) {
	for (int i = 0; i < size; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

void printMatrix(const char x[][5], const int size, const int amount) {
	for (int i = 0; i < amount; i++) {
		printList(x[i], size);
	}
}

/*



*/

