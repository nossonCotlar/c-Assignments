#include "date.h"
#include <iostream>
using namespace std;

Date::Date(unsigned int x = 1, unsigned int y = 1, unsigned int z = 1970) { 
	if (x >= 1 && x <= 30) day = x;
	else {
		cout << "ERROR day" << endl;
		day = 1;
	}
	if (y >= 1 && y <= 12) month = y;
	else {
		cout << "ERROR month" << endl;
		month = 1;
	}
	if (z >= 1970 && z <= 2099) year = z;
	else {
		cout << "ERROR year" << endl;
		year = 1970;
	}
}

Date::Date(const Date& x) {
	day = x.getD();
	month = x.getM();
	year = x.getY();
}

unsigned int Date::getD() const { return day; }
unsigned int Date::getM() const { return month; }
unsigned int Date::getY() const { return year; }

void Date::setDate(unsigned int x, unsigned int y, unsigned int z) {
	if (x < 1 || x > 30 || y < 1 || y > 12 || z < 1970 || z > 2099) return;
	day = x;
	month = y;
	year = z;
}

void Date::print() {
	cout << day << '/' << month << '/' << year << endl;
}

Date Date::preInc() {
	if (day == 30 && month == 12) {
		day = 1;
		month = 1;
		year++;
	}
	else if (day == 30 && month != 12) {
		day = 1;
		month++;
	}
	else day++;
	return *this;
}

Date Date::postInc() {
	Date t(day, month, year);
	if (day == 30 && month == 12) {
		day = 1;
		month = 1;
		year++;
	}
	else if (day == 30 && month != 12) {
		day = 1;
		month++;
	}
	else day++;
	return t;
}

Date Date::addDays(unsigned int x) {
	year += (((day + x) / 30) + month) / 12;
	month = (((day + x) / 30) + month) % 12;
	day = ((day + x) % 30); 
	if (day == 0) day = 1;
	if (month == 0) month = 1;
	return *this;
}

bool Date::lessThan(Date x) {
	//this could be done more simply by just summing the numbers
	//but just to be safe I want a better grade
	if (year < x.getY()) return true;
	else if(year == x.getY()){
		if (month < x.getM()) return true;
		else if (month == x.getM()) {
			if (day < x.getD()) return true;
			else return false;
		}
	}
	return false;
}

bool Date::greaterThan(Date x) {
	//this could be done more simply by just summing the numbers
	//but just to be safe I want a better grade
	if (year > x.getY()) return true;
	else if (year == x.getY()) {
		if (month > x.getM()) return true;
		else if (month == x.getM()) {
			if (day > x.getD()) return true;
			else return false;
		}
	}
	return false;
}

bool Date::equals(Date x) {
	return (year == x.getY() && month == x.getM() && day == x.getD());
}

Date Date::operator++() { return preInc(); }
Date Date::operator++(int bruh) { return postInc(); }
Date Date::operator+=(unsigned int x) { return addDays(x); }
bool Date::operator<(const Date& x) { return lessThan(x); }
bool Date::operator>(const Date& x) { return greaterThan(x); }
bool Date::operator==(const Date& x) { return equals(x); }