#include "class_price.h"
#include <iostream>
using namespace std;
int Price::get_cost() {
	return cost;
}

string Price::get_name() {
	return name;
}

string Price::get_shop_name() {
	return shop_name;
}

void Price::set_cost(int cost) {
	this->cost = cost;
}

void Price::set_shop_name(string shop_name) {
	this->shop_name = shop_name;
}

void Price::set_name(string name) {
	this->name = name;
}

void Price::print() {
	cout << get_name() << endl;
	cout << get_shop_name() << endl;
	cout << get_cost() << " руб." << endl;
}