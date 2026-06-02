#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	FragTrap ft1("FT-One");
    FragTrap ft2("FT-Two");

    std::cout << "Initial state:" << std::endl;
    std::cout << "FT-One: HP=" << ft1.getHitPoints() << ", EP=" << ft1.getEnergyPoints() << ", AD=" << ft1.getAttackDamage() << std::endl;
    std::cout << "FT-Two: HP=" << ft2.getHitPoints() << ", EP=" << ft2.getEnergyPoints() << ", AD=" << ft2.getAttackDamage() << std::endl;

    std::cout << "First round" << std::endl;
    ft1.attack("FT-Two");
    ft2.takeDamage(ft1.getAttackDamage());
    ft2.beRepaired(10);

    ft2.attack("FT-One");
    ft1.takeDamage(ft2.getAttackDamage());
    ft1.beRepaired(10);
    
	ft1.highFivesGuys();
	ft2.highFivesGuys();

    std::cout << "End of first round:" << std::endl;
    std::cout << "FT-One: HP=" << ft1.getHitPoints() << ", EP=" << ft1.getEnergyPoints() << ", AD=" << ft1.getAttackDamage() << std::endl;
    std::cout << "FT-Two: HP=" << ft2.getHitPoints() << ", EP=" << ft2.getEnergyPoints() << ", AD=" << ft2.getAttackDamage() << std::endl;
    
    std::cout << "-------------------------" << std::endl;

    std::cout << "Second round" << std::endl;
    ft1.attack("FT-Two");
    ft2.takeDamage(95);
    ft2.beRepaired(10);

    ft2.attack("FT-One");
    ft1.takeDamage(60);
	ft1.beRepaired(20);

    std::cout << "End of second round:" << std::endl;
    std::cout << "FT-One: HP=" << ft1.getHitPoints() << ", EP=" << ft1.getEnergyPoints() << ", AD=" << ft1.getAttackDamage() << std::endl;
    std::cout << "FT-Two: HP=" << ft2.getHitPoints() << ", EP=" << ft2.getEnergyPoints() << ", AD=" << ft2.getAttackDamage() << std::endl;

    return 0;
}