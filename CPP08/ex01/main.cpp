#include "Span.hpp"
#include <ctime>   // std::time
#include <cstdlib> // std::rand, std::srand
#include <list>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

int main()
{
    std::srand(std::time(NULL));

    std::cout << BLUE << "---Subject Test---" << RESET << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << BLUE << "---Empty Span Test---" << RESET << std::endl;
    try
    {        
        Span emptySpan = Span(5);
        emptySpan.shortestSpan();
    }
    catch(const Span::NoSpanException& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "---One Element Span Test---" << RESET << std::endl;
    try
    {
        Span emptySpan = Span(5);
        emptySpan.addNumber(42);
        emptySpan.shortestSpan();
    }
    catch(const Span::NoSpanException& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "---Container is Full Test 1---" << RESET << std::endl;
    try
    {
        Span fullSpan = Span(3);
        fullSpan.addNumber(1);
        fullSpan.addNumber(2);
        fullSpan.addNumber(3);
        fullSpan.addNumber(4); //exception fırlatmalı
    }
    catch(const Span::ContainerFullException& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    std::cout << BLUE << "---Container is Full Test 2---" << RESET << std::endl;
    try
    {
        unsigned int n = 11000;
        Span sp(n);
        std::vector<int> randomNumbers;

        for (unsigned int i = 0; i < n; ++i) {
            randomNumbers.push_back(std::rand());
        }
        sp.addRange(randomNumbers.begin(), randomNumbers.end());
        sp.addNumber(42); //exception fırlatmalı
    }
    catch(const Span::ContainerFullException& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    std::cout << BLUE << "--- Printing the Container ---" << RESET << std::endl;
    try
    {
        Span sp(15);
        sp.addNumber(5);
        sp.addNumber(8);
        std::list<int> moreNumbers; //list ile de ekleyebildiğimizi göstermek için (çünkü addRange bir template function) list container kullandım
        moreNumbers.push_back(12);
        moreNumbers.push_back(42);
        moreNumbers.push_back(3);
        moreNumbers.push_back(17);
        moreNumbers.push_back(9);
        sp.addRange(moreNumbers.begin(), moreNumbers.end());
        std::cout << sp << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    return 0;
}