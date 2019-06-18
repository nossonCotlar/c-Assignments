#include "circle.h"
#include <cmath>

Circle::Circle() {
	//center point has already been instantiated to (0, 0) with its own constructor
	rad = 0; //decided not to make any circle by default (as opposed to a unit circle)
}
Circle::Circle(Point c, float r) {
	center.setX(c.getX());
	center.setY(c.getY());
	rad = r;
}
Point Circle::getCenter() {
	return center;
}
float Circle::getRad() {
	return rad;
}
void Circle::setCenter(Point c) {
	center.setX(c.getX());
	center.setY(c.getY());
}
void Circle::setRad(float r) {
	rad = r;
}
float Circle::area() {
	return PI * rad * rad;
}
float Circle::circ() {
	return 2 * PI * rad;
}

short Circle::location(Point p) {
	float d = sqrt(pow(center.getX() - p.getX(), 2) + pow(center.getY() - p.getY(), 2));
	if (d < rad) return -1;
	if (d == rad) return 0;
	if (d > rad) return 1;
}