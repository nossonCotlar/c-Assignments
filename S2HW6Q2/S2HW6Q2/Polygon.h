#pragma once
#include <iostream>

class Polygon {
public:
	Polygon(int x);
	Polygon(const Polygon& x);

	int getNumSides() const;
	int getSide(int x) const;
	int perimeter() const;

	int operator[](const int x) const;
	bool operator==(const Polygon& x) const;
	bool operator==(const int x) const;

protected:
	int numSides;
	int * sides;
};