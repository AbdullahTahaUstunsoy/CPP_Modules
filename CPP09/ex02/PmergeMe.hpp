#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <deque>
#include <string>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> _vectorContainer;
        std::deque<int> _dequeContainer;

        struct timeval _vectorStartTime;
        struct timeval _vectorEndTime;
        struct timeval _dequeStartTime;
        struct timeval _dequeEndTime;

        //vector helpers private olmalı
        void pairVector(std::vector<int>& container, std::vector<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler);
        void recursiveSortVector(std::vector<std::pair<int, int> >&pairs);
        void isThereStragglerVector(int& hasStraggler, std::pair<int, int>& straggler, std::vector<std::pair<int, int> >& pairs);
        void tournamentVector(std::vector<std::pair<int, int> >& pairs, std::vector<std::pair<int, int> >& winners, std::vector<std::pair<int, int> >& losers);
        void insertLoserPairs(std::vector<std::pair<int, int> >& winners, std::vector<std::pair<int, int> >& losers);
        void insertStragglerPair(int& hasStraggler, std::pair<int, int>& straggler, std::vector<std::pair<int, int> >& winners);
        void splitChainsVector(std::vector<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler, std::vector<int>& main_chain, std::vector<int>& pend);
        void insertWithJacobsthalVector(std::vector<int>& pend, std::vector<int>& main_chain);
        size_t getSizeVector() const;

        //deque helpers private olmalı
        void pairDeque(std::deque<int>& container, std::deque<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler);
        void recursiveSortDeque(std::deque<std::pair<int, int> >& pairs);
        void isThereStragglerDeque(int& hasStraggler, std::pair<int, int>& straggler, std::deque<std::pair<int, int> >& pairs);
        void tournamentDeque(std::deque<std::pair<int, int> >& pairs, std::deque<std::pair<int, int> >& winners, std::deque<std::pair<int, int> >& losers);
        void insertLoserPairsDeque(std::deque<std::pair<int, int> >& winners, std::deque<std::pair<int, int> >& losers);
        void insertStragglerPairDeque(int& hasStraggler, std::pair<int, int>& straggler, std::deque<std::pair<int, int> >& winners);
        void splitChainsDeque(std::deque<std::pair<int, int> >& pairs, int& straggler, bool& hasStraggler, std::deque<int>& main_chain, std::deque<int>& pend);
        void insertWithJacobsthalDeque(std::deque<int>& pend, std::deque<int>& main_chain);
        size_t getSizeDeque() const;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void   startTimerVector();
        void   stopTimerVector();
        double getElapsedTimeUsVector() const;     
        void    startTimerDeque();
        void    stopTimerDeque();
        double  getElapsedTimeUsDeque() const;

        void insertElementsToVector(int argc, char **argv);
        void fordJhonsonVector();
        void insertElementsToDeque(int argc, char **argv); 
        void fordJhonsonDeque();

        void printTimerResults() const;
        void printBeforeVector() const; 
        void printAfterVector() const;
        void printBeforeDeque() const;
        void printAfterDeque() const;
};

#endif