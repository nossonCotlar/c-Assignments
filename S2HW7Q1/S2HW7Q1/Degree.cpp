#include "Degree.h"

//========== BA ==========
BA::BA(int id, int courses, int size, float * x, std::string& first, std::string& last) : Student(id, courses, first, last) {
	this->size = size;
	grades = new float[size];
	setGrades(x);
}
void BA::print() const {
	std::cout << "ID: " << getID() << std::endl;
	std::cout << "first name: " << getFirstName() << std::endl;
	std::cout << "last name: " << getLastName() << std::endl;
	std::cout << "num courses: " << getCourses() << std::endl;

	std::cout << "grades: ";
	for (int i = 0; i < getSize(); i++) {
		std::cout << getGrades()[i] << ' ';
	}
	std::cout << std::endl;
}
float BA::avg() const {
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += grades[i];
	}
	return sum / size;
}
int BA::getSize() const { return size; }
float * BA::getGrades() const { return grades; }
void BA::setGrades(const float * x) {
	for (int i = 0; i < getSize(); i++) {
		grades[i] = x[i];
	}
}
bool BA::milga() const { return getCourses() >= 10 && avg() > 95; }

//========== MA ==========
MA::MA(int id, int courses, int size, float * x, bool research, std::string& first, std::string& last) : BA(id, courses, size, x, first, last) {
	this->research = research;
}
void MA::print() const {
	std::cout << "ID: " << getID() << std::endl;
	std::cout << "first name: " << getFirstName() << std::endl;
	std::cout << "last name: " << getLastName() << std::endl;
	std::cout << "num courses: " << getCourses() << std::endl;

	std::cout << "grades: ";
	for (int i = 0; i < getSize(); i++) {
		std::cout << getGrades()[i] << ' ';
	}
	std::cout << std::endl;

	std::cout << "research: ";
	if (research) std::cout << "yes";
	else std::cout << "no";

	std::cout << std::endl;
}
bool MA::milga() const { return getCourses() >= 7 && avg() > 90 && research; }

//========== PHD ==========
PHD::PHD(int id, int courses, int hours, std::string& first, std::string& last) : Student(id, courses, first, last) {
	this->hours = hours;
}
void PHD::print() const {
	std::cout << "ID: " << getID() << std::endl;
	std::cout << "first name: " << getFirstName() << std::endl;
	std::cout << "last name: " << getLastName() << std::endl;
	std::cout << "num courses: " << getCourses() << std::endl;
	std::cout << "hours: " << hours << std::endl;
}
bool PHD::milga() const { return getCourses() >= 2 && hours > 25; }