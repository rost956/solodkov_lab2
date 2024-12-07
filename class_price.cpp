#include "class_price.h"
#include <iostream>
using namespace std;

Price::Price(const Price& price) {
	cout << "Был вызван конструктор копирования" << endl;
	name = price.name;
	shop_name = price.shop_name;
	cost = price.cost;
}
Price::Price() {
	cout << "Был вызван конструктор по умолчанию" << endl;
	this->name = "None";
	this->shop_name = "None";
	this->cost = 0;
}
Price::Price(string name, string shop_name, int cost) {
	cout << "Был вызван конструктор" << endl;
	this->name = name;
	this->shop_name = shop_name;
	this->cost = cost;
}
Price::~Price() {
	cout << "Был вызван деструктор" << endl;
}


int Price::get_cost() const{
	return cost;
}

string Price::get_name() const{
	return name;
}

string Price::get_shop_name() const{
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
	cout << "Название товара: " << get_name() << endl;
	cout << "Магазин: " << get_shop_name() << endl;
	cout << "Стоимость: " << get_cost() << " руб." << endl;
}

Price& Price::operator=(Price& copy)
{
	shop_name = copy.get_shop_name();
	name = copy.get_name();
	cost = copy.get_cost();
	return *this;
}
