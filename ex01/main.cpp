#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ScavTrap st1("ST-One");
    ScavTrap st2("ST-Two");

    std::cout << "Initial state:" << std::endl;
    std::cout << "ST-One: HP=" << st1.getHitPoints() << ", EP=" << st1.getEnergyPoints() << ", AD=" << st1.getAttackDamage() << std::endl;
    std::cout << "ST-Two: HP=" << st2.getHitPoints() << ", EP=" << st2.getEnergyPoints() << ", AD=" << st2.getAttackDamage() << std::endl;

    std::cout << "First round" << std::endl;
    st1.attack("ST-Two");
    st2.takeDamage(st1.getAttackDamage());
    st2.beRepaired(10);

    st2.attack("ST-One");
    st1.takeDamage(st2.getAttackDamage());
    st1.beRepaired(10);
    
	st1.guardGate();
	st2.guardGate();

    std::cout << "End of first round:" << std::endl;
    std::cout << "ST-One: HP=" << st1.getHitPoints() << ", EP=" << st1.getEnergyPoints() << ", AD=" << st1.getAttackDamage() << std::endl;
    std::cout << "ST-Two: HP=" << st2.getHitPoints() << ", EP=" << st2.getEnergyPoints() << ", AD=" << st2.getAttackDamage() << std::endl;
    
    std::cout << "-------------------------" << std::endl;

    std::cout << "Second round" << std::endl;
    st1.attack("ST-Two");
    st2.takeDamage(95);
    st2.beRepaired(10);

    st2.attack("ST-One");
    st1.takeDamage(60);
	st1.beRepaired(20);

    std::cout << "End of second round:" << std::endl;
    std::cout << "ST-One: HP=" << st1.getHitPoints() << ", EP=" << st1.getEnergyPoints() << ", AD=" << st1.getAttackDamage() << std::endl;
    std::cout << "ST-Two: HP=" << st2.getHitPoints() << ", EP=" << st2.getEnergyPoints() << ", AD=" << st2.getAttackDamage() << std::endl;

    return 0;
}
