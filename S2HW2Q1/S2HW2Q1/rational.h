#pragma once
#include <iostream>

class Rational {
public:
	Rational(int x, int y);
	Rational();
	void setN(int x);
	void setD(int x);
	int getN();
	int getD();
	void print();
	bool equal(Rational x);
	void reduce();

	bool operator!=(const Rational& x);
	bool operator<(const Rational& X);
	bool operator>(const Rational& x);
	bool operator>=(const Rational& x);
	Rational operator/(const Rational& x);
	Rational operator-(const Rational& x);
	Rational operator--();
	Rational operator--(int bruh);
	Rational operator++();
	Rational operator++(int bruh);

private:
	int num;
	int den;
	int oNum;
	int oDen;
	int gcd(int x, int y);

	bool notEqual(Rational x);
	bool lessThan(Rational x);
	bool greaterThan(Rational x);
	bool greaterThanOrEqual(Rational x);
	Rational minus(Rational x);
	Rational divide(Rational x);
	Rational postInc();
	Rational preInc();
	Rational preDec();
	Rational postDec();

	
	
};