#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>

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
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::startTimer()
{
    gettimeofday(&_startTime, NULL);
}

void PmergeMe::stopTimer()
{
    gettimeofday(&_endTime, NULL);
}

double PmergeMe::getElapsedTimeUs() const
{
    long sec = _endTime.tv_sec - _startTime.tv_sec;
    long usec = _endTime.tv_usec - _startTime.tv_usec;

    if (usec < 0)
    {
        sec -= 1;
        usec += 1000000; // 1 saniye 1.000.000 mikrosaniye
    }

    return (sec * 1000000.0) + usec;
}

size_t PmergeMe::getVectorSize() const
{
    return _vectorContainer.size();
}

void PmergeMe::printBeforeVector() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vectorContainer.size(); i++)
    {
        std::cout << _vectorContainer[i];
        if (i < _vectorContainer.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfterVector() const
{
    std::cout << "After:  ";
    for (size_t i = 0; i < _vectorContainer.size(); i++)
    {
        std::cout << _vectorContainer[i];
        if (i < _vectorContainer.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::insertElementsToVector(int argc, char **argv)
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

void PmergeMe::insertElementsToDeque(int argc, char **argv)
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

void PmergeMe::fordJhonsonVector()
{
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = false;
    int straggler = -1;
    startTimer();
    pairVector(_vectorContainer, pairs, straggler, hasStraggler);
    if (pairs.empty())
    {
        if (hasStraggler)
            _vectorContainer.push_back(straggler);
        stopTimer();
        return;
    }
    recursiveSortVector(pairs);
    splitChains(pairs, straggler, hasStraggler);
    stopTimer();
}

void PmergeMe::pairVector(std::vector<int>& container, std::vector<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler)
{
    if(container.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = container.back();
        container.pop_back();
    }
    for (size_t i = 0; i < container.size(); i+=2)
    {
        if(container[i] >= container[i + 1])
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        else
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
    }
}

void PmergeMe::recursiveSortVector(std::vector<std::pair<int, int> >& pairs)
{
    if (pairs.size() <= 1)
        return;

    int hasStraggler = 0;
    if(pairs.size() % 2 != 0)
        hasStraggler = 1;
    std::pair<int, int> straggler;
    if (hasStraggler)
    {
        straggler = pairs.back();
        pairs.pop_back();
    }

    // turnuva: winner ve loser'ları ayır
    std::vector<std::pair<int, int> > winners;
    std::vector<std::pair<int, int> > losers;
    for (size_t i = 0; i < pairs.size(); i += 2)
    {
        if (pairs[i].first >= pairs[i + 1].first)
        {
            winners.push_back(pairs[i]);
            losers.push_back(pairs[i + 1]);
        }
        else
        {
            winners.push_back(pairs[i + 1]);
            losers.push_back(pairs[i]);
        }
    }

    recursiveSortVector(winners);
    for (size_t i = 0; i < losers.size(); i++)
    {
        std::vector<std::pair<int, int> >::iterator it = winners.begin();
        while (it != winners.end() && it->first < losers[i].first)
            ++it;
        winners.insert(it, losers[i]); //it iteratorünün gösterdiği pozisyonun önüne ekler.
    }

    // Bu seviyedeki straggler (çift bulamayan pair) varsa ekle
    if (hasStraggler)
    {
        std::vector<std::pair<int, int> >::iterator it = winners.begin();
        while (it != winners.end() && it->first < straggler.first)
            ++it;
        winners.insert(it, straggler);
    }
    pairs = winners;
}


void PmergeMe::splitChains(std::vector<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler)
{
    std::vector<int> main_chain;
    std::vector<int> pend;

    main_chain.push_back(pairs[0].second);

    for (size_t i = 0; i < pairs.size(); i++)
        main_chain.push_back(pairs[i].first);

    for (size_t i = 1; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);

    if (hasStraggler)
        pend.push_back(straggler);

    std::vector<size_t> jacobSequence;
    jacobSequence.push_back(1);
    jacobSequence.push_back(3);
    while (jacobSequence.back() < pend.size())
    {
        size_t next = jacobSequence[jacobSequence.size() - 1]
                    + 2 * jacobSequence[jacobSequence.size() - 2];
        jacobSequence.push_back(next);
    }

    size_t lastInsertedIdx = 0;
    //1 10 20 30 40 50
    //     2  3  4  5  7
    for (size_t k = 0; k < jacobSequence.size(); k++)
    {
        size_t targetJacobIdx = jacobSequence[k];
        if (targetJacobIdx > pend.size())
            targetJacobIdx = pend.size();

        for (size_t i = targetJacobIdx; i > lastInsertedIdx; i--)
        {
            int itemToInsert = pend[i - 1];
            std::vector<int>::iterator it =
                std::lower_bound(main_chain.begin(), main_chain.end(), itemToInsert); //lower_bound sıralı bir dizide verilen değerden küçük olmayan ilk elemanın pozisyonunu bulur.
            main_chain.insert(it, itemToInsert); //insert fonksiyonu da iteratorun gösterdiği yerin önüne ekler. mesela main_chain = [1, 10, 20, 30, 40, 50], 4 insert edilecek. lower_bound 10 gelir, insert 10'un önüne insert eder yani 1 4 10 20 30 ..
        }
        lastInsertedIdx = targetJacobIdx;
    }
    _vectorContainer = main_chain;
}