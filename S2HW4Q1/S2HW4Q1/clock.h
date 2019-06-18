#pragma once
#include <iostream>
#include <string>

class Clock {
public: 
	Clock();
	Clock(int x, int y = 0, int z = 0);
	Clock(const Clock& x);

	// getters/setters
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	void setHour(const int x);
	void setMinute(const int x);
	void setSecond(const int x);

	// ops
	int operator+=(const int x);
	friend std::ostream& operator<<(std::ostream& stream, const Clock& x);
	friend std::istream& operator>>(std::istream& stream, Clock& x);

private:
	int hour, minute, second;
};