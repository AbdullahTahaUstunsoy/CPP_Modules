#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default constructor called for FragTrap." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "Constructor called for FragTrap." << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref) : ClapTrap(ref)
{
    std::cout << "Copy constructor called for FragTrap" << std::endl;    
}

FragTrap& FragTrap::operator=(const FragTrap& ref)
{
    std::cout << "Copy assignment operator called for FragTrap." << std::endl;
    if(this != &ref)
    {
        ClapTrap::operator=(ref);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "Destructor called for FragTrap." << std::endl;
}


void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " is requesting high fives!" << std::endl;
}












