#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private:
        int rawValue;
        static const int fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed& ref);    
        Fixed& operator=(const Fixed& ref);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif

