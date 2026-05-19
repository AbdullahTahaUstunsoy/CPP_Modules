#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char**argv)
{
    if(argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <data_file>" << std::endl;
        return 1;
    }
    BitcoinExchange btc;

    std::cout << "--- Loading Database ---" << std::endl;
    if (!btc.loadDB("data.csv"))
    {
        std::cerr << "Error: Internal database could not be loaded." << std::endl;
        return 1;
    }
    std::cout << "Database loaded successfully!\n" << std::endl;

    std::cout << "--- Processing Input File ---" << std::endl;
    btc.processInput(argv[1]);   
    return (0);
}