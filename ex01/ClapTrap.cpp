#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called for ClapTrap." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Constructor called for ClapTrap." << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref) : _name(ref._name), _hit_points(ref._hit_points), _energy_points(ref._energy_points), _attack_damage(ref._attack_damage)
{
    std::cout << "Copy constructor called for ClapTrap." << std::endl; // bu mesajlar kalmalı mı
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref)
{
    std::cout << "Copy assignment operator called for ClapTrap." << std::endl; //bu mesajlar kalmalı mı 
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
    std::cout << "Destructor called for ClapTrap." << std::endl;
}

void ClapTrap::attack(const std::string& target) //Attacking and repairing each cost 1 energy point. //ClapTrap can’t do anything if it has no hit points or energy points left.
{
    if(_energy_points > 0 && _hit_points > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << getAttackDamage() << " points of damage"  << std::endl; //attack damage 0 verilmiş onun için de buraya 0 yazılmalı diye düşündüm
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
    if(_hit_points > 0)
    {
        _hit_points -= amount;
        if(_hit_points <= 0)
            _hit_points = 0;
        std::cout << "ClapTrap " << _name << " takes damage of " << amount << " points." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) //When ClapTrap repairs itself, it regains <amount> hit points. //Hit points gidince repair olması mantıklı ama bu egzersizde hiçbir zaman hit points in gideceği bir durum yok // ClapTrap can’t do anything if it has no hit points or energy points left.
{
    if(_energy_points > 0 && _hit_points >= 0) //Dolayısıyla bu kısım biraz göstermelik //_hit_points'e bakılmalı mı burada
    {
        std::cout << "ClapTrap " << _name << " is repaired " << amount << " point." << std::endl;
        _hit_points+= amount;
        _energy_points--;
    }
    else
        std::cout << "ClapTrap no energy or hit points to repair" << std::endl;
}


int ClapTrap::getHitPoints() const
{
    //std::cout << "ClapTrap's hit points amount:" << std::endl; //bu mesajlara gerek olmayabilir
    return _hit_points;
}

int ClapTrap::getEnergyPoints() const
{
    //std::cout << "ClapTrap's energy_points amount:" << std::endl;
    return _energy_points;
}

int ClapTrap::getAttackDamage() const
{   
    //std::cout << "ClapTrap's damaged amount:";
    return _attack_damage;
}


void ClapTrap::setHitPoints(int hit_points)
{
    //std::cout << "ClapTrap's hit points assigned." << std::endl;
    _hit_points = hit_points;
}

void ClapTrap::setEnergyPoints(int energy_points)
{
    //std::cout << "ClapTrap's energy points assigned." << std::endl;
    _energy_points = energy_points;
}

void ClapTrap::setAttackDamage(int attack_damage)
{
    //std::cout << "ClapTrap's attack damage assigned." << std::endl;
    _attack_damage = attack_damage;
}