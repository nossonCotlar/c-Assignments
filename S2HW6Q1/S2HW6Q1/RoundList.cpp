#include "RoundList.h"

RoundList::RoundList() {
	List();
	foot = NULL;
}
void RoundList::clear() {
	Link * next;
	for (Link * p = head; p != foot; p = next)
	{
		// delete the element pointed to by p
		next = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}
void RoundList::add(int x) {
	head = new Link(x, head);
	if (head == NULL) throw "failed in memory allocation";
	if (head->next == NULL) { //if there's only one element 
		foot = head;
	}
	foot->next = head; 
}
void RoundList::addToEnd(int key) {
	if (isEmpty()) {
		add(key); 
		return;
	}
	Link * temp = foot;
	foot = new Link(key, head);
	temp->next = foot;
}
void RoundList::removeFirst() {
	if (isEmpty()) {
		//throw "List is already empty";
		return;
	}
	if (head == foot) { //if there's only one element
		delete head;
		head = NULL;
		foot == NULL;
		return;
	}
	Link * temp = head;
	head = head->next;
	foot->next = head;
	delete temp;
}
int RoundList::search(int n) {
	if (head == NULL) throw "List is empty";
	Link * p = head;
	for (int i = 0; i < n; i++) {
		p = p->next;
	}
	return p->value;
}
void RoundList::insert(int key) {
	if (isEmpty() || head->value >= key) {
		add(key);
		return;
	}

	Link * p = head;

	while (p->next != head && p->next->value < key) { //goes through list until the next value is greater than key
		if (p->next == head) break; //if we're at the end just skip to adding
		p = p->next;
	}
	Link * added = new Link(key, p->next); //make a new link and point to the original "next"
	p->next = added; //make the new "next" pointing to the Link that was just added
	if (added->next == head) { //if the Link that was added was at the end
		foot = added; //update foot to be the added Link
	}
}
void RoundList::print(std::ostream& stream) const {
	Link * p = head;
	do {
		if (isEmpty()) break;
		stream << p->value << ' ';
		p = p->next;
	} while (p != head);
	stream << std::endl;
}