#include "ClapTrap.hpp"
#include <iostream>
//hit points, energy points, attack damage değişkenlerini unsigned tanımlamak zorunda mıyım ? ve void attack(const std::string& target); burada const olmak zorunda mı referans zaten değiştirilemez
int main()
{
    ClapTrap ct1("CT-One");
    ClapTrap ct2("CT-Two");

    std::cout << "Initial state:" << std::endl;
    std::cout << "CT-One: HP=" << ct1.getHitPoints() << ", EP=" << ct1.getEnergyPoints() << ", AD=" << ct1.getAttackDamage() << std::endl;
    std::cout << "CT-Two: HP=" << ct2.getHitPoints() << ", EP=" << ct2.getEnergyPoints() << ", AD=" << ct2.getAttackDamage() << std::endl;

    std::cout << "First round" << std::endl;
    ct1.attack("CT-Two");
    ct2.takeDamage(3);
    ct2.beRepaired(5);

    ct2.attack("CT-One");
    ct1.takeDamage(2);
    ct1.beRepaired(3);
    
    std::cout << "End of first round:" << std::endl;
    std::cout << "CT-One: HP=" << ct1.getHitPoints() << ", EP=" << ct1.getEnergyPoints() << ", AD=" << ct1.getAttackDamage() << std::endl;
    std::cout << "CT-Two: HP=" << ct2.getHitPoints() << ", EP=" << ct2.getEnergyPoints() << ", AD=" << ct2.getAttackDamage() << std::endl;
    
    std::cout << "-------------------------" << std::endl;

    std::cout << "Second round" << std::endl;
    ct1.attack("CT-Two");
    ct2.takeDamage(15);
    
    ct2.attack("CT-One");
    ct1.takeDamage(15); //!!! şuanki durumda c2 nin hit points'i kalmadığı için ct1'a zarar veremez ancak ct1 'in hit points'inin 0landığını göstermek adına bunu çalıştırdım

    std::cout << "End of second round:" << std::endl;
    std::cout << "CT-One: HP=" << ct1.getHitPoints() << ", EP=" << ct1.getEnergyPoints() << ", AD=" << ct1.getAttackDamage() << std::endl;
    std::cout << "CT-Two: HP=" << ct2.getHitPoints() << ", EP=" << ct2.getEnergyPoints() << ", AD=" << ct2.getAttackDamage() << std::endl;

    return 0;
}