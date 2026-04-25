#include "ScalarConverter.hpp"
#include <iostream> //?
#include <limits>
#include <cctype>

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

int ScalarConverter::isInt(const std::string& literal, int length)
{
    int i = 1;
    while (i < length)
    {
        if(!std::isdigit(literal[i]))
            return INVALID;
        i++;
    }
    return INT;
}

int ScalarConverter::isDouble(const std::string& literal, int length)
{
    int i = 0;
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

int ScalarConverter::isFloat(const std::string& literal, int length)
{
    int i = 0;
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
        return CHAR; //isprintable bakılacak
    else if(length == 1 && std::isdigit(literal[0])) // "0", "1", "2" ...
        return INT;
    else if(length > 1 && hasSign && !hasDot && !hasF) // "-132", "+53252"
    {
        int result = isInt(literal, length);
        if(result == INVALID)
            return INVALID;
        return INT;
    }
    else if(length > 1 && hasDot && !hasF)
    {
        int result = isDouble(literal, length);
        if(result == INVALID)
            return INVALID;
        return DOUBLE;
    }
    else if(length > 1 && hasDot && hasF)
    {
        int result = isFloat(literal, length);
        if(result == INVALID)
            return INVALID;
        return FLOAT;
    }
}

void ScalarConverter::convert(const std::string& literal)
{
    int type = detectType(literal);   
}