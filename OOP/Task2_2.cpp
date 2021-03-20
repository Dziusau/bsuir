#include <iostream>
using namespace std;

class Product {
	string name;
	float price;

public:
	Product(string name = "", float price = 0) : name(name), price(price) {}

	void setName(string name) { this->name = name; }
	string getName() { return name; }

	void setPrice(float price) { this->price = price; }
	float getPrice() { return price; }
};

class Customer {

};