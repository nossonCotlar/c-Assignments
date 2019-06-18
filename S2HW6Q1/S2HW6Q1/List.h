#pragma once
#include <iostream>

class List {
protected:
	class Link {
	public:
		Link(int x, Link * nxt);
		Link(const Link& x);

		Link& operator=(const Link& x);

		int value;
		Link * next;
	};

public:
	List();
	List(const List& x);
	~List();

	//===== funcs =====
	void add(int x);

	void insert(int key);
	int firstElement() const;
	//bool search(const int& x) const;
	bool isEmpty() const;
	void removeFirst();
	void remove(int key);
	void clear();
	void print(std::ostream& stream) const;

	//===== ops =====
	List& operator=(const List& x);
	friend std::ostream& operator<<(std::ostream& stream, const List& x);
	friend std::istream& operator>>(std::istream& stream, List& x);

	//===== frenz =====
	friend List& merge(const List& x, const List& y);
	friend void makeSet(List& x);

protected:
	Link * head;
};