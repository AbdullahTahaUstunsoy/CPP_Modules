#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
   _db = other._db; 
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::validateDate(const std::string& date)
{
    if (date.length() != 10)
        return false;
    for (size_t i = 0; i < date.length(); i++){ //Karakterlerin sayı olup olmadığının kontrolü
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else if (date[i] < '0' || date[i] > '9')
            return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        daysInMonths[1] = 29;
    if (month < 1 || month > 12 || day < 1 || day > daysInMonths[month - 1] || year < 2009)
        return false;
    return true;
}