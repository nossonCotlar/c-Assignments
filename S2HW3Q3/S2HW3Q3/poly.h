#pragma once
#include <cmath>

class Point {
public:
	Point();
	Point(float x, float y);
	Point(const Point& x);
	static float distance(const Point& boi1, const Point& boi2);
	float getX() const;
	float getY() const;

private:
	float x, y;
};

class Poly {
public:
	Poly();
	Poly(const int x);
	Poly(const int x, const float * values);
	Poly(const Poly& x);
	~Poly();
	int getAmount() const;
	Point& operator[](const int x) const;
	float permimeter() const;

private:
	Point * vertices;
	int amount;
};