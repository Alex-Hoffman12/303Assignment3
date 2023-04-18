#include "PrePostFix.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

	PrePostFix fix;

	string userInput;

	cout << "Welcome to the InFix to PostFix converter..." << endl << endl << endl;

	cout << "Please enter the equation you would like to convert" << endl << endl;
	cin >> userInput;
	cout << endl << endl;
	
	fix.setPreFix(userInput);
	
	cout << "Checking for paratheses balance ..." << endl << endl;

	if (fix.balancedParenthesesCheck() == true) {
		cout << "The equations paratheses are balanced" << endl << endl;
		cout << "Starting conversion process..." << endl << endl;
		fix.postFixConvert();
	}
	else {
		cout << "The equations paratheses are not balanced. Finishing program." << endl << endl;
		return -1;
	}


	return 0;
}