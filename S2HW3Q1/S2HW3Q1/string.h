#pragma once
#include <cstring>
#include <iostream>

class String {
public:
	String(char * x = nullptr);
	String(const String& x);
	~String();

	char * getString() const;
	int length() const;
	void print() const;
	String& insert(const int index, const String& x);

	String& operator=(const String& x);
	bool operator==(const String& x) const;
	bool operator<(const String& x) const;
	bool operator>(const String& x) const;
	bool operator<=(const String& x) const;
	bool operator>=(const String& x) const;
	bool operator!=(const String& x) const;
	String operator+(const String& x);
	String operator*(const int x);


private:
	char * string;
	void setString(const char * x);
};