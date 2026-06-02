#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : rawValue(0)
{
    std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed(const Fixed& ref)
{
    std::cout << "Copy constructor called" <<std::endl;
    rawValue = ref.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& ref)
{
    std::cout << "Copy assignment operator called" <<std::endl;
    if (this != &ref) //kendini kendine atamaması için //this genel anlamda isim çakışmasını önlemek için kullanılır fakat burada kullanmak zorundayım çünkü alternatifi yok
        rawValue = ref.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" <<std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return rawValue;
}

void Fixed::setRawBits(int const raw)
{
    rawValue = raw;
}