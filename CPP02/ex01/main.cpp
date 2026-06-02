#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed       a; // default constructor called
    Fixed const b( 10 ); // int constructor called
    Fixed const c( 42.42f ); // float constructor called
    Fixed const d( b ); // copy constructor called

    a = Fixed( 1234.4321f ); // float constructor called + copy assignment operator called

    std::cout << "a is " << a << std::endl; //
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}