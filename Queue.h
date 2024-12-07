#pragma once
#include "class_price.h"
struct LNode {
	Price* price;
	LNode* next;
	LNode(Price* newprice) : price(newprice), next(nullptr) {}
	LNode() : price(new Price("a", "a", 0)), next(nullptr) {}
};

class Queue {
private:
	LNode* head;
	size_t size;
public:
	Queue() : head(nullptr), size(0) {};
	void add(Price* price);
	void print() const;
	LNode* getHead() { return head; }
	void setHead(LNode* newHead) { head = newHead; }
	int print_shops(string name);
	void edit(int number);
	void delet_e(int number);
};