#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : rawValue(0)
{   
    std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    rawValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
        rawValue = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
    std::cout << "Int constructor called" << std::endl;
    rawValue = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
    std::cout << "Float constructor called" << std::endl;
    rawValue = roundf(floatValue * (1 << fractionalBits));
}

float Fixed::toFloat() const
{
    return (float)rawValue / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return rawValue >> fractionalBits;
}

int Fixed::getRawBits() const
{
    return rawValue;
}

void Fixed::setRawBits(int const raw)
{
    rawValue = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const
{
    return rawValue > other.rawValue;
}

bool Fixed::operator<(const Fixed& other) const
{
    return rawValue < other.rawValue;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return rawValue >= other.rawValue;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return rawValue <= other.rawValue;
}

bool Fixed::operator==(const Fixed& other) const
{
    return rawValue == other.rawValue;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return rawValue != other.rawValue;
}

Fixed Fixed::operator+(const Fixed& other) const //return (Fixed(rawValue + other.rawValue)) yapamayız çünkü constructorın aldığı parametre integer'ı gerçek sayı olarak alıyor ama biz rawValue göndermiş olacağız bu durumda
{
    Fixed newFixed;
    newFixed.setRawBits(rawValue + other.rawValue);
    return newFixed;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed newFixed;
    newFixed.setRawBits(rawValue - other.rawValue);
    return newFixed;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed newFixed;
    newFixed.setRawBits((rawValue * other.rawValue) >> fractionalBits);
    return newFixed;
}

Fixed Fixed::operator/(const Fixed& other) const
{   
    Fixed newFixed;
    newFixed.setRawBits(roundf( ((float)rawValue / (float)other.rawValue) * (1 << fractionalBits) ));
    return newFixed;
}

Fixed& Fixed::operator++()
{
    rawValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    rawValue++;
    return temp;
}

Fixed& Fixed::operator--()
{
    rawValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    rawValue--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if(a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if(a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if(a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if(a > b)
        return (a);
    return (b);
}