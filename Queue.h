#pragma once
#include "class_price.h"
struct LNode {
	Price* price;
	LNode* next;
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
};