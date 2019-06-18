// Main.cpp
// String stuffs
// Introduction to Computer Science
// Semester 2 Exercise 3 Question 4
// Nosson Cotlar - 524859733
// 5/14/19


#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
	string input;

	getline(cin, input);

	size_t location = input.find(' '); //set location to first instance of character ' '
	while (location != string::npos) { //while it still can be found
		input.replace(location, 1, "*"); //replace it with '*'
		location = input.find(' '); //try to find it again
	}
	cout << input << endl;

	location = input.find_last_of("*"); //find last asterisk
	input.replace(location + 1, input.length() - location, "#!!@1234"); //replace the word after the last asterisk with the given string
	cout << input << endl;

	location = input.find_first_of("*"); //find first asterisk
	while (location != string::npos) {
		input.erase(0, location + 1); //erase the current word
		cout << input << endl;
		location = input.find_first_of("*"); //try to find again
	}
	

	return 0;
}