#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        int tokenControl(const std::string& expression);
        int digitAndOpControl(const std::string& expression);
        int doOperation(char op, std::stack<double>& stack);
        double calculate(const std::string& expression);
};


#endif