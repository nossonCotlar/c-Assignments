#include "List.h"

// ========== Link ==========
List::Link::Link(int x, Link * nxt = NULL) {
	value = x;
	next = nxt;
}
List::Link::Link(const Link& x) {
	value = x.value;
	next = x.next;
}
List::Link& List::Link::operator=(const Link& x) {
	value = x.value;
	next = x.next;
	return *this;
}

// ========== List ==========
List::List() {
	head = NULL;
}
List::List(const List& x) {
	Link * source, *target;

	if (x.head == NULL) {
		head = NULL;
	}
	else {
		head = new Link((x.head)->value, NULL);
		source = x.head;
		target = head;
		while (source->next != NULL) {
			target->next = new Link(source->next->value, NULL);
			source = source->next;
			target = target->next;
		}
	}
}
List::~List() {
	clear();
}
void List::clear() {
	Link* next;
	for (Link * p = head; p != NULL; p = next)
	{
		// delete the element pointed to by p
		next = p->next;
		p->next = NULL;
		delete p;
	}
	// mark that the List contains no elements
	head = NULL;
}
bool List::isEmpty() const {
	return (head == NULL);
}
void List::add(int x) {
	head = new Link(x, head);
	if (head == NULL) throw "failed in memory allocation";
}
void List::insert(int key) {
	Link * p = head;

	if (p == NULL) {
		add(key); //if it's empty we can just add to the beginning
		return;
	}
	if (p->value > key) { //if the first value is greater than key
		Link * added = new Link(head->value, head->next); //make a new link and replace 
		head->value = key;
		head->next = added;
		return;
	}

	while (p->next != NULL && p->next->value < key) { //goes through list until the next value is greater than key
		if (p->next == NULL) break; //if we're at the end just skip to adding
		p = p->next;
	}
	Link * added = new Link(key, p->next); //make a new link and point to the original "next"
	p->next = added; //make the new "next" pointing to the Link that was just added

}
int List::firstElement() const {
	if (isEmpty()) throw "the List is empty, no first Element";
	return head->value;
}
/*
bool List::search(const int& x) const {
	for (Link * p = head; p != NULL; p = p->next) {
		if (p->value == x) return true;
	}
	return false;
}
*/
void List::removeFirst() {
	if (isEmpty()) throw "the List is empty, no Element to remove";
	Link * p = head;
	head = p->next;
	p->next = NULL;
	delete p;
}
void List::remove(int key) {
	Link * p = head;

	if (p == NULL) throw "value not found";
	else if (head->value == key) { //account for first value case
		Link * temp = head;
		head = head->next;
		delete temp;
	}
	else {
		while (p->next->value != key) { //goes through list until the next value equals key
			if (p->next == NULL) throw "value not found";
			p = p->next; //itterate through List
		}

		Link * temp = p->next; //save location of Link to be deleted
		p->next = p->next->next; //switch "next" to two Links forward
		delete temp; //free up memory
	}
}
void List::print(std::ostream& stream) const {
	for (Link * p = head; p != NULL; p = p->next) {
		stream << p->value << ' ';
	}
	stream << std::endl;
}
List& List::operator=(const List& x) {
	Link * source, *target;

	if (x.head == NULL) {
		head = NULL;
	}
	else {
		head = new Link((x.head)->value, NULL);
		source = x.head;
		target = head;
		while (source->next != NULL) {
			target->next = new Link(source->next->value, NULL);
			source = source->next;
			target = target->next;
		}
	}
	return *this;
}
std::ostream& operator<<(std::ostream& stream, const List& x) {
	x.print(stream);
	return stream;
}
std::istream& operator>>(std::istream& stream, List& x) {
	int val, prev;
	x.clear(); //clear all contents to prepare for stream

	stream >> val; //input initial value
	prev = val - 1; //make sure "previous" value isn't an issue

	List::Link * p = new List::Link(val);
	x.head = p;

	while (stream) {
		if (val <= prev) break;

		List::Link * added = new List::Link(val);

		p->next = added;
		p = added;

		prev = val;
		stream >> val;
	}

	x.removeFirst(); //to rectify initial value entry

	return stream;
}

// ========== Globals ==========
List& merge(const List& x, const List& y) {
	List * result = new List;
	List::Link * uptoX = x.head, *uptoY = y.head, *uptoR = result->head; //used to keep track of current elements
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