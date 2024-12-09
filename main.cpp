#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Queue.h"
#include "class_price.h"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int stringToNumber(const std::string& str) {
	// Проверяем, является ли строка пустой
	// Проверяем, является ли строка числом
	for (char c : str) {
		if (!std::isdigit(c) && c != '.' && c != '-') {
			throw std::invalid_argument("Введено не число! Повторите попытку");
		}
	}
	return std::stoi(str);
}

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Queue stack;
	int command = 0;
	int command2 = 0;
	int input_int = 0;
	Price* a = new Price();
	string input_int_exc;
	ifstream inputFile("text.txt"); // для второго задания
	stringstream buffer; 
	buffer << inputFile.rdbuf(); //перенаправляем поток на buffer, для работы
	string text = buffer.str(); //получаем строку из файла
	vector<string> sentences; //вектор для предложений
	string sentence; //предложение
	istringstream stream(text); //
	

	// Проверяем, удалось ли открыть файл
	if (!inputFile.is_open()) {
		cerr << "Ошибка открытия файла!" << endl;
		return 1;
	}
	int number = 0;
	// Закрываем файл
	inputFile.close();

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
				system("cls");
				cout << "-----Меню-----" << endl;
				cout << "1. Добавить новый объект в список" << endl; //+
				cout << "2. Просмотреть список" << endl; //+
				cout << "3. Найти товары " << endl; //+
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
					cin >> input_int_exc;
					try {
						number = stringToNumber(input_int_exc);
					}
					catch (const invalid_argument& e) {
						cerr << "Вызвано исключение: " << e.what() << endl; // Обработка исключения
						system("pause");
						break;
					}
					
					a->set_shop_name(input);
					a->set_cost(number);
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
					cout << "Введите название товара: ";
					cin >> input;
					system("cls");
					stack.print_products(input);
					system("pause");
					system("cls");
					break;
				case 4:
					system("cls");
					cout << "Введите номер товара в списке, который необходимо отредактировать: ";

					cin >> input_int_exc;
					try {
						number = stringToNumber(input_int_exc);
					}
					catch (const invalid_argument& e) {
						cerr << "Вызвано исключение: " << e.what() << endl; // Обработка исключения
						system("pause");
						break;
					}

					system("cls");
					stack.edit(number-1);
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

				while (getline(stream, sentence, '.')) { //разделитель - точка
					sentence.erase(0, sentence.find_first_not_of(" \n\r\t")); // Убираем пробелы в начале
					sentence.erase(sentence.find_last_not_of(" \n\r\t") + 1); // Убираем пробелы в конце

					if (!sentence.empty()) { // Добавляем только непустые предложения
						sentences.push_back(sentence + '.'); // Добавляем точку обратно
					}
				}

				// Выводим предложения
				for (size_t i = sentences.size(); i > 0; --i) {
					cout << sentences[i - 1] << endl; // Выводим элемент с индексом i - 1
				}
				system("pause");
			break;
		case 3:
			return 0;
			break;
		}
	}
	


}