#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _db;
        bool validateDate(const std::string& date); //Bu fonksiyon tamamen sınıfın kendi iç işleyişiyle (veriyi kontrol etmekle) ilgili bir yardımcı fonksiyon (helper function). Dışarıdan, yani main.cpp içinden doğrudan çağrılmasına gerek yok.
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

        bool loadDatabase(const std::string& dbPath);
        void processInput(const std::string& inputPath);
};

#endif