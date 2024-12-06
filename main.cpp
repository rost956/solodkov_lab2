#include <iostream>
#include <conio.h>
#include "class_price.h"
#include <windows.h>
using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	if ("À" < "Á") {
		cout << int("À") << endl;
		cout << int("Á") << endl;
	}
	Price a;
	a.set_cost(10);
	a.set_name("govno");
	a.set_shop_name("cal");
	a.print();
}