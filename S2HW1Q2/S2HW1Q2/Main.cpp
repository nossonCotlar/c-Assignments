// Main.cpp
// Rational class
// Introduction to Computer Science
// Semester 2 Exercise 1 Question 2
// Nosson Cotlar
// 3/11/19

#include <iostream>
#include <cstring>
#include "employee.h"

using namespace std;


int main() {
	Employee boi[20];
	int id;
	char name[20];
	float wage;
	int hours;
	int overHours;

	cout << "enter details, to end enter 0" << endl;
	int i = 0;
	while (true) {
		cin >> id;
		if (id == 0) break;
		cin >> name >> wage >> hours >> overHours;
		boi[i].setId(id);
		boi[i].setName(name);
		boi[i].setWage(wage);
		boi[i].setHours(hours);
		boi[i].setOverHours(overHours);
		if (id < 0 || wage < 0 || hours < 0 || overHours < 0) { //check for invalids
			cout << "ERROR" << endl;
		} 
		else i++; //only increment if data was valid

	}


	int maxS = 0, maxH = 0;
	for (int j = 0; boi[j + 1].getId() != 0; j++) {
		if (boi[maxS].salary() < boi[j + 1].salary()) {
			maxS = j + 1;
		}
		if (boi[maxH].getHours() + boi[maxH].getOverHours() < boi[j + 1].getHours() + boi[j + 1].getOverHours()) {
			maxH = j + 1;
		}
	}

	cout << "highest salary: " << boi[maxS].getId() << " " << boi[maxS].getName() << endl;
	cout << "hardest worker: " << boi[maxH].getId() << " " << boi[maxH].getName() << endl;

	//system("pause");
	return 0;
}



/*



*/
