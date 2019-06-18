#pragma once
#include <iostream>
#include <string>

class Student {
public:
	Student(int id, int courses, std::string& first, std::string& last) { 
		//defining it here because I don't want a .cpp file just for this 
		this->id = id;
		this->courses = courses;
		firstName = first;
		lastName = last;
	}
	
	virtual bool milga() const = 0;
	virtual void print() const = 0;

	virtual int getID() const { return id; }
	virtual int getCourses() const { return courses; }
	virtual std::string getFirstName() const { return firstName; }
	virtual std::string getLastName() const { return lastName; }

private:
	int id;
	int courses;
	std::string firstName, lastName;
};