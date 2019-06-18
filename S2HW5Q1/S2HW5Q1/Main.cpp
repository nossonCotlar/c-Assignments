// Main.cpp
// Linked List stuffs
// C++
// Semester 2 Exercise 5 Question 3
// Nosson Cotlar - 524859733
// 5/17/19


#include <iostream>
#include <cmath>
#include <string>
#include "List.h"

using namespace std;

int main() {
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;



	return 0;
}

List& merge(const List& x, const List& y) {
	List * result = new List;
	List::Link * uptoX = x.head, * uptoY = y.head, * uptoR = result->head; //used to keep track of current elements
	List::Link * p; //used for creating new Links

	while (uptoX != NULL && uptoY != NULL) { //while both Lists have some elements left
		if (uptoX->value == uptoY->value) { //duplicate case
			p = new List::Link(uptoX->value, NULL); //create new link
			if (uptoR != NULL) uptoR->next = p; //only if we aren't at the beginning of the list
			uptoR = p; //moves result "upto" to current Link
			if (result->head == NULL) result->head = uptoR;
			uptoX = uptoX->next; //moves List X forward
			p = new List::Link(uptoY->value, NULL); //create new link
			uptoR->next = p;
			uptoR = p; //moves result "upto" to current Link
			uptoY = uptoY->next; //moves List Y forward

			continue;
		}
		if (uptoX->value < uptoY->value) {
			p = new List::Link(uptoX->value, NULL); //create new link
			if (uptoR != NULL) uptoR->next = p; //only if we aren't at the beginning of the list
			uptoR = p; //moves result "upto" to current Link
			if (result->head == NULL) result->head = uptoR;
			uptoX = uptoX->next; //moves List X forward

			continue;
		}
		if (uptoY->value < uptoX->value) {
			p = new List::Link(uptoY->value, NULL); //create new link
			if (uptoR != NULL) uptoR->next = p;
			uptoR = p; //moves result "upto" to current Link
			if (result->head == NULL) result->head = uptoR;
			uptoY = uptoY->next; //moves List Y forward

			continue;
		}
	}

	while (uptoX != NULL) {
		p = new List::Link(uptoX->value, NULL); //create new link
		if (uptoR != NULL) uptoR->next = p; //only if we aren't at the beginning of the list
		uptoR = p; //moves result "upto" to current Link
		if (result->head == NULL) result->head = uptoR;
		uptoX = uptoX->next; //moves List X forward
	}

	while (uptoY != NULL) {
		p = new List::Link(uptoY->value, NULL); //create new link
		uptoR->next = p;
		uptoR = p; //moves result "upto" to current Link
		if (result->head == NULL) result->head = uptoR;
		uptoY = uptoY->next; //moves List Y forward
	}

	return *result;
	
}

void makeSet(List& x) {
	List::Link * upto = x.head; //self explanatory
	List::Link * temp;

	while (upto != NULL && upto->next != NULL) {
		if (upto->value == upto->next->value) {
			temp = upto->next;
			upto->next = upto->next->next;
			delete temp;
		}
		upto = upto->next;
	}
}