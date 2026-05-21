#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    
    double result = 0;
    RPN rpn;
    try
    {
        result = rpn.calculate(argv[1]);
        std::cout << result << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    
    return (0);
}