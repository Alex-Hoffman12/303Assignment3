#include "PrePostFix.h"
#include <iostream>
#include <string>

using namespace std;

void PrePostFix::setPreFix(string str) {preFix = str;}

string PrePostFix::getPreFix() {return preFix;};

void PrePostFix::setFinalStr(string str) { finalStr = str; }

string PrePostFix::getFinalStr() { return finalStr; };

bool PrePostFix::balancedParenthesesCheck() {
	char temp;
	int openPara = 0;
	
	for (int i = 0; i < preFix.length(); i++) {
		if (preFix[i] == '(' || preFix[i] == '{' || preFix[i] == '[') {
			paraStack.push(preFix[i]);
			openPara++;
		}
		if (preFix[i] == ')' || preFix[i] == '}' || preFix[i] == ']') {
			if (openPara == 0)
				return false;
			else {
				temp = paraStack.top();
				if (temp == '(' && preFix[i] != ')')
					return false;
				else if (temp == '{' && preFix[i] != '}')
					return false;
				else if (temp == '[' && preFix[i] != ']')
					return false;
				else
					openPara--;
			}
		}
	}

	if (openPara != 0)
		return false;

	return true;
}

int PrePostFix::opValue(char op) {
	if (op == '(' || op == '{' || op == '[')
		return 4;
	else if (op == ')' || op == '}' || op == ']')
		return 3;
	else if (op == '%' || op == '*' || op == '/')
		return 2;
	else if (op == '+' || op == '-')
		return 1;
	else
		return -1;
}

void PrePostFix::opCompare(char op) {
	if (opStack.empty()) {
		opStack.push(op);
	}
	else {
		if (opValue(op) == 4)
			opStack.push(op);
		else if (opValue(op) == 3) {
			while (opValue(opStack.top()) != 4) {
				finalStr = finalStr + opStack.top() + " ";
				//cout << finalStr << endl;
				opStack.pop();
			}
			opStack.pop();
		}
		else if (opValue(opStack.top()) >= opValue(op) && opValue(opStack.top()) != 4) {
			finalStr = finalStr + opStack.top()+ " ";
			opStack.pop();
			opStack.push(op);
		}
		else
			opStack.push(op);
	}
}

int PrePostFix::postFixConvert() {
	
	bool multiOp = false;

	for (int i = 0; i < preFix.length(); i++) {
		if (isdigit(preFix[i]) || isalpha(preFix[i])) {
			finalStr = finalStr + preFix[i] + " ";
			multiOp = false;
		}
		else {
			if (opValue(preFix[i]) == -1) {
				cout << endl << "User used something other than +, -, *, /, or % when doing arithmetic" << endl << endl;
				return -3;
			}	
			else if (multiOp == true) {
				cout <<  endl <<  "User can not have more than one operator next to each other" << endl;
				return -2;
			}
			else {
				opCompare(preFix[i]);
				if (opValue(preFix[i]) != 3 && opValue(preFix[i]) != 4)
					multiOp = true;
			}
		}
	}

	while (!opStack.empty()) {
		finalStr = finalStr + opStack.top() + " ";
		opStack.pop();
	}

	cout << endl << endl << finalStr << endl << endl;

	return 0;
}


