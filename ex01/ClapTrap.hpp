#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hit_points;
        unsigned int _energy_points; //bunlara atama olmayacağı için "_" ile başlatmadım
        unsigned int _attack_damage;
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& ref); //const koymama gerek var mı zaten değiştirilemiyor
        ClapTrap& operator=(const ClapTrap& ref);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
        void setHitPoints(int hit_points);
        void setEnergyPoints(int energy_points);
        void setAttackDamage(int attack_damage);
};

#endif