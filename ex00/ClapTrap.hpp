#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
    private:
        std::string _name;
        int energy_points = 10; //bunlara atama olmayacağı için "_" ile başlatmadım
        int hit_points = 10;
        int attack_damage = 0;
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& ref); //const koymama gerek var mı zaten değiştirilemiyor
        ClapTrap& operator=(const ClapTrap& ref);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif