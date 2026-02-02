#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
}

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

void ClapTrap::attack(const std::string& target) //Attacking and repairing each cost 1 energy point.
{
    if(_energy_points != 0 && _hit_points != 0)
    {
        std::cout << "ClapTrap " << _name << "attacks" << target << ", causing" << 1 << "points of damage"  << std::endl;
        _energy_points--;
    }
    else if (_energy_points == 0 && _hit_points != 0)
        std::cout << "ClapTrap " << _name << "has no energy" << std::endl;
    else if (_hit_points == 0 && _energy_points != 0)
        std::cout << "ClapTrap " << _name << "has no hit points" << std::endl;
    else    
        std::cout << "ClapTrap " << _name << "has no energy points and hit points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{

}

void ClapTrap::beRepaired(unsigned int amount) //When ClapTrap repairs itself, it regains <amount> hit points.
{
    std::cout << "ClapTrap " << _name << " is repaired" << amount << " point." << std::endl;
    if(_hit_points >= 0 && _hit_points < 10)
        _hit_points++;
    else
        std::cout << "hit point full." << std::endl;
}