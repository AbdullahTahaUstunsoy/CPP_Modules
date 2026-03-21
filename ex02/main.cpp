#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>  // srand, rand
#include <ctime>    // time
#include <iostream>

int main()
{
    srand(time(NULL)); // Robotomy için rastgelelik

    try
    {
        Bureaucrat highAuthority("HighAuthority", 1);
        Bureaucrat lowAuthority("LowAuthority", 150);

        ShrubberyCreationForm scform("tree");
        RobotomyRequestForm rrform("robot");
        PresidentialPardonForm ppform("pardon");
        
        std::cout << "---Initial states---"<<std::endl;
        std::cout << highAuthority << std::endl;
        std::cout << lowAuthority << std::endl;
        std::cout << scform << std::endl;
        std::cout << rrform << std::endl;
        std::cout << ppform << std::endl;

        std::cout << "---Bureaucrats are signing forms---"<<std::endl;
        lowAuthority.signForm(scform);
        lowAuthority.signForm(rrform);
        lowAuthority.signForm(ppform);
        highAuthority.signForm(scform);
        highAuthority.signForm(rrform);
        highAuthority.signForm(ppform);

        std::cout << "---Executing forms---"<<std::endl;
        lowAuthority.executeForm(scform);
        lowAuthority.executeForm(rrform);
        lowAuthority.executeForm(ppform);
        highAuthority.executeForm(scform);
        highAuthority.executeForm(rrform);
        highAuthority.executeForm(ppform);

        std::cout << "---Some wrong situations---" << std::endl;
        Bureaucrat b1("b1", 140);
        b1.signForm(scform); //sign yapabilir ama exec yapamaz
        b1.executeForm(scform);
        Bureaucrat b2("b2", 60); //sign yapabilir ama exec yapamaz
        b2.signForm(rrform);
        b2.executeForm(rrform);
        Bureaucrat b3("b3", 30); //sign da exec de yapamaz
        b3.signForm(ppform);
        b3.executeForm(ppform);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}