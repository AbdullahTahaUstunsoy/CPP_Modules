#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL)); // Robotomy için rastgelelik
    std::cout << "-----Test1-----" << std::endl;
    try
    {
        Bureaucrat b1("Taha", 15);
        std::cout << b1 << std::endl;
        Intern intern;
        AForm* form = intern.makeForm("robotomy request", "Bender");
        std::cout << *form << std::endl;
        b1.signForm(*form);
        (*form).execute(b1);
        b1.executeForm(*form);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----Test2-----" << std::endl;
    try
    {
        Bureaucrat b2("Taha", 85);
        std::cout << b2 << std::endl;
        Intern intern;
        AForm* form = intern.makeForm("presidental pardon", "marvin");
        std::cout << *form << std::endl;
        b2.signForm(*form);
        (*form).execute(b2);
        b2.executeForm(*form);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----Test3-----" << std::endl;
     try
    {
        Bureaucrat b3("Taha", 50);
        std::cout << b3 << std::endl;
        Intern intern;
        AForm* form = intern.makeForm("non-existent form", "null");
        std::cout << *form << std::endl;
        b3.signForm(*form);
        (*form).execute(b3);
        b3.executeForm(*form);
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}