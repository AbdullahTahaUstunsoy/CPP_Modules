#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <vector>

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _numbers;
    public:
        class ContainerFullException : public std::exception
        {
            public:
                const char* what() const throw()
            {
               return "Container is full";
            }
        };

        class NoSpanException : public std::exception
        {
            public:
                const char* what() const throw()
            {
                return "No span can be found";
            }
        };

        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            if(std::distance(begin, end) + _numbers.size() > _N)
                throw ContainerFullException();
            _numbers.insert(_numbers.end(), begin, end);
        }
        const std::vector<int>& getNumbers() const;
};
std::ostream& operator<<(std::ostream& os, const Span& span);

#endif