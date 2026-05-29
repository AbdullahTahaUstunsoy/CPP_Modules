#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <climits>
#include <cstdlib>
#include <iomanip>

int isAllDigits(std::string& token, int start)
{
    for(size_t j = start; j < token.size(); j++)
    {
        if(!isdigit(token[j]))
            return (1);
    }
    return (0);
}

int isAllZeros(std::string& token)
{
    int counter = 0;
    for(size_t i = 0; i < token.size(); i++)
    {
        if(token[i] != '0')
            counter++;
    }
    if(counter == 0)
        return (1);
    return (0);
}

int isValidToken(std::string& token)
{
    int start = 0;
    if(token[0] == '0' && token.size() == 1)
        return (1);
    if((token[0] != '+' && !isdigit(token[0])))
        return (1);
    if(token[0] == '+')
    {
        if (token.size() == 1)
            return (1);
        if(token.size() > 1 && token[1] == '0')
            return (1);
        start = 1;
        if(isAllDigits(token, start))
            return (1);
    }
    else
    {
        if(isAllDigits(token, start))
            return (1);
    }
    if(isAllZeros(token))
        return (1);
    long longValue = std::strtol(token.c_str(), NULL, 10);
    if (longValue > INT_MAX)
        return (1);
    return (0);
}

int argControl(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        std::stringstream ss(argv[i]);
        std::string token;

        while(ss >> token)
        {
            if(isValidToken(token))
                return (1);
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc < 2 || argControl(argc, argv))
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    PmergeMe pmergeme;
    pmergeme.insertElementsToVector(argc, argv);
    pmergeme.insertElementsToDeque(argc, argv);
    pmergeme.printBeforeVector();
    pmergeme.fordJhonsonVector();
    pmergeme.fordJhonsonDeque();
    pmergeme.printAfterVector();
    pmergeme.printTimerResults();
    return (0);
}