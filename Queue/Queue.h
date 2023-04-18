#ifndef QUEUE_H_
#define QUEUE_H_

#include <stddef.h>

struct Node {
	Node* next;
	int data;

	Node(int dataItem, Node* next_prt = NULL) : data(dataItem), next(next_prt) {}
};

class Queue
{
private:
	Node* head = NULL;
	Node* tail = NULL;
	size_t queueCount = 0;

public:
	void push(int data);						// Pushes to the back of the queue

	void pop();									// Pops the front of the queue

	const int front() const;					// Returns the front of the queue

	const int back() const;						// return the back of the queue

	bool empty();								// Checks if queue is empty

	const int getQueueCount() const;			// Gets the size of the queue

	void printQueue();							// Prints the queue

};

#endif // !QUEUE_H_