#include "ClapTrap.hpp"
#include <iostream>
//hit points, energy points, attack damage değişkenlerini unsigned tanımlamak zorunda mıyım ?
int main()
{
    ClapTrap ct1("CT-One");
    ClapTrap ct2("CT-Two");

    std::cout << "Initial state:" << std::endl;
    std::cout << "CT-One: HP=" << ct1.getHitPoints() << ", EP=" << ct1.getEnergyPoints() << ", AD=" << ct1.getAttackDamage() << std::endl;
    std::cout << "CT-Two: HP=" << ct2.getHitPoints() << ", EP=" << ct2.getEnergyPoints() << ", AD=" << ct2.getAttackDamage() << std::endl;

    ct1.attack("CT-Two");
    ct2.takeDamage(0);
    ct2.beRepaired(5);

    ct2.attack("CT-One");
    ct1.takeDamage(0);
    ct1.beRepaired(3);

    std::cout << "Final state:" << std::endl;
    std::cout << "CT-One: HP=" << ct1.getHitPoints() << ", EP=" << ct1.getEnergyPoints() << ", AD=" << ct1.getAttackDamage() << std::endl;
    std::cout << "CT-Two: HP=" << ct2.getHitPoints() << ", EP=" << ct2.getEnergyPoints() << ", AD=" << ct2.getAttackDamage() << std::endl; 

    return 0;
}