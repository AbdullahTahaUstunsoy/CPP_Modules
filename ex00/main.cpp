#include "whatever.hpp"
#include <iostream>
#include <string>

int main()
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << "-----------------------------" << std::endl;

    float e = 42.0f;
    float f = 42.0f;
    std::cout << "Address of e: " << &e << std::endl;
    std::cout << "Address of f: " << &f << std::endl;
    float const& min_ef = ::min(e, f);
    std::cout << "Address of min_ef: " << &min_ef << std::endl;
    float const& max_ef = ::max(e, f);
    std::cout << "Address of max_ef: " << &max_ef << std::endl;

    return 0;
}