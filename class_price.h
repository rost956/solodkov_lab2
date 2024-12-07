#pragma once
#include <string>
using namespace std;

class Price {
private:
	string name;
	string shop_name;
	int cost;
public:
	Price(const Price& priced);
	Price(string name, string shop_name, int cost);
	Price();
	~Price();
	int get_cost() const;
	string get_name() const;
	string get_shop_name() const;

	void set_cost(int cost);
	void set_name(string name);
	void set_shop_name(string shop_name);

	void print();
	Price& operator= (Price& copy);
};