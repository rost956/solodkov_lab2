#include "Queue.h"
#include <iostream>
#include <math.h>
#include "class_price.h"
using namespace std;
void Queue::add(Price* price) {
	LNode* newNode = new LNode();
	newNode->price->set_cost(price->get_cost());
	newNode->price->set_name(price->get_name());
	newNode->price->set_shop_name(price->get_shop_name());
	int flag1 = 0;
	string name_insert = price->get_shop_name();
	if (head == nullptr) {
		head = newNode;
	}
	else {
		LNode* current = head;
		LNode* previous = current;
		int index = 0;
		while (current != nullptr) {
			string name_now = current->price->get_shop_name();
			if (name_insert <= name_now) {
				current = head;
				for (int i = 0; i < index; i++) {
					current = current->next;
				}
				if (index == 0) {
					previous = current;
					newNode->next = previous;
					head = newNode;
				}
				else {
					previous = current->next;
					current->next = newNode;
					newNode->next = previous;
				}
				//transfer->price = current->next->price; //
				//current->price = newNode->price;
				//current->next->price = current->price;
				//current = current->next;
				//while (current->next != nullptr) {
				//	cout << "dadawdw" << endl;
				//	transfer2->price = current->next->price;
				//	current->next->price = transfer->price;
				//	transfer->price = transfer2->price;
				//	current = current->next;
				//}
				//flag1 = 1;
				//break;
				flag1 = 1;
				break;
			}
			
			else{
				if (current->next == nullptr) { break; }
				else { current = current->next; }
			}
			index++;
		}
		
		if (flag1 == 0) {
			current->next = newNode;
		}

	}
	++size;
	
}

void Queue::print() const{
	LNode* current = head;
	int cnt = 0;
	if (head == nullptr) {
		cout << "Список пуст!" << endl;
		return;
	}
	cout << "Список товаров: " << endl;
	while (current != nullptr) {
		cout << "--------" << cnt+1 << "--------" << endl;
		cout << "Название товара: " << current->price->get_name() << endl;
		cout << "Магазин: " << current->price->get_shop_name() << endl;
		cout << "Стоимость: " << current->price->get_cost() << " руб." << endl;
		current = current->next;
		cnt++;
		
	}
}

int Queue::print_shops(string name) {
	int cnt = 0;
	int flag = 0;
	LNode* current = head;
	if (head == nullptr) {
		cout << "Список пуст!" << endl;
		return 0;
	}
	
	while (current != nullptr) {
		if (current->price->get_shop_name() == name) {
			if (flag == 0) { cout << "В магазине " << name << " продаются следующие товары:" << endl; flag = 1; }
			cnt++;
			cout << "-----------------" << endl;
			cout << "Название товара: " << current->price->get_name() << endl;
			cout << "Стоимость: " << current->price->get_cost() << " руб." << endl;
			
			}
		current = current->next;
	}
	if (cnt == 0) { cout << "Магазина " << name << " в списке нет" << endl; }
}
void Queue::edit(int number) {
	int cnt = 0;
	int flag = 0;
	int command = 0;
	string input;
	Queue rezerv;
	int input_int = 0;
	LNode* current = head;
	if (head == nullptr) {
		cout << "Список пуст!" << endl;
		return;
	}
	while (cnt != number) {
		if (current->next == nullptr) { cout << "Такой позиции нет в списке" << endl; system("pause"); return; }
		current = current->next;
		cnt++;
	}
	while (command != 4) {
		cout << "-----Товар найден-----" << endl;
		current->price->print();
		cout << "1. Изменить название товара" << endl;
		cout << "2. Изменить название магазина" << endl;
		cout << "3. Изменить стоимость" << endl;
		cout << "4. Отменить редактирование" << endl;
		cin >> command;
		system("cls");
		switch (command) {
		case 1:
			cout << "Введите новое название: ";
			cin >> input;
			current->price->set_name(input);
			cout << "Измененная запись: " << endl;
			current->price->print();
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Введите новое название магазина: ";
			cin >> input;
			current->price->set_shop_name(input);
			cout << "Измененная запись: " << endl;
			current->price->print();
			system("pause");
			system("cls");
			flag = 1;
			break;
		case 3:
			cout << "Введите новое название магазина: ";
			cin >> input_int;
			current->price->set_cost(input_int);
			cout << "Измененная запись: " << endl;
			current->price->print();
			system("pause");
			system("cls");
			break;
		case 4:
			break;
		}
	}
	if (flag == 1) {
		current = head;
		while (current != nullptr) {
			rezerv.add(current->price);
			current = current->next;
		}
		head = rezerv.getHead();
	}
}
void Queue::delet_e(int number) {
	int cnt = 0;
	int flag = 0;
	int command = 0;
	Queue rezerv;
	string input;
	int input_int = 0;
	LNode* current = head;
	if (number == 0) {
		head = current->next;
		return;
	}
	if (head == nullptr) {
		cout << "Список пуст!" << endl;
		return;
	}
	if (head->next == nullptr) {
		head = rezerv.getHead();
		return;
	}
	while (cnt != number-1) {
		if (current->next->next == nullptr) { cout << "Такой позиции нет в списке" << endl; system("pause"); return; }
		current = current->next;
		cnt++;
	}
	current->next = current->next->next;
}
