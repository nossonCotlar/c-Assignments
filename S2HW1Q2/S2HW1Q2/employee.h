//employee.h
#pragma once
#include <cstring>
class Employee {
public:
	//getters
	int getId();
	char* getName();
	float getWage();
	int getHours();
	int getOverHours();
	//setters
	void setId(int x);
	void setName(char* x);
	void setWage(float x);
	void setHours(int x);
	void setOverHours(int x);

	Employee();

	Employee(int id, char* name, float wage, int hours, int overHours);

	float salary();

private:
	int id;
	char name[20];
	float wage;
	int hours;
	int overHours;

};