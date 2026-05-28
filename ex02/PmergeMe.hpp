#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <deque>
#include <string>
#include <sys/time.h> // gettimeofday için
class PmergeMe
{
    private:
        std::vector<int> _vectorContainer;
        std::deque<int> _dequeContainer;

        double _vectorTime;
        double _dequeTime;

        struct timeval _startTime;
        struct timeval _endTime;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void   startTimer();
        void   stopTimer();
        double getElapsedTimeUs() const;

        void printBeforeVector() const;
        void printAfterVector() const;

        size_t getVectorSize() const;
        
        void insertElementsToVector(int argc, char **argv);
        void insertElementsToDeque(int argc, char **argv);

        void pairVector(std::vector<int>& container, std::vector<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler);
        void pairDeque(std::deque<int>& container);

        void recursiveSortVector(std::vector<std::pair<int, int> >&pairs);
        void fordJhonsonVector();
        void splitChains(std::vector<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler);
};

#endif