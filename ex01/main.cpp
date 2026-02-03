#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	/* std::cout << "=== ClapTrap Tests ===" << std::endl;
	ClapTrap clap1("ClapTrap1");
	ClapTrap clap2("ClapTrap2");

	std::cout << "\nInitial stats:" << std::endl;
	std::cout << "ClapTrap1 - HP: " << clap1.getHitPoints() << ", Energy: " << clap1.getEnergyPoints() << ", Attack: " << clap1.getAttackDamage() << std::endl;

	clap1.attack("ClapTrap2");
	clap2.takeDamage(5);
	clap2.beRepaired(3);

	std::cout << "\nAfter actions:" << std::endl;
	std::cout << "ClapTrap2 - HP: " << clap2.getHitPoints() << ", Energy: " << clap2.getEnergyPoints() << std::endl; */

	std::cout << "\n=== ScavTrap Tests ===" << std::endl;
	ScavTrap scav1("ScavTrap1");
	ScavTrap scav2("ScavTrap2");

	std::cout << "\nInitial stats:" << std::endl;
	std::cout << "ScavTrap1 - HP: " << scav1.getHitPoints() << ", Energy: " << scav1.getEnergyPoints() << ", Attack: " << scav1.getAttackDamage() << std::endl;

	scav1.attack("ScavTrap2");
	scav2.takeDamage(20);
	scav2.beRepaired(10);
	scav1.guardGate();

	std::cout << "\nAfter actions:" << std::endl;
	std::cout << "ScavTrap2 - HP: " << scav2.getHitPoints() << ", Energy: " << scav2.getEnergyPoints() << std::endl;

	return (0);
}
