#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap()
{
    std::cout << "Default constructor called for ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "Constructor called for ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ref) : ClapTrap(ref)
{
    std::cout << "Copy constructor called for ScavTrap" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref)
{
    std::cout << "Copy assignment operator called for ScavTrap." << std::endl;
    if(this != &ref)
    {
        ClapTrap::operator=(ref);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called for ScavTrap." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(_energy_points > 0 && _hit_points > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << getAttackDamage() << " points of damage"  << std::endl;
        _energy_points--;  
    }
    else if (_energy_points == 0 && _hit_points > 0)
        std::cout << "ScavTrap " << _name << " has no energy" << std::endl;
    else if (_hit_points == 0 && _energy_points > 0)
        std::cout << "ScavTrap " << _name << " has no hit points" << std::endl;
    else    
        std::cout << "ScavTrap " << _name << " has no energy points and hit points to attack" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate Keeper mode." << std::endl;
}
