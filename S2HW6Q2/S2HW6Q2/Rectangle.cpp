#include "Rectangle.h"

Rectangle::Rectangle(int x, int y) : Polygon(4) {
	sides[0] = x;
	sides[1] = y;
	sides[2] = x;
	sides[3] = y;
}