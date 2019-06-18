 #include "rational.h"
#include <iostream>
#include <cstring>

Rational::Rational(int x, int y) {
	if (y == 0) {
		std::cout << "ERROR" << std::endl;
	}
	num = x;
	den = (y == 0) ? 1 : y;
	oNum = x;
	oDen = (y == 0) ? 1 : y;
	reduce();
}
Rational::Rational() {
	num = 0;
	den = 1;
	oNum = 0;
	oDen = 1;
}
void Rational::setN(int x) {
	num = x;
}
void Rational::setD(int x) {
	den = x;
	if (x == 0) den = 1;
}
int Rational::getN() {
	return num;
}
int Rational::getD() {
	return den;
}
void Rational::print() {
	reduce();
	if (num == 0 || den == 1) {
		std::cout << num << std::endl;
	}
	else std::cout << num << '/' << den << std::endl;
}

bool Rational::equal(Rational x) {

	if (x.getN() == num && x.getD() == den) return true;
	else return false;
}

void Rational::reduce() {
	int d = gcd(num, den);
	num /= d;
	den /= d;
}
int Rational::gcd(int x, int y)
{
	// Euclid's Algorithm
	if (y == 0)
	{
		return x;
	}
	return gcd(y, x%y);
}

bool Rational::notEqual(Rational x) {
	if (num / den == x.getN() / x.getD() && num % den == x.getN() % x.getD()) return false;
	else return true;
}

bool Rational::lessThan(Rational x) {
	if (num / den < x.getN() / x.getD()) return true;
	else if (num / den == x.getN() / x.getD() && num % den < x.getN() % x.getD()) return true;
	else return false;
}
bool Rational::greaterThan(Rational x) {
	if (num / den > x.getN() / x.getD()) return true;
	else if (num / den == x.getN() / x.getD() && num % den > x.getN() % x.getD()) return true;
	else return false;
}
bool Rational::greaterThanOrEqual(Rational x) {
	if (num / den > x.getN() / x.getD()) return true;
	else if (num / den == x.getN() / x.getD() && num % den >= x.getN() % x.getD()) return true;
	else return false;
}

Rational Rational::divide(Rational x) {
	return Rational(num * x.getD(), den * x.getN());
}

Rational Rational::minus(Rational x) {
	int tDen = den * x.getD();
	int tNum = num * x.getD();
	tNum -= x.getN() * den;
	return Rational(tNum, tDen);
}

Rational Rational::preInc() {
	num += den;
	return Rational(num, den);
}

Rational Rational::postInc() {
	Rational t(num, den);
	num += den;
	return t;
}

Rational Rational::preDec() {
	num -= den;
	return Rational(num, den);
}

Rational Rational::postDec() {
	Rational t(num, den);
	num -= den;
	return t;
}

bool Rational::operator!=(const Rational& x) {return notEqual(x);}
bool Rational::operator<(const Rational& x) {return lessThan(x);}
bool Rational::operator>(const Rational& x) {return greaterThan(x);}
bool Rational::operator>=(const Rational& x) {return greaterThanOrEqual(x);}
Rational Rational::operator/(const Rational& x) {return divide(x);}
Rational Rational::operator-(const Rational& x) {return minus(x);}
Rational Rational::operator--() {return preDec();}
Rational Rational::operator--(int bruh) {return postDec();}
Rational Rational::operator++() {return preInc(); }
Rational Rational::operator++(int bruh) {return postInc();}