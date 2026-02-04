#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called for ClapTrap." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref) : _name(ref._name), _hit_points(ref._hit_points), _energy_points(ref._energy_points), _attack_damage(ref._attack_damage)
{
    std::cout << "Copy constructor called for ClapTrap " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
    std::cout << "Copy assignment operator called for ClapTrap " << _name << std::endl; 
    if(this != &ref)
    {
        _name = ref._name;
        _hit_points = ref._hit_points;
        _energy_points = ref._energy_points;
        _attack_damage = ref._attack_damage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called for ClapTrap " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target) //Attacking and repairing each cost 1 energy point. //ClapTrap can’t do anything if it has no hit points or energy points left.
{
    if(_energy_points > 0 && _hit_points > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << getAttackDamage() << " points of damage"  << std::endl;
        _energy_points--;  
    }
    else if (_energy_points == 0 && _hit_points > 0)
        std::cout << "ClapTrap " << _name << " has no energy" << std::endl;
    else if (_hit_points == 0 && _energy_points > 0)
        std::cout << "ClapTrap " << _name << " has no hit points" << std::endl;
    else    
        std::cout << "ClapTrap " << _name << " has no energy points and hit points to attack" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    if(_hit_points == 0)
    {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }
    if(amount >= _hit_points)
        _hit_points = 0;
    else
        _hit_points -= amount;
    std::cout << "ClapTrap " << _name << " takes damage of " << amount << " points." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) //When ClapTrap repairs itself, it regains <amount> hit points.
{
    if(_energy_points > 0 && _hit_points > 0)
    {
        std::cout << "ClapTrap " << _name << " is repaired " << amount << " point." << std::endl;
        _hit_points+= amount;
        _energy_points--;
    }
    else
        std::cout << "ClapTrap " << _name << " can't repair (no energy or hit points left)" << std::endl;
}

int ClapTrap::getAttackDamage() const
{   
    return _attack_damage;
}


int ClapTrap::getHitPoints() const
{
    return _hit_points;
}

int ClapTrap::getEnergyPoints() const
{
    return _energy_points;
}