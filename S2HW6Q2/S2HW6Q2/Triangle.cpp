#include "Triangle.h"

Triangle::Triangle(int x, int y, int z) : Polygon(3) {
	sides[0] = x;
	sides[1] = y;
	sides[2] = z;
}