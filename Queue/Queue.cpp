#include "Queue.h"
#include <iostream>

using namespace std;

void Queue::push(int data) {

	if (empty() == true) {
		Node* newNode = new Node(data);
		head = newNode;
		tail = newNode;
		queueCount++;
	}
	else {
		Node* newNode = new Node(data);
		tail->next = newNode;
		tail = newNode;
		tail->next = NULL;
		queueCount++;
	}
	
}

void Queue::pop() {
	if (empty() == false) {
		if (head->next == NULL) {
			delete head;
			queueCount--;
		}
		else {
			Node* oldTop = head;
			head = head->next;
			delete oldTop;
			queueCount--;
		}
	}
	else
		cout << endl << "Can not pop because queue is empty" << endl << endl;
}

const int Queue::front() const {
	return(head->data);
}

const int Queue::back() const {
	return(tail->data);
}

bool Queue::empty() {
	if (queueCount == 0)
		return (true);
	return(false);
}

const int Queue::getQueueCount() const {
	return(queueCount);
}


void Queue::printQueue() {
	cout << endl;
	if (empty() == false) {
		Node* tempNode = head;
		cout << head->data;
		for (int i = 1; i < queueCount; i++) {
			tempNode = tempNode->next;
			cout << " -> " << tempNode->data;
		}
		cout << endl << endl;
	}
}