#pragma once
#include "Student.h"

class BA : public Student {
public:
	BA(int id, int courses, int size, float * x, std::string& first, std::string& last);

	virtual bool milga() const override;
	virtual void print() const override;
	virtual std::string studType() const override;

	int getSize() const;
	float * getGrades() const;
	float avg() const;



private:
	int size;
	float * grades;
	void setGrades(const float * x);
};

class MA : public BA {
public:
	MA(int id, int courses, int size, float * x, bool research, std::string& first, std::string& last);

	bool milga() const override;
	void print() const override;
	virtual std::string studType() const override;
	virtual bool getResearch() const override;

protected:
	bool research;
};

class PHD : public Student {
public:
	PHD(int id, int courses, int hours, std::string& first, std::string& last);

	bool milga() const override;
	void print() const override;
	virtual std::string studType() const override;
	virtual int getHours() const override;

protected:
	int hours;
};

