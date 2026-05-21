#include "RPN.hpp"
#include <iostream>
#include <stack>
#include <sstream>
#include <exception>

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
			throw std::runtime_error("Error");
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
		throw std::runtime_error("Error");
	std::stack<double> stack;
	double rightOp, leftOp;
	double result = 0;
	std::stringstream ss1(expression);

	while(ss1 >> token) // 3 4 5 6 15 + - - * *
	{
		if(isdigit(token[0]))
			stack.push(token[0] - '0');
		else if(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
		{
			if(stack.size() < 2) // 1 + 2 gibi bir durumda hata vermesi için
				throw std::runtime_error("Error");	
			rightOp = stack.top();
			stack.pop();
			leftOp = stack.top();
			stack.pop();
			if(token[0] == '+')
				result = leftOp + rightOp;
			else if(token[0] == '-')
				result = leftOp - rightOp;
			else if(token[0] == '*')
				result = leftOp * rightOp;
			else if(token[0] == '/')
			{
				if(rightOp == 0)
					throw std::runtime_error("Error");
				result = leftOp / rightOp;
			}
			stack.push(result);
		}
	}
	if(stack.size() != 1)
		throw std::runtime_error("Error");
	return (stack.top());
}