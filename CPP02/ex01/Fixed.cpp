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