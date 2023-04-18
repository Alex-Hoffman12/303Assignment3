#include "Queue.h"
#include <iostream>

using namespace std;

int main() {

	int userInput = 0;
	bool userEnd = false;

	Queue queue;

	cout << "Welcome to the queue experience" << endl << endl;

	do {
		cout << "Would you like to:" << endl
			<< "1: Insert a number into the queue" << endl
			<< "2: Remove an item from the queue" << endl
			<< "3: Get the front of the queue" << endl
			<< "4: Get the end of the queue" << endl
			<< "5: Check if the queue is empty" << endl
			<< "6: Check how many elements are in the queue" << endl
			<< "0: Quit the program" << endl << endl;
		cin >> userInput;
		cout << endl;


		switch (userInput) {
		case 1:
			cout << "What would you like to push?" << endl << endl;
			cin >> userInput;
			cout << endl;
			queue.push(userInput);
			queue.printQueue();
			break;
		case 2:
			queue.pop();
			queue.printQueue();
			break;
		case 3:
			if (queue.empty() == false) {
				cout << "The front of the queue is " << queue.front() << endl << endl;
				break;
			}
			cout << "The queue is empty so there is no front." << endl << endl;
			break;
		case 4:
			if (queue.empty() == false) {
				cout << "The back of the queue is " << queue.back() << endl << endl;
				break;
			}
			cout << "The queue is empty so there is no back." << endl << endl;
			break;
		case 5:
			if (queue.empty() == false) {
				cout << "The queue is currently not empty" << endl << endl;
				break;
			}
			cout << "The queue is currently empty" << endl << endl;
			break;
		case 6:
			cout << queue.getQueueCount() << endl << endl;
			break;
		case 0:
			cout << endl << endl << "Thank you for using the queue program. Please come again" << endl << endl;
			userEnd = true;
		}
	} while (userEnd != true);
}