#pragma once
#include "point.h"
class Circle {
	Point center;
	float rad;
public:
	const float PI = 3.14;

	Circle();
	Circle(Point, float);
	Point getCenter();
	float getRad();
	void setCenter(Point);
	void setRad(float);

	float area();
	float circ();
	short location(Point);

};