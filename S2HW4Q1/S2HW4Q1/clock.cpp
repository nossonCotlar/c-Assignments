#include "clock.h"

Clock::Clock() {
	setHour(0);
	setMinute(0);
	setSecond(0);
}
Clock::Clock(const Clock& x) {
	setHour(x.getHour());
	setMinute(x.getMinute());
	setSecond(x.getSecond());
}
Clock::Clock(int x, int y, int z) {
	try {
		setHour(x);
		setMinute(y);
		setSecond(z);
	}
	catch(const char * exception){
		setHour(0);
		setMinute(0);
		setSecond(0);
		std::cout << exception << std::endl;
	}
}
int Clock::getHour() const { return hour; }
int Clock::getMinute() const { return minute; }
int Clock::getSecond() const { return second; }
void Clock::setHour(const int x) {
	if (x > 23) throw "Invalid time - more than 24 hours";
	else if (x < 0) throw "Invalid time - negative number of hours";
	hour = x;
}
void Clock::setMinute(const int x) {
	if (x > 59) throw "Invalid time - more than 60 minutes";
	else if (x < 0) throw "Invalid time - negative number of minutes";
	minute = x;
}
void Clock::setSecond(const int x) {
	if (x > 59) throw "Invalid time - more than 60 seconds";
	else if (x < 0) throw "Invalid time - negative number of minutes";
	second = x;
}
int Clock::operator+=(const int x) {
	//beginning, ending, and duration ending times
	int bHour, bMin, bSec, eHour, eMin, eSec, dHour, dMin, dSec; 
	bSec = getSecond();
	bMin = getMinute();
	bHour = getHour();

	dSec = x % 60;
	dMin = x / 60;
	dHour = x / 3600;

	eSec = (bSec + dSec) % 60;
	eMin = ((bMin + dMin) + ((bSec + dSec) / 60)) % 60;
	eHour = ((bHour + dHour) + ((bMin + dMin) / 60)) % 24;

	setSecond(eSec);
	setMinute(eMin);
	setHour(eHour);

	
	return getSecond();
}
std::ostream& operator<<(std::ostream& stream, const Clock& x) {
	if (x.getHour() < 10) {
		stream << '0'; //these are to ensure a two character output even if less than 10
	}
	stream << x.getHour() << ':';

	if (x.getMinute() < 10) {
		stream << '0';
	}
	stream << x.getMinute() << ':';

	if (x.getSecond() < 10) {
		stream << '0';
	}
	stream << x.getSecond();

	return stream;
}
std::istream& operator>>(std::istream& stream, Clock& x) {
	std::string input;
	int holder;
	stream >> input;

	try {
		if (input.at(2) != ':' || input.at(5) != ':') {
			throw "Wrong time format";
		}
		holder = std::stoi(input); //convert first number in string to int
		if (holder >= 0 && holder <= 23) {
			x.setHour(holder);
			input.erase(0, 3); //cut off the first bit for easy reading
		}
		else throw "Wrong time format";

		holder = std::stoi(input); //convert next number in string to int
		if (holder >= 0 && holder <= 59) {
			x.setMinute(holder);
			input.erase(0, 3); //cut off the first bit for easy reading
		}
		else throw "Wrong time format";

		holder = std::stoi(input); //convert next number in string to int
		if (holder >= 0 && holder <= 59) {
			x.setSecond(holder);
		}
		else throw "Wrong time format";
		
	}
	catch (const char * exception) {
		std::cout << exception << std::endl;
	}
	return stream;
}
