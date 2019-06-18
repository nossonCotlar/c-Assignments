#include "Polygon.h"

Polygon::Polygon(int x) {
	numSides = x;
	sides = new int[numSides];
	if (x != 3 && x != 4) {
		std::cout << "enter sides for polygon: ";
		for (int i = 0; i < numSides; i++) {
			std::cin >> sides[i];
		}
	}
}
Polygon::Polygon(const Polygon& x) {
	numSides = x.getNumSides();
	sides = new int[numSides];
	for (int i = 0; i < numSides; i++) {
		sides[i] = x[i];
	}
}
int Polygon::perimeter() const {
	int sum = 0;
	for (int i = 0; i < numSides; i++) {
		sum += getSide(i);
	}
	return sum;
}
int Polygon::getNumSides() const { return numSides; }
int Polygon::getSide(int x) const { return sides[x]; }
int Polygon::operator[](const int x) const { return getSide(x); }
bool Polygon::operator==(const Polygon& x) const {
	return (numSides == x.getNumSides() && perimeter() == x.perimeter());
}
bool Polygon::operator==(const int x) const { return (getNumSides() == x); }