#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name)
{
    std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
    std::cout << "Copy constructor called." << std::endl;
    _name = ref._name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
    std::cout << "Copy assignment operator called." << std::endl;
    if(this != &ref)
        _name = ref._name;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap " + _name + "attacks" + target + ", causing" + 1 +  "points of damage"<< std::endl;
}

