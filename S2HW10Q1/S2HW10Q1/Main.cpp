// Main.cpp
// STL stuffs
// C++
// Semester 2 Exercise 10 Question 1
// Nosson Cotlar - 524859733
// 6/18/19


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

	int a[] = { 1, 2, 3, 4, 5, 10 };
	int b[6];

	fstream f;
	f.open("test.bin", ios::out|ios::binary);

	if (f) {

		f.write(a, );

		f.close();
	}

	return 0;
}
