#pragma once

class Vector {
public:
	Vector();
	Vector(const int x);
	Vector(const Vector& x);
	~Vector();

	int getCapacity() const;
	int getSize() const;
	void print() const;
	void clear();
	void delLast();
	void insert(const int x);

	Vector& operator=(const Vector& x);
	bool operator==(const Vector& x) const;
	int operator*(const Vector& x) const;
	int& operator[]( const int x) const ;
	Vector operator+(const Vector& x);
	

private:
	int * data;
	int capacity;
	int size;
};