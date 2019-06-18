#include "point.h"

Point::Point() {
	x = 0;
	y = 0;
}
Point::Point(float x, float y) {
	this->x = x;
	this->y = y;
}
float Point::getX() {
	return x;
}
float Point::getY() {
	return y;
}
void Point::setX(float a) {
	x = a;
}
void Point::setY(float a) {
	y = a;
}