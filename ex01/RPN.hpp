#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN
{
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);

        double calculate(const std::string& expression);
};


#endif