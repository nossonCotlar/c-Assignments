// HW10.cpp
// store managing program
// Introduction to Computer Science
// Exercise 10
// Nosson Cotlar
// 1/1/19

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

struct Item {
	unsigned int code;
	char name[20];
	unsigned int stock;
	unsigned int minStock;
	float price;
};

void addItem(Item store[], const int max, int& current);
void findPrice(Item store[], int x);
void sold(Item store[], int x);
void order(Item store[], int x);
void print(Item store[], int x);

int main() {
	int max, current = 0, choice;
	cout << "enter max number of items: " << endl;
	cin >> max; 

	Item* store = new Item[max];

	do {

		cout << "enter 0 - 5: " << endl;
		cin >> choice;

		switch (choice) {

		case 0: break;

		case 1: addItem(store, max, current);
			break; 

		case 2: findPrice(store, current);
			break;

		case 3: sold(store, current);
			break;

		case 4: order(store, current);
			break;

		case 5: print(store, current);
			break;

		default: cout << "ERROR" << endl;

		}
	} while (choice != 0);
	
	delete[] store;

	//system("pause");
	return 0;
}

void addItem(Item store[], int max, int& current) {

	if (current >= max) { //if at max then we only allow updating
		int code;
		char name[20];

		cout << "enter code: " << endl;
		cin >> code;
		cout << "enter name: " << endl;
		cin >> name;

		for (int i = 0; i < current; i++) {

			if (code == store[i].code && strcmp(name, store[i].name) != 0) {
				//if names dont match
				cout << "ERROR" << endl;
				return;
			}

			if (code == store[i].code && strcmp(name, store[i].name) == 0) {
				cout << "enter amount: " << endl;
				cin >> store[i].stock;
				cout << "enter minimum amount: " << endl;
				cin >> store[i].minStock;
				cout << "enter price: " << endl;
				cin >> store[i].price;
				return;
			}
		}

		return;
	}
	else {
		cout << "enter code: " << endl;
		cin >> store[current].code;
		cout << "enter name: " << endl;
		cin >> store[current].name;

		for (int i = 0; i < current; i++) {

			if (store[current].code == store[i].code && strcmp(store[current].name, store[i].name) != 0) {
				//if names dont match
				cout << "ERROR" << endl;
				return;
			}

			if (store[current].code == store[i].code && strcmp(store[current].name, store[i].name) == 0) {
				cout << "enter amount: " << endl;
				cin >> store[i].stock;
				cout << "enter minimum amount: " << endl;
				cin >> store[i].minStock;
				cout << "enter price: " << endl;
				cin >> store[i].price;
				return;
			}
		}

		//this next section will only execute if there was no matching name and code
		cout << "enter amount: " << endl;
		cin >> store[current].stock;
		cout << "enter minimum amount: " << endl;
		cin >> store[current].minStock;
		cout << "enter price: " << endl;
		cin >> store[current].price;

		current++;
	}
	
}

void findPrice(Item store[], int x) {
	int code;
	cout << "enter code: " << endl;
	cin >> code;

	for (int i = 0; i < x; i++) {
		if (store[i].code == code) {
			cout << store[i].price << endl;
			return;
		}
	}
	cout << "ERROR" << endl;
}

void sold(Item store[], int x) {
	int code, sale;
	cout << "enter code: " << endl;
	cin >> code;

	for (int i = 0; i < x; i++) {
		if (store[i].code == code) {
			cout << "enter amount: " << endl;
			cin >> sale;
			store[i].stock -= sale;
			return;
		}
	}
	cout << "ERROR" << endl;
}

void order(Item store[], int x) {

	for (int i = 0; i < x; i++) {
		if (store[i].stock < store[i].minStock) {

			cout << "item name: " << store[i].name << endl << "code: " << store[i].code << endl;

			int order = store[i].minStock - store[i].stock + 5;
			cout << "amount to order: " << order << endl;

			store[i].stock += order;
		}
	}
}

void print(Item store[], int x) {

	for (int i = 0; i < x; i++) {
		cout << "name: " << store[i].name << endl;
		cout << "code: " << store[i].code << endl;
		cout << "amount: " << store[i].stock << endl;
		cout << "minimum amount: " << store[i].minStock << endl;
		cout << "price: " << store[i].price << endl;
	}
}

/*



*/

