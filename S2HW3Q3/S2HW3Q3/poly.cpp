#include "poly.h"

Point::Point() {
	x = 0;
	y = 0;
}
Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}
Point::Point(const Point& x) {
	this->x = x.getX();
	this->y = x.getY();
}
float Point::getX() const { return x; }
float Point::getY() const { return y; }
float Point::distance(const Point& boi1, const Point& boi2) {
	float a = pow(boi1.getX() - boi2.getX(), 2);
	float b = pow(boi1.getY() - boi2.getY(), 2);
	return sqrt(a + b);
}

//===================================================================

Poly::Poly() {
	amount = 0;
}
Poly::Poly(const int x) {
	amount = x;
	vertices = new Point[x];
}
Poly::Poly(const int x, const float * values) {
	amount = x;
	vertices = new Point[x];
	for (int i = 0; i < x; i++) {
		vertices[i] = Point(values[i * 2], values[i * 2 + 1]);
	}
}
Poly::~Poly() {
	if (vertices) delete[] vertices;
}
Poly::Poly(const Poly& x) {
	if (vertices) delete[] vertices;
	amount = x.getAmount();
	vertices = new Point[amount];
	for (int i = 0; i < amount; i++) {
		vertices[i] = x[i];
	}
}
int Poly::getAmount() const { return amount; }
Point& Poly::operator[](const int x) const { return vertices[x]; }
float Poly::permimeter() const {
	float sum = 0;
	for (int i = 0; i < amount - 1; i++) {
		sum += Point::distance(vertices[i], vertices[i + 1]);
	}
	sum += Point::distance(vertices[amount - 1], vertices[0]);
	return sum;
}