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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif