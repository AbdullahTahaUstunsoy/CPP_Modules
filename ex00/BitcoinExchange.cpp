#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib> // std::strtod için
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
            std::cerr << "Error: Invalid date format in database file. => " << dateStr << std::endl;
            continue;
        }
        exchangeRateStr = line.substr(commaPosition + 1);
        char *endptr;
        double exchangeRate = std::strtod(exchangeRateStr.c_str(), &endptr); //2.5abc gibi bir girdi varsa 2.5'i alır ve endptr'yi 'a' karakterine işaret eder. Eğer exchangeRateStr tamamen geçerli bir sayı değilse, endptr hala exchangeRateStr'nin başlangıcını gösterecektir. (2.5abc durumunda a yı, abc durumunda a'yı gösterir) //atof kullansaydım 2.5'i alacaktı ve hiçbir hata mesajı vermeyecekti, bu yüzden strtod kullanmak daha güvenli.
        if (*endptr != '\0' || endptr == exchangeRateStr.c_str()) {
            std::cerr << "Error: Invalid exchange_rate format in database file. => " << line << std::endl;
            continue;
        }
        if(exchangeRate < 0){
            std::cerr << "Error: Negative exchange_rate in database file. => " << line << std::endl;
            continue;
        }
        _db[dateStr] = exchangeRate;
    }
    dbFile.close();
    return true;
}

void BitcoinExchange::processInput(const std::string& inputPath)
{
    
}