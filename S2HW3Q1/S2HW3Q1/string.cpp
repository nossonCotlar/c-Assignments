#include "string.h"


String::String(char * x) {
	setString(x);
}
String::String(const String& x) {
	setString(x.getString());
}
String::~String() {
	if (string) {
		delete[] string;
	}
	string = nullptr;
}
char * String::getString() const {
	return string;
}
void String::setString(const char * x) {
	
	if (x) {
		int len = strlen(x) + 1;
		string = new char[len];
		strcpy_s(string, len, x);
	}
	else string = nullptr;
}
String& String::operator=(const String& x) {
	if (string) {
		delete[] string;
	}
	setString(x.getString());
	return *this;
}
String String::operator+(const String & x) {
	int sizeA = strlen(string);
	int sizeB = strlen(x.getString());
	char * temp = new char[sizeA + sizeB + 1];
	strcpy_s(temp, sizeA + 1, string);
	strcpy_s(temp + sizeA, sizeB + 1, x.getString());
	String y(temp);
	delete[] temp;
	return y;
}
String String::operator*(const int x) {
	char * temp;
	int len = strlen(string);
	temp = new char[(len * x) + 1];
	for (int i = 0; i < x; i++) {
		strcpy_s(temp + (i * len), len + 1, string);
	}
	String a(temp);
	return a;
}
bool String::operator==(const String& x) const {
	return !strcmp(string, x.getString());
}
bool String::operator<(const String& x) const {
	for (int i = 0; i < this->length(); i++) {
		if (string[i] == x.getString()[i]) continue;

		else if (string[i] < x.getString()[i]) return true;

		else return false;
	}
	return false;
}
bool String::operator>(const String& x) const {
	for (int i = 0; i < this->length(); i++) {
		if (string[i] == x.getString()[i]) continue;

		else if (string[i] > x.getString()[i]) return true;

		else return false;
	}
	return false;
}
bool String::operator<=(const String& x) const {
	for (int i = 0; i < this->length(); i++) {
		if (string[i] == x.getString()[i]) continue;

		else if (string[i] < x.getString()[i]) return true;

		else return false;
	}
	return true;
}
bool String::operator>=(const String& x) const {
	for (int i = 0; i < this->length(); i++) {
		if (string[i] == x.getString()[i]) continue;

		else if (string[i] > x.getString()[i]) return true;

		else return false;
	}
	return true;
}
bool String::operator!=(const String& x) const {
	for (int i = 0; i < this->length(); i++) {
		if (string[i] != x.getString()[i]) return true;
	}
	return false;
}
int String::length() const {
	return strlen(string);
}
void String::print() const {
	if (string) {
		std::cout << string << std::endl;
	}
}
String& String::insert(const int index, const String& x) {

	if (index > x.length() || index < 0) {
		std::cout << "ERROR" << std::endl;
		return *this;
	}

	int length = this->length();
	char * temp = new char[length + x.length() + 1];
	
	//copy first bit (until index) of local string into temp
	strncpy_s(temp, 100, string, index); 
	//copy entire supplied string into temp at specified index
	strcat_s(temp + index, 100, x.getString()); 
	//copy the rest of local string into temp after the supplied string
	strcat_s(temp + index + x.length(), 100, string + index);
	this->setString(temp);
	//delete temp;
	return *this;

}