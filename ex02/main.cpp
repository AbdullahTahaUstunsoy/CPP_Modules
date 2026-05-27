#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <climits>

int argControl(int argc, char **argv) // edge case'leri kontrol edicem
{
    for(int i = 1; i < argc; i++) //05 , 007 gibi sayılar kontrole eklenmeli mi ? bence gerek yok
    {
        std::stringstream ss(argv[i]);
        std::string token;

        while(ss >> token)
        {
            if(token[0] == '-')
            {
                std::cerr << "Error" << std::endl;
                return (1);
            }
            if(token[0] == '0' || (token[0] != '+' && !isdigit(token[0])))
            {
                std::cerr << "Error" << std::endl;
                return (1);
            }
            if(token[0] == '+')
            {
                if (token.size() == 1) 
                {
                    std::cerr << "Error" << std::endl;
                    return (1);
                }
                for(size_t j = 1; j < token.size(); j++)
                {
                    if(!isdigit(token[j]))
                    {
                        std::cerr << "Error" << std::endl;
                        return (1);
                    }
                }
            }
            else
            {
                for(size_t j = 0; j < token.size(); j++)
                {
                    if(!isdigit(token[j]))
                    {
                        std::cerr << "Error" << std::endl;
                        return (1);
                    }
                }
            }
            long longValue = std::strtol(token.c_str(), NULL, 10);
            if (longValue > INT_MAX)
            {
                std::cerr << "Error" << std::endl;
                return (1);
            }
        }
    }
    return (0);
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    if(argControl(argc, argv))
        return (1);
    
    PmergeMe pmergeme;
    pmergeme.insertElementsToVector(argc, argv);
    pmergeme.insertElementsToDeque(argc, argv);
    return (0);
}