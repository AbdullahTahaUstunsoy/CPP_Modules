#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
    private:
        std::vector<int> _vectorContainer;
        std::deque<int> _dequeContainer;

        double _vectorTime;
        double _dequeTime;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void insertElementsToVector(const int argc, const char **argv);
        void insertElementsToDeque(const int argc, const char **argv);

        void pairVector(std::vector<int>& container);
        void pairDeque(std::deque<int>& container);

        void recursiveSortVector(std::vector<std::pair<int, int> >&pairs);

};

#endif