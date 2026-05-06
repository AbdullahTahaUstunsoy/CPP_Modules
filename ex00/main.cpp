#include "easyfind.h"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    std::list<int> lst;
    std::vector<int> emptyVec;
    for(int i = 1; i <= 5; i++)
        vec.push_back(i);
    for(int i = 6; i <= 10; i++)
        lst.push_back(i);
    try
    {
        std::vector<int>::iterator it1 = easyfind(vec, 3);
        std::cout << "Value found in the vector: " << *it1 << std::endl;
    }
    catch(const NotFoundException& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it2 = easyfind(vec,42);
        std::cout << "Value found in the vector: " << *it2 << std::endl;
    }
    catch(const NotFoundException& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        std::list<int>::iterator it3 = easyfind(lst, 8);
        std::cout << "Value found in the list: " << *it3 << std::endl;
    }
    catch(const NotFoundException& e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::list<int>::iterator it4 = easyfind(lst, 42);
        std::cout << "Value found in the list: " << *it4 << std::endl;
    }
    catch(const NotFoundException& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try
    {
        std::vector<int>::iterator it5 = easyfind(emptyVec, 42);
        std::cout << "Value found in the empty vector: " << *it5 << std::endl;
    }
    catch(const NotFoundException& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}