// Main.cpp
// STL stuffs
// C++
// Semester 2 Exercise 9 Question 1
// Nosson Cotlar - 524859733
// 6/18/19


#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include "Student.h"
#include "Degree.h"


using namespace std;
void add(std::vector<Student *>& vec);
void milga(std::vector<Student *>& vec);
Student * mostResearchHours(std::vector<Student *>& vec);
void printVec(std::vector<Student *>& vec);

enum option {
	stop, 
	addNewStudent, 
	milgaList, 
	mostResearch, 
	countMilgaBA, 
	noResearchMA, 
	overheadStudent, 
	removePHDFailers
};

//So here's the deal. Using a vector of Abstract classes doesn't work
//when I make the class not abstract, and I try to operate on an element of the vector, 
//it doesn't operate on it like it were a child class, rather it always treats it as the parent
//so I guess for now I'll make a vector of pointers so I don't run into this issue

int main() {
	
	std::vector<Student *> studentVec;


	
	int option;
	cout << "enter 0-7" << endl;
	cin >> option;
	while (option != stop) {
		switch (option) {
		case addNewStudent:
			add(studentVec);
			break;
		case milgaList:
			milga(studentVec);
			break;
		case mostResearch:
			Student * s;
			s = mostResearchHours(studentVec);
			cout << "PHD student with most research hours: ";
			cout << s->getFirstName() << ' ' << s->getLastName() << endl;
			break;
		case countMilgaBA:
			int sum;
			sum = 0;
			for (Student *& t : studentVec) {
				if (t->studType() == "BA" && t->milga()) sum++;
			}
			cout << "#BA students for milga: " << sum << endl;
			break;
		case noResearchMA:
			for (Student *& t : studentVec) {
				if (t->studType() == "MA" && !t->getResearch()) t->print();
			}
			break;
		case overheadStudent:
			for (Student *& t : studentVec) {
				if (t->getCourses() > 15) {
					cout << "there is a student that takes more than 15 courses" << endl;
					break;
				}
			}
			cout << "no student takes more than 15 courses" << endl;
			break;
		case removePHDFailers:
			for (int i = 0; i < studentVec.size(); i++) {
				if (studentVec[i]->studType() == "PHD" && studentVec[i]->getCourses() == 0) {
					studentVec.erase(studentVec.begin() + i);
					i--;
				}
			}
			printVec(studentVec);
			break;
		}
		//printVec(studentVec);
		cout << "enter 0-7" << endl;
		cin >> option;
	}



	return 0;
}


void add(std::vector<Student *>& vec) {
	int choice, id, courses, hours;
	std::string first, last;
	bool research;
	float * grades = nullptr;
	cout << "enter 1 to add a BA student" << endl;
	cout << "enter 2 to add a MA student" << endl;
	cout << "enter 3 to add a PHD student" << endl;
	cin >> choice;

	cout << "enter id, first name, last name and number of Courses" << endl;
	cin >> id >> first >> last >> courses;
	if (choice != 3) { //only if the degree isn't PHD (PHD dont care about grades)
		grades = new float[courses];
		cout << "enter " << courses << " grades" << endl;
		
		for (int i = 0; i < courses; i++) {
			cin >> grades[i];
		}
	}
	if (choice == 2) {
		cout << "enter 1 if the student does research and 0 if not" << endl;
		cin >> research;
	}
	if (choice == 3) {
		cout << "enter number of research hours" << endl;
		cin >> hours;
	}
	
	Student * student = nullptr;

	switch (choice) {
	case 1:
		student = new BA(id, courses, courses, grades, first, last);
		break;
	case 2:
		student = new MA(id, courses, courses, grades, research, first, last);
		break;
	case 3:
		student = new PHD(id, courses, hours, first, last);
		break;
	default: 
		cout << "ERROR" << endl;
		break;
	}
	vec.push_back(student);
}

void milga(std::vector<Student *>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i]->milga()) vec[i]->print();
	}
}

Student * mostResearchHours(std::vector<Student *>& vec) {
	Student * most = NULL;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i]->studType() == "PHD") {
			if (most == NULL) { //if there was no pevious student, set the current one as "most"
				most = vec[i];
				continue; //and go back to the for loop
			}
			if (vec[i]->getHours() > most->getHours()) {
				most = vec[i];
			}
		}
	}
	return most;
}

void printVec(std::vector<Student *>& vec) {
	for (Student *& t : vec) {
		t->print();
		cout << endl;
	}
}