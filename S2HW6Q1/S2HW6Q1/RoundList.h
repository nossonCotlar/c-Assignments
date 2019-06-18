#pragma once
#include "List.h"

class RoundList : public List {
public:
	RoundList();
	void clear();
	void addToEnd(int key);
	void removeFirst();
	int search(int n);
	void add(int x);
	void insert(int key);
	void print(std::ostream& stream) const;

private:
	Link * foot;
};