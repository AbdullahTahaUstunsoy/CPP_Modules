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


int RPN::tokenControl(const std::string& expression)
{
	std::stringstream ss(expression);
	std::string token;

	while(ss >> token)
	{
		if(token.size() != 1 || (!isdigit(token[0]) && token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/'))
			return (1);
	}
	return (0);
}

int RPN::digitAndOpControl(const std::string& expression)
{
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
		return(1);
	return (0);
}

int RPN::doOperation(char op, std::stack<double>& stack)
{
	if(stack.size() < 2)
		return (1);
	double rightOp = 0.0;
    double leftOp = 0.0;
    double result = 0.0;
	rightOp = stack.top();
	stack.pop();
	leftOp = stack.top();
	stack.pop();
	if(op == '+')
		result = leftOp + rightOp;
	else if(op == '-')
		result = leftOp - rightOp;
	else if(op == '*')
		result = leftOp * rightOp;
	else if(op == '/')
	{
		if(rightOp == 0)
			return (1);
		result = leftOp / rightOp;
	}
	stack.push(result);
	return (0);
}


double RPN::calculate(const std::string& expression)
{
	if(tokenControl(expression))
		throw std::runtime_error("Error");
	if(digitAndOpControl(expression))
		throw std::runtime_error("Error");

	std::stack<double> stack;
	std::stringstream ss(expression);
	std::string token;

	while(ss >> token)
	{
		if(isdigit(token[0]))
			stack.push(token[0] - '0');
		else if(token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
		{
			if(doOperation(token[0], stack))
				throw std::runtime_error("Error");
		}
	}
	if(stack.size() != 1)
		throw std::runtime_error("Error");
	return (stack.top());
}