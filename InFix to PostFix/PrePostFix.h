#ifndef PREPOSFIX_H_
#define PREPOSTFIX_H_

#include <stack>
#include <string>
#include <vector>

class PrePostFix
{

private:
	std::stack<char> paraStack;
	std::stack<char> opStack;
	std::string preFix = "";
	std::string finalStr = "";


public:

	void setPreFix(std::string str);

	std::string getPreFix();

	void setFinalStr(std::string str);

	std::string getFinalStr();

	bool balancedParenthesesCheck();

	int opValue(char op);

	void opCompare(char op);

	int postFixConvert();

};

#endif // !PREPOSTFIX_H_