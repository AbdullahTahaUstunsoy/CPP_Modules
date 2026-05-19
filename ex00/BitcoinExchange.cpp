#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

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
    for (size_t i = 0; i < date.length(); i++){
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

bool BitcoinExchange::loadDB(const std::string& dbPath)
{
    std::ifstream dbFile(dbPath.c_str());
    if(!dbFile.is_open())
    {
        std::cerr << "Error: Could not open database file." << std::endl;
        return false;
    }

    std::string line;
    if(!std::getline(dbFile, line))
    {
        std::cerr << "Error: database file is empty." << std::endl;
        dbFile.close();
        return false;
    }

    std::string dateStr;
    std::string exchangeRateStr;
    while(std::getline(dbFile, line))
    {
        if (line.empty())
            continue;
        size_t commaPosition = line.find(',');
        if (commaPosition == std::string::npos){
            std::cerr << "Error: Invalid line format in database file. => " << line << std::endl;
            continue;
        }
        dateStr = line.substr(0, commaPosition);
        if (!validateDate(dateStr)){
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        exchangeRateStr = line.substr(commaPosition + 1);
        char *endptr;
        double exchangeRate = std::strtod(exchangeRateStr.c_str(), &endptr);
        if (*endptr != '\0' || endptr == exchangeRateStr.c_str()){
            std::cerr << "Error: bad input. => " << line << std::endl;
            continue;
        }
        if(exchangeRate < 0){
            std::cerr << "Error: not a positive number."<< std::endl;
            continue;
        }
        _db[dateStr] = exchangeRate;
    }
    dbFile.close();
    return true;
}

void BitcoinExchange::processInput(const std::string& inputPath)
{
    std::ifstream inputFile(inputPath.c_str());
    if(!inputFile.is_open())
    {
        std::cerr << "Error: Could not open input file." << std::endl;
        return;
    }
    std::string line;
    if(!std::getline(inputFile, line))
    {
        std::cerr << "Error: input file is empty." << std::endl;
        inputFile.close();
        return;
    }
    if(line != "date | value")
    {
        std::cerr << "Error: Invalid header in input file. Expected 'date | value'." << std::endl;
        inputFile.close();
        return;
    }
    std::string dateStr;
    std::string valueStr;
    while(std::getline(inputFile, line))
    {
        if(line.empty())
            continue;
        if(line.find('|') == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if(line.length() < 14)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        dateStr = line.substr(0, line.find('|'));
        valueStr = line.substr(line.find('|') + 1);
        if(dateStr.length() != 11 || dateStr[10] != ' ' || valueStr[0] != ' ')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        dateStr = dateStr.substr(0, dateStr.length() - 1);
        if (!validateDate(dateStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        size_t startIndex = 0;
        size_t endIndex = valueStr.length() - 1;
        while (startIndex < valueStr.length() &&  (valueStr[startIndex] == ' ' || valueStr[startIndex] == '\t' || valueStr[startIndex] == '\n')) 
            startIndex++;
        while (endIndex >= startIndex && (valueStr[endIndex] == ' ' || valueStr[endIndex] == '\t' || valueStr[endIndex] == '\n'))
            endIndex--;
        if (startIndex <= endIndex)
            valueStr = valueStr.substr(startIndex, endIndex - startIndex + 1);
        else
            valueStr = "";

        char* endptr2;
        double value = std::strtod(valueStr.c_str(), &endptr2);
        if (*endptr2 != '\0' || endptr2 == valueStr.c_str())
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if(value < 0)
        {
            std::cerr << "Error: not a positive number" << std::endl;
            continue;
        }
        if(value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, double>::iterator it = _db.lower_bound(dateStr);
        if (it != _db.end() && it->first == dateStr)
            std::cout << dateStr << " => " << value << " = " << value * it->second << std::endl;
        else if (it == _db.end() || it != _db.begin())
        {
            --it;
            std::cout << dateStr << " => " << value << " = " << value * it->second << std::endl;
        }
        else
            std::cerr << "Error: No exchange rate available for date => " << dateStr << std::endl;
    }
}