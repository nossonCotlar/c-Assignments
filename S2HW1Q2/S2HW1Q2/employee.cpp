//employee.cpp

#include "employee.h"
#include <cstring>

//getters
int Employee::getId() { return id; }
char* Employee::getName() { return name; }
float Employee::getWage() { return wage; }
int Employee::getHours() { return hours; }
int Employee::getOverHours() { return overHours; }
//setters
void Employee::setId(int x) { id = x; }
void Employee::setName(char* x) { strcpy_s(name, x); }
void Employee::setWage(float x) { wage = x; }
void Employee::setHours(int x) { hours = x; }
void Employee::setOverHours(int x) { overHours = x; }

Employee::Employee() {
	id = 0;
	strcpy_s(name, "John Doe");
	wage = 0;
	hours = 0;
	overHours = 0;
}

Employee::Employee(int id, char* name, float wage, int hours, int overHours) {
	this->id = id;
	strcpy_s(this->name, name);
	this->wage = wage;
	this->hours = hours;
	this->overHours = overHours;
}

float Employee::salary() {
	return (float(hours) * wage) + (float(overHours) * 1.5 * wage);
}