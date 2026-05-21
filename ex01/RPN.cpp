#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <sstream>

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
    (void)other;
}

RPN& RPN::operator=(const RPN& other)
{
    (void)other;
    return *this;
}

RPN::~RPN()
{
}

//  ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

double RPN::calculate(const std::string& expression) //İçerideki kontrolleri fonksiyonlara bölebilirim
{
    //Input control
	std::stringstream ss(expression);
	std::string token;
	while(ss >> token) //token kontrolü
	{
		if(token.size() != 1 || (!isdigit(token[0]) && token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/')) //iç kısmı fonksiyona ayırabilirim
		{
			std::cerr << "Error: Invalid token '" << token << "' in expression." << std::endl;
			return 1;
		}
	}
	int digitCounter = 0;
	int operatorCounter = 0;
	for(size_t i = 0; i < expression.size(); i++)
	{
		if(isdigit(expression[i]))
			digitCounter++;
		else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
			operatorCounter++;
	}
	if(digitCounter != operatorCounter + 1)
	{
		std::cerr << "Error: Invalid expression. The number of digits must be one more than the number of operators." << std::endl;
		return 1;
	}
	std::stack<double> stack;
	double rightOp, leftOp;
	double result;
	int flag = 0;
	ss.clear();
	while(ss >> token) // 3 4 5 6 7 8 + + - - * *
	{
		if(isdigit(token[0]))
			stack.push(token[0] - '0');
		else if(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
		{
			
		}
	}

	return (0);
}