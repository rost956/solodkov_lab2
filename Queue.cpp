#include "Queue.h"
void Queue::add(Price* price) {
	LNode* newNode = new LNode{ price };
	if (head == nullptr) {
		head = newNode;
	}
	else {
		LNode* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;

		//сюда сортировку

	}
	++size;
}
