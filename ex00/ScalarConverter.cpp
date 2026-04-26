#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::analyzeLiteral(const std::string& literal, bool& hasSign, bool& hasDot, bool& hasF, int& length)
{
     if(literal[0] == '-' || literal[0] == '+')
        hasSign = true;
    int i = 0;
    int dotCount = 0;
    while(i < length)
    {
        if(literal[i] == '.')
            dotCount++;
        i++;
    }
    if(dotCount == 1)
        hasDot = true;
    if(literal[length - 1] == 'f')
        hasF = true;
}

int ScalarConverter::isInt(const std::string& literal, bool& hasSign, int length)
{
    int i;
    if(hasSign)
        i = 1;
    else
        i = 0;
    while (i < length)
    {
        if(!std::isdigit(literal[i]))
            return INVALID;
        i++;
    }
    return INT;
}

int ScalarConverter::isDouble(const std::string& literal, bool& hasSign, int length)
{
    int i;
    if(hasSign)
        i = 1;
    else
        i = 0;
    while(i < length)
    {
        if(literal[i] == '.')
        {
            i++;
            continue;
        }
        if(!std::isdigit(literal[i]))
            return INVALID;
        i++;
    }
    return DOUBLE;
}

int ScalarConverter::isFloat(const std::string& literal, bool& hasSign, int length)
{
    int i;
    if(hasSign)
        i = 1;
    else
        i = 0;
    while(i < length)
    {
        if(literal[i] == '.' || literal[i] == 'f')
        {
            i++;
            continue;
        }
        if(!std::isdigit(literal[i]))
            return INVALID;
        i++;
    }
    return FLOAT;
}

int ScalarConverter::detectType(const std::string& literal)
{
    if(literal.empty())
        return INVALID;
    if(literal == "-inff" || literal == "+inff" || literal == "nanf" || literal == "-inf" || literal == "+inf" || literal == "nan")
        return PSEUDO;
    int length = literal.length();
    bool hasSign = false;
    bool hasDot = false;
    bool hasF = false;

    analyzeLiteral(literal, hasSign, hasDot, hasF, length);
   
    if(length == 1 && !std::isdigit(literal[0]))
        return CHAR;
    else if(length == 1 && std::isdigit(literal[0]))
        return INT;
    else if(length > 1 && !hasDot && !hasF)
    {
        int result = isInt(literal, hasSign, length);
        if(result == INVALID)
            return INVALID;
        return INT;
    }
    else if(length > 1 && hasDot && !hasF)
    {
        int result = isDouble(literal, hasSign, length);
        if(result == INVALID)
            return INVALID;
        return DOUBLE;
    }
    else if(length > 1 && hasDot && hasF)
    {
        int result = isFloat(literal, hasSign, length);
        if(result == INVALID)
            return INVALID;
        return FLOAT;
    }
    else
        return INVALID;
}

void ScalarConverter::convert(const std::string& literal)
{
    int type = detectType(literal);

    if(type == INVALID)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    if(type == PSEUDO)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        {
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        }
        else
        {
            std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
        return;
    }

    if(type == CHAR)
    {
        if(std::isprint(literal[0]))
            std::cout << "char: '" << literal[0] << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        
        char c = literal[0];

        int i = static_cast<int>(c);
        float  f = static_cast<float>(c);
        double d = static_cast<double>(c);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }

    if(type == INT)
    {
        long temp = std::strtol(literal.c_str(), NULL, 10);
        int i;
        float f;
        double d;
        char c;
        bool isIntImpossible = (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min());
        if(!isIntImpossible)
            i = static_cast<int>(temp);
        if(isIntImpossible || temp < 0 || temp > 127)
            std::cout << "char: impossible" << std::endl;
        else
        {
            c = static_cast<char>(i);
            if(std::isprint(c))
                std::cout << "char: '" << c << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        if(isIntImpossible)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
        if(isIntImpossible)
        {
            f = static_cast<float>(temp);
            d = static_cast<double>(temp);
        }
        else
        {
            f = static_cast<float>(i);
            d = static_cast<double>(i);
        }
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }

    if(type == FLOAT)
    {
        float f = std::strtof(literal.c_str(), NULL);

        char    c = static_cast<char>(f);
        int     i = static_cast<int>(f);
        double  d = static_cast<double>(f);

        if (f < 0 || f > 127 || std::isnan(f) || std::isinf(f))
            std::cout << "char: impossible" << std::endl;
        else
        {
            if(std::isprint(c))
                std::cout << "char: '" << c << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min() || std::isnan(f) || std::isinf(f))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
        
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }

    if(type == DOUBLE)
    {
        double d = std::strtod(literal.c_str(), NULL);

        char    c = static_cast<char>(d);
        int     i = static_cast<int>(d);
        float   f = static_cast<float>(d);

        if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d))
            std::cout << "char: impossible" << std::endl;
        else
        {
            if(std::isprint(c))
                std::cout << "char: '" << c << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }

        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || std::isnan(d) || std::isinf(d))
          std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
        
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
}