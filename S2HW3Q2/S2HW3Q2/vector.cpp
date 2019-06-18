#include "vector.h"
#include <iostream>

Vector::Vector() {
	capacity = 10;
	data = new int[capacity];
	size = 0;
}
Vector::Vector(const int x) {
	capacity = x;
	data = new int[x];
	size = 0;
}
Vector::Vector(const Vector& x) {
	int otherSize = x.getSize();
	capacity = x.getCapacity();
	size = otherSize;
	data = new int[capacity];
	for (int i = 0; i < otherSize; i++) {
		data[i] = x[i];
	}
}
Vector::~Vector() {
	if (data) {
		delete[] data;
	}
	data = NULL;
}
int Vector::getCapacity() const { return capacity; }
int Vector::getSize() const { return size; }
void Vector::print() const {

	std::cout << "capacity: " << capacity << " size: " << size << " val: ";
	for (int i = 0; i < size; i++) {
		std::cout << data[i] << ' ';
	}
	std::cout << std::endl;
}
void Vector::clear() {
	for (int i = 0; i < size; i++) {
		data[i] = NULL;
	}
	size = 0;
}
void Vector::delLast() { 
	if (size < 1) {
		std::cout << "ERROR" << std::endl;
		return;
	}
	data[--size] = NULL;
}
void Vector::insert(const int x) {
	if (size >= capacity) {
		std::cout << "ERROR" << std::endl;
		return;
	}
	data[size++] = x;
}
Vector& Vector::operator=(const Vector& x) {
	int otherSize = x.getSize();
	capacity = x.getCapacity();
	size = otherSize;
	data = new int[capacity];
	for (int i = 0; i < otherSize; i++) {
		data[i] = x[i];
	}
	return *this;
}
bool Vector::operator==(const Vector& x) const {
	if (size != x.getSize()) return false;
	for (int i = 0; i < size; i++) {
		if (data[i] != x[i]) return false;
	}
	return true;
}
int& Vector::operator[](const int x) const { 
	if (x > size || x < 0) {
		std::cout << "ERROR" << std::endl;
		return data[0];
	}
	return data[x]; 
}
int Vector::operator*(const Vector& x) const {
	if (size != x.getSize()) {
		std::cout << "ERROR" << std::endl;
		return NULL;
	}
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += data[i] * x[i];
	}
	return sum;
}
Vector Vector::operator+(const Vector& x) {
	int otherSize = x.getSize();
	Vector yeet(capacity + x.getCapacity());
	for (int i = 0; i < size; i++) {
		yeet.insert(data[i]);
	}
	for (int i = 0; i < otherSize; i++) {
		yeet.insert(x[i]);
	}
	return yeet;
}
