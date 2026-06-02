#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed 
{
    private:
        int rawValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        Fixed(const int intValue);
        Fixed(const float floatValue);
        float toFloat(void) const;
        int toInt(void) const;
        int getRawBits(void) const;
        void setRawBits(int const raw);

        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        Fixed& operator++(); //prefix increment ++x
        Fixed operator++(int); //postfix increment x++
        Fixed& operator--(); //prefix decrement --x
        Fixed operator--(int); //postfix decrement x--

        static Fixed& min(Fixed& a, Fixed& b);
        const static Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        const static Fixed& max(const Fixed& a, const Fixed& b);



};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif