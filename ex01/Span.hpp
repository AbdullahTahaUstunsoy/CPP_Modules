#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iterator>
#include <vector>

class SpanAlreadyFullException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Span is already full";
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

class Span
{
    private:
        unsigned int _N;
        std::vector<int> _numbers;
    public:
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
                throw SpanAlreadyFullException();
            _numbers.insert(_numbers.end(), begin, end);
        }
};

#endif