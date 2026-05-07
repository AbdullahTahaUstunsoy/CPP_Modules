#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
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
        unsigned int N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;
};

#endif