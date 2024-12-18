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
	// ���������, �������� �� ������ ������
	// ���������, �������� �� ������ ������
	for (char c : str) {
		if (!std::isdigit(c) && c != '.' && c != '-') {
			throw std::invalid_argument("������� �� �����! ��������� �������");
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
	ifstream inputFile("text.txt"); // ��� ������� �������
	stringstream buffer; 
	buffer << inputFile.rdbuf(); //�������������� ����� �� buffer, ��� ������
	string text = buffer.str(); //�������� ������ �� �����
	vector<string> sentences; //������ ��� �����������
	string sentence; //�����������
	istringstream stream(text); //
	

	// ���������, ������� �� ������� ����
	if (!inputFile.is_open()) {
		cerr << "������ �������� �����!" << endl;
		return 1;
	}
	int number = 0;
	// ��������� ����
	inputFile.close();

	/*Price* b = new Price("aaa", "bbb", 111); // ����� ����������
	a = b;
	a->print();*/
	string input;
	while (command != 3) {
		system("cls");
		cout << "-----����-----" << endl;
		cout << "1. 1 �������" << endl;
		cout << "2. 2 �������" << endl;
		cout << "3. ������� ���������" << endl;
		cout << ">>> ";
		cin >> command;
		getchar();
		switch (command) {
		case 1:
			command2 = 0;
			system("cls");
			while (command2 != 6) { //�������� ����� ��� ����
				system("cls");
				cout << "-----����-----" << endl;
				cout << "1. �������� ����� ������ � ������" << endl; //+
				cout << "2. ����������� ������" << endl; //+
				cout << "3. ����� ������ " << endl; //+
				cout << "4. ��������������� �����" << endl;  //+
				cout << "5. ������� ������" << endl; //+
				cout << "6. ����� � ���� ������ �������" << endl;
				cout << ">>> ";
				cin >> command2;
				getchar();
				
				switch (command2) {
				case 1:
					
					system("cls");
					cout << "������� �������� ������: ";
					cin >> input;
					a->set_name(input);
					cout << "������� �������� ��������: ";
					cin >> input;
					cout << "������� ���������: ";
					cin >> input_int_exc;
					try {
						number = stringToNumber(input_int_exc);
					}
					catch (const invalid_argument& e) {
						cerr << "������� ����������: " << e.what() << endl; // ��������� ����������
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
					cout << "������� �������� ������: ";
					cin >> input;
					system("cls");
					stack.print_products(input);
					system("pause");
					system("cls");
					break;
				case 4:
					system("cls");
					cout << "������� ����� ������ � ������, ������� ���������� ���������������: ";

					cin >> input_int_exc;
					try {
						number = stringToNumber(input_int_exc);
					}
					catch (const invalid_argument& e) {
						cerr << "������� ����������: " << e.what() << endl; // ��������� ����������
						system("pause");
						break;
					}

					system("cls");
					stack.edit(number-1);
					system("cls");
					break;
				case 5:
					system("cls");
					cout << "������� ����� ������ � ������, ������� ���������� �������: ";
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

				while (getline(stream, sentence, '.')) { //����������� - �����
					sentence.erase(0, sentence.find_first_not_of(" \n\r\t")); // ������� ������� � ������
					sentence.erase(sentence.find_last_not_of(" \n\r\t") + 1); // ������� ������� � �����

					if (!sentence.empty()) { // ��������� ������ �������� �����������
						sentences.push_back(sentence + '.'); // ��������� ����� �������
					}
				}

				// ������� �����������
				for (size_t i = sentences.size(); i > 0; --i) {
					cout << sentences[i - 1] << endl; // ������� ������� � �������� i - 1
				}
				system("pause");
			break;
		case 3:
			return 0;
			break;
		}
	}
	


}