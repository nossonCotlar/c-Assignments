#pragma once

class Date {
public:
	Date(unsigned int x, unsigned int y, unsigned int z);
	Date(const Date& x); //I was getting some weird errors when this was const so here we are

	unsigned int getD() const;
	unsigned int getM() const;
	unsigned int getY() const;
	void setDate(unsigned int x, unsigned int y, unsigned int z);
	void print();
	Date operator++();
	Date operator++(int bruh);
	Date operator+=(unsigned int x);
	bool operator<(const Date& x);
	bool operator>(const Date& x);
	bool operator==(const Date& x);

private:
	unsigned int day, month, year;

	Date preInc();
	Date postInc();
	Date addDays(unsigned int x);
	bool lessThan(Date x);
	bool greaterThan(Date x);
	bool equals(Date x);
};