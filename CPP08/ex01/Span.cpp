#include "Span.hpp"
#include <algorithm>

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if(this != &other)
    {
       _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
    if(_numbers.size() >= _N)
        throw Span::ContainerFullException();
    _numbers.push_back(number); //yeni elemanı vektörün sonuna ekler
}

int Span::shortestSpan() const
{
    if(_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sortedNumbers = _numbers; //kopya oluşturuyorum çünkü fonksiyonu const olarak tanımladık ve vektörün içeriğini değiştiremeyiz
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = sortedNumbers[1] - sortedNumbers[0];
    for(size_t i = 2; i < sortedNumbers.size(); i++)
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if(span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if(_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

    return (*maxIt - *minIt);
}

const std::vector<int>& Span::getNumbers() const
{
    return _numbers;
}

std::ostream& operator<<(std::ostream& os, const Span& span)
{
    std::vector<int>::const_iterator it = span.getNumbers().begin();
    while(it != span.getNumbers().end())
    {
        os << *it << " ";
        it++;
    }
    return os;
}

/*
Eğer sınıf içindeki orijinal _numbers vektörünü sıralamaya çalışırsak (std::sort), 
vektörün içeriği değişir. Bu durumda derleyici hata verir ve kodumuz derlenmez. (Çünkü fonksiyonu const olarak tanımladım)
*/