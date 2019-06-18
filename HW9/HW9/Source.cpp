// HW9Q2.cpp
// reverses a string sentence
// Introduction to Computer Science
// Exercise 9 Question 2
// Nosson Cotlar
// 12/24/18

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

void printList(const int x[], int size);
void swap(char& x, char& y);
int indvGap(const char text[], char x, char y);
int gap(const char text[], const char word[]);

int main() {
	char text[80], word[80];
	cout << "enter text: " << endl;
	cin.getline(text, 80);
	cout << "enter word: " << endl;
	cin.getline(word, 80);

	cout << "size of jump: " << gap(text, word) << endl;

	//system("pause");
	return 0;
}

int indvGap(const char text[], char x, char y) {
	int count = -1;

	for (int i = 0; text[i] != NULL; i++) {

		if (text[i] == x) {

			for (int j = i; text[j] != y; j++) {

				if (text[j] == NULL) return -1;
				count++;
				if (text[j + 1] == y) return count;

			}
		}
	}
	return -1;
}

int gap(const char text[], const char word[]) {
	int a;


	a = indvGap(text, word[0], word[1]);

	return a;

}

void swap(char& x, char& y) {
	char a = y;
	y = x;
	x = a;

}

void printList(const int x[], int size) {
	for (int i = 0; i < size; i++) {
		cout << x[i] << " ";
	}
	cout << endl;
}

/*



*/

