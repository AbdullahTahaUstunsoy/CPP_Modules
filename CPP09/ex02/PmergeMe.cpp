#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>

PmergeMe::PmergeMe()
{
    memset(&_vectorStartTime, 0, sizeof(_vectorStartTime));
    memset(&_vectorEndTime,   0, sizeof(_vectorEndTime));
    memset(&_dequeStartTime,  0, sizeof(_dequeStartTime));
    memset(&_dequeEndTime,    0, sizeof(_dequeEndTime));
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    _vectorContainer = other._vectorContainer;
    _dequeContainer = other._dequeContainer;
    _vectorStartTime = other._vectorStartTime;
    _vectorEndTime = other._vectorEndTime;
    _dequeStartTime = other._dequeStartTime;
    _dequeEndTime = other._dequeEndTime;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
        _vectorContainer = other._vectorContainer;
        _dequeContainer = other._dequeContainer;
        _vectorStartTime = other._vectorStartTime;
        _vectorEndTime = other._vectorEndTime;
        _dequeStartTime = other._dequeStartTime;
        _dequeEndTime = other._dequeEndTime;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::startTimerVector()
{
    gettimeofday(&_vectorStartTime, NULL);
}

void PmergeMe::stopTimerVector()
{
    gettimeofday(&_vectorEndTime, NULL);
}

double PmergeMe::getElapsedTimeUsVector() const
{
    long sec = _vectorEndTime.tv_sec - _vectorStartTime.tv_sec;
    long usec = _vectorEndTime.tv_usec - _vectorStartTime.tv_usec;

    if (usec < 0) //mikrosaniye hesaplanırken negatif gelebiliyor, o durumdaki hata payını önlemek için
    {
        sec -= 1;
        usec += 1000000;
    }

    return (sec * 1000000.0) + usec;
}

size_t PmergeMe::getSizeVector() const
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

void PmergeMe::fordJhonsonVector()
{
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = false;
    int straggler = -1;
    startTimerVector();
    pairVector(_vectorContainer, pairs, straggler, hasStraggler);
    if (pairs.empty())
    {
        if (hasStraggler)
            _vectorContainer.push_back(straggler);
        stopTimerVector();
        return;
    }
    recursiveSortVector(pairs);
    std::vector<int> main_chain;
    std::vector<int> pend;
    splitChainsVector(pairs, straggler, hasStraggler, main_chain, pend);
    insertWithJacobsthalVector(pend, main_chain);
    stopTimerVector();
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

void PmergeMe::tournamentVector(std::vector<std::pair<int, int> >& pairs,
    std::vector<std::pair<int, int> >& winners, std::vector<std::pair<int, int> >& losers)
{
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
}

void PmergeMe::insertLoserPairs(std::vector<std::pair<int, int> >& winners, std::vector<std::pair<int, int> >& losers)
{
    for (size_t i = 0; i < losers.size(); i++)
    {
        std::vector<std::pair<int, int> >::iterator it = winners.begin();
        while (it != winners.end() && it->first < losers[i].first)
            ++it;
        winners.insert(it, losers[i]);
    }
}

void PmergeMe::insertStragglerPair(int& hasStraggler, std::pair<int, int>& straggler, std::vector<std::pair<int, int> >& winners)
{
    if (hasStraggler)
    {
        std::vector<std::pair<int, int> >::iterator it = winners.begin();
        while (it != winners.end() && it->first < straggler.first)
            ++it;
        winners.insert(it, straggler);
    }
}

void PmergeMe::isThereStragglerVector(int& hasStraggler, std::pair<int, int>& straggler, std::vector<std::pair<int, int> >& pairs)
{
    if(pairs.size() % 2 != 0)
        hasStraggler = 1;

    if (hasStraggler)
    {
        straggler = pairs.back();
        pairs.pop_back();
    }
}

void PmergeMe::recursiveSortVector(std::vector<std::pair<int, int> >& pairs)
{
    if (pairs.size() <= 1)
        return;

    int hasStraggler = 0;
    std::pair<int, int> straggler;
    isThereStragglerVector(hasStraggler, straggler, pairs);
    std::vector<std::pair<int, int> > winners;
    std::vector<std::pair<int, int> > losers;
    tournamentVector(pairs, winners, losers);
    recursiveSortVector(winners);
    insertLoserPairs(winners, losers);
    insertStragglerPair(hasStraggler, straggler, winners);
    pairs = winners; //çiftler küçükten büyüğe sıralanmış durumda artık
}

void PmergeMe::splitChainsVector(std::vector<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler,
    std::vector<int>& main_chain, std::vector<int>& pend)
{
    main_chain.push_back(pairs[0].second);

    for (size_t i = 0; i < pairs.size(); i++)
        main_chain.push_back(pairs[i].first);

    for (size_t i = 1; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);

    if (hasStraggler)
        pend.push_back(straggler);
}

void PmergeMe::insertWithJacobsthalVector(std::vector<int>& pend, std::vector<int>& main_chain)
{
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
    for (size_t k = 0; k < jacobSequence.size(); k++)
    {
        size_t targetJacobIdx = jacobSequence[k];
        if (targetJacobIdx > pend.size())
            targetJacobIdx = pend.size();

        for (size_t i = targetJacobIdx; i > lastInsertedIdx; i--)
        {
            int itemToInsert = pend[i - 1];
            std::vector<int>::iterator it =
                std::lower_bound(main_chain.begin(), main_chain.end(), itemToInsert);
            main_chain.insert(it, itemToInsert);
        }
        lastInsertedIdx = targetJacobIdx;
    }
    _vectorContainer = main_chain;
}

void PmergeMe::startTimerDeque()
{
    gettimeofday(&_dequeStartTime, NULL);
}

void PmergeMe::stopTimerDeque()
{
    gettimeofday(&_dequeEndTime, NULL);
}

double PmergeMe::getElapsedTimeUsDeque() const
{
    long sec  = _dequeEndTime.tv_sec  - _dequeStartTime.tv_sec;
    long usec = _dequeEndTime.tv_usec - _dequeStartTime.tv_usec;
    if (usec < 0)
    {
        sec  -= 1;
        usec += 1000000;
    }
    return (sec * 1000000.0) + usec;
}

size_t PmergeMe::getSizeDeque() const
{
    return _dequeContainer.size();
}

void PmergeMe::printBeforeDeque() const
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _dequeContainer.size(); i++)
    {
        std::cout << _dequeContainer[i];
        if (i < _dequeContainer.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printAfterDeque() const
{
    std::cout << "After:  ";
    for (size_t i = 0; i < _dequeContainer.size(); i++)
    {
        std::cout << _dequeContainer[i];
        if (i < _dequeContainer.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
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

void PmergeMe::fordJhonsonDeque()
{
    std::deque<std::pair<int, int> > pairs;
    bool hasStraggler = false;
    int straggler = -1;
    startTimerDeque();
    pairDeque(_dequeContainer, pairs, straggler, hasStraggler);
    if (pairs.empty())
    {
        if (hasStraggler)
            _dequeContainer.push_back(straggler);
        stopTimerDeque();
        return;
    }
    recursiveSortDeque(pairs);
    std::deque<int> main_chain;
    std::deque<int> pend;
    splitChainsDeque(pairs, straggler, hasStraggler, main_chain, pend);
    insertWithJacobsthalDeque(pend, main_chain);
    stopTimerDeque();
}

void PmergeMe::pairDeque(std::deque<int>& container, std::deque<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler)
{
    if (container.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = container.back();
        container.pop_back();
    }
    for (size_t i = 0; i < container.size(); i += 2)
    {
        if (container[i] >= container[i + 1])
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        else
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
    }
}

void PmergeMe::tournamentDeque(std::deque<std::pair<int, int> >& pairs,
    std::deque<std::pair<int, int> >& winners, std::deque<std::pair<int, int> >& losers)
{
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
}

void PmergeMe::insertLoserPairsDeque(std::deque<std::pair<int, int> >& winners,
    std::deque<std::pair<int, int> >& losers)
{
    for (size_t i = 0; i < losers.size(); i++)
    {
        std::deque<std::pair<int, int> >::iterator it = winners.begin();
        while (it != winners.end() && it->first < losers[i].first)
            ++it;
        winners.insert(it, losers[i]);
    }
}

void PmergeMe::insertStragglerPairDeque(int& hasStraggler, std::pair<int, int>& straggler,
    std::deque<std::pair<int, int> >& winners)
{
    if (hasStraggler)
    {
        std::deque<std::pair<int, int> >::iterator it = winners.begin();
        while (it != winners.end() && it->first < straggler.first)
            ++it;
        winners.insert(it, straggler);
    }
}

void PmergeMe::isThereStragglerDeque(int& hasStraggler, std::pair<int, int>& straggler,
    std::deque<std::pair<int, int> >& pairs)
{
    if (pairs.size() % 2 != 0)
        hasStraggler = 1;
    if (hasStraggler)
    {
        straggler = pairs.back();
        pairs.pop_back();
    }
}

void PmergeMe::recursiveSortDeque(std::deque<std::pair<int, int> >& pairs)
{
    if (pairs.size() <= 1)
        return;

    int hasStraggler = 0;
    std::pair<int, int> straggler;
    isThereStragglerDeque(hasStraggler, straggler, pairs);
    std::deque<std::pair<int, int> > winners;
    std::deque<std::pair<int, int> > losers;
    tournamentDeque(pairs, winners, losers);
    recursiveSortDeque(winners);
    insertLoserPairsDeque(winners, losers);
    insertStragglerPairDeque(hasStraggler, straggler, winners);
    pairs = winners;
}

void PmergeMe::splitChainsDeque(std::deque<std::pair<int, int> >& pairs, int& straggler,
    bool& hasStraggler, std::deque<int>& main_chain, std::deque<int>& pend)
{
    main_chain.push_back(pairs[0].second);

    for (size_t i = 0; i < pairs.size(); i++)
        main_chain.push_back(pairs[i].first);

    for (size_t i = 1; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);

    if (hasStraggler)
        pend.push_back(straggler);
}

void PmergeMe::insertWithJacobsthalDeque(std::deque<int>& pend, std::deque<int>& main_chain)
{
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
    for (size_t k = 0; k < jacobSequence.size(); k++)
    {
        size_t targetJacobIdx = jacobSequence[k];
        if (targetJacobIdx > pend.size())
            targetJacobIdx = pend.size();

        for (size_t i = targetJacobIdx; i > lastInsertedIdx; i--)
        {
            int itemToInsert = pend[i - 1];
            std::deque<int>::iterator it =
                std::lower_bound(main_chain.begin(), main_chain.end(), itemToInsert);
            main_chain.insert(it, itemToInsert);
        }
        lastInsertedIdx = targetJacobIdx;
    }
    _dequeContainer = main_chain;
}

void PmergeMe::printTimerResults() const
{
    std::cout << "Time to process a range of "
              << getSizeVector()
              << " elements with std::vector : "
              << getElapsedTimeUsVector() << " us" << std::endl;

    std::cout << "Time to process a range of "
              << getSizeDeque()
              << " elements with std::deque  : "
              << getElapsedTimeUsDeque() << " us" << std::endl;
}