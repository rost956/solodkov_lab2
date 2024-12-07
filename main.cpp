#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Queue.h"
#include "class_price.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Queue stack;
	int command = 0;
	int command2 = 0;
	int input_int = 0;
	Price* a = new Price();
	/*Price* b = new Price("aaa", "bbb", 111); // ПОКАЗ ПЕРЕГРУЗКИ
	a = b;
	a->print();*/
	string input;
	while (command != 3) {
		system("cls");
		cout << "-----Меню-----" << endl;
		cout << "1. 1 задание" << endl;
		cout << "2. 2 задание" << endl;
		cout << "3. Закрыть программу" << endl;
		cout << ">>> ";
		cin >> command;
		getchar();
		switch (command) {
		case 1:
			command2 = 0;
			system("cls");
			while (command2 != 6) { //поменять число под меню
				cout << "-----Меню-----" << endl;
				cout << "1. Добавить новый объект в список" << endl; //+
				cout << "2. Просмотреть список" << endl; //+
				cout << "3. Найти товары по магазину" << endl; //+
				cout << "4. Отредактировать товар" << endl;  //+
				cout << "5. Удалить объект" << endl; //+
				cout << "6. Выйти в меню выбора задания" << endl;
				cout << ">>> ";
				cin >> command2;
				getchar();
				
				switch (command2) {
				case 1:
					
					system("cls");
					cout << "Введите название товара: ";
					cin >> input;
					a->set_name(input);
					cout << "Введите название магазина: ";
					cin >> input;
					cout << "Введите стоимость: ";
					cin >> input_int;
					
					a->set_shop_name(input);
					a->set_cost(input_int);
					stack.add(a);
					system("cls");
					break;
				case 2:
					system("cls");
					stack.print();
					system("pause");
					system("cls");
					break;
				case 3:
					system("cls");
					cout << "Введите название магазина: ";
					cin >> input;
					system("cls");
					stack.print_shops(input);
					system("pause");
					system("cls");
					break;
				case 4:
					system("cls");
					cout << "Введите номер товара в списке, который необходимо отредактировать: ";
					cin >> input_int;
					system("cls");
					stack.edit(input_int-1);
					system("cls");
					break;
				case 5:
					system("cls");
					cout << "Введите номер товара в списке, который необходимо удалить: ";
					cin >> input_int;
					system("cls");
					stack.delet_e(input_int-1);
					break;
				case 6:

					break;
				}
		
			}
			break;
		case 2:
			break;
		case 3:
			return 0;
			break;
		}
	}
	


}