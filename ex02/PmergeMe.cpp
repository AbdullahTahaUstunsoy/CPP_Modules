#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0)
{
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    _vectorContainer = other._vectorContainer;
    _dequeContainer = other._dequeContainer;
    _vectorTime = other._vectorTime;
    _dequeTime = other._dequeTime;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
        _vectorContainer = other._vectorContainer;
        _dequeContainer = other._dequeContainer;
        _vectorTime = other._vectorTime;
        _dequeTime = other._dequeTime;
    }
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::insertElementsToVector(const int argc, const char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        std::stringstream ss(argv[i]);
        std::string token;

        while(ss >> token)
        {
            _vectorContainer.push_back(std::atoi(token.c_str()));
        }
    }
}

void PmergeMe::insertElementsToDeque(const int argc, const char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        std::stringstream ss(argv[i]);
        std::string token;

        while(ss >> token)
        {
            _dequeContainer.push_back(std::atoi(token.c_str()));
        }
    }
}

void PmergeMe::pairVector(std::vector<int>& container)
{
    bool hasStraggler = false;
    int straggler = -1;
    if(container.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = container.back();
        container.pop_back();
    }
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size(); i+=2)
    {
        if(container[i] >= container[i + 1])
            pairs.push_back(std::pair<int,int>(container[i], container[i + 1]));
        else
            pairs.push_back(std::pair<int, int>(container[i + 1], container[i]));
    }
}

void PmergeMe::recursiveSortVector(std::vector<std::pair<int, int> >& pairs)
{
    if(pairs.size() <= 1)
        return;
    std::vector<std::pair<int, int> > higherPairs;
    bool hasStraggler = false;
    std::pair<int, int> stragglerPair;

    if (pairs.size() % 2 != 0)
    {
        hasStraggler = true;
        stragglerPair = pairs.back();
        pairs.pop_back(); //    Vektörü çift sayıda bırakıyoruz
    }
    for (size_t i = 0; i < pairs.size(); i += 2)
    {
        if (pairs[i].first >= pairs[i + 1].first)
        {
            higherPairs.push_back(std::pair<int, int>(pairs[i].first, pairs[i + 1].first));
        }
        else
        {
            higherPairs.push_back(std::pair<int, int>(pairs[i + 1].first, pairs[i].first));
        }
    }
    recursiveSortVector(higherPairs);
}