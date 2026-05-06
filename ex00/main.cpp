#include "easyfind.h"
#include <iostream>
#include <vector>
#include <list>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

int main()
{
    std::vector<int> vec;
    std::list<int> lst;
    std::vector<int> emptyVec;
    std::list<int> duplicateLst;
    for(int i = 1; i <= 5; i++)
        vec.push_back(i);
    for(int i = 6; i <= 10; i++)
        lst.push_back(i);
    duplicateLst.push_back(1);
    duplicateLst.push_back(3);
    duplicateLst.push_back(3);
    duplicateLst.push_back(5);
    try
    {
        std::vector<int>::iterator it1 = easyfind(vec, 3);
        std::cout << BLUE << "Value found in the vector: " << RESET << *it1 << std::endl;
    }
    catch(const NotFoundException& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    try
    {
        std::vector<int>::iterator it2 = easyfind(vec,42);
        std::cout << BLUE << "Value found in the vector: " << RESET << *it2 << std::endl;
    }
    catch(const NotFoundException& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    try
    {
        std::list<int>::iterator it3 = easyfind(lst, 8);
        std::cout << BLUE <<"Value found in the list: " << RESET << *it3 << std::endl;
    }
    catch(const NotFoundException& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    try
    {
        std::list<int>::iterator it4 = easyfind(lst, 42);
        std::cout << BLUE << "Value found in the list: " << RESET << *it4 << std::endl;
    }
    catch(const NotFoundException& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    try
    {
        std::vector<int>::iterator it5 = easyfind(emptyVec, 42);
        std::cout << BLUE << "Value found in the empty vector: " << RESET << *it5 << std::endl;
    }
    catch(const NotFoundException& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    try
    {
        std::list<int>::iterator it6 = easyfind(duplicateLst, 3);
        std::cout << BLUE << "Index: " << RESET << std::distance(duplicateLst.begin(), it6) << std::endl; //1 olmalıdır //std::distance(begin, it) begin'den it'e kadar kaç adım atıldığını sayar.
    }
    catch(const NotFoundException& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    
    return (0);
}