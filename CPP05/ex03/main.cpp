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
    srand(time(NULL));
    std::cout << "-----Valid Tests-----" << std::endl;
    try
    {
        Bureaucrat b1("Taha", 30);
        std::cout << b1 << std::endl;

        Intern intern;
        AForm* form1 = intern.makeForm("shrubbery creation", "Cherries");
        if(!form1)
            throw Intern::NotAForm();
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        if(!form2)
            throw Intern::NotAForm();
        AForm* form3 = intern.makeForm("presidential pardon", "Marvin");
        if(!form3)
            throw Intern::NotAForm();
        std::cout << "---Shrubbery Test---"<<std::endl;
        b1.signForm(*form1);
        b1.executeForm(*form1);
        std::cout << "---Robotomy Test---"<<std::endl;
        b1.signForm(*form2);
        b1.executeForm(*form2);
        std::cout << "---Presidential Test---"<<std::endl;
        b1.signForm(*form3);
        b1.executeForm(*form3);
        delete form1;
        delete form2;
        delete form3;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "-----Invalid Test1-----"<<std::endl;
    try
    {
        Bureaucrat b1("Taha", 1);
        std::cout << b1 << std::endl;
        Intern intern;
        AForm* form = intern.makeForm("non-existent form", "null");
        if(!form)
            throw Intern::NotAForm(); //olmayan form durumu
        b1.signForm(*form);
        b1.executeForm(*form);
        delete form;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b1("Taha", 1);
        std::cout << b1 << std::endl;
        Intern intern;
        AForm* form = intern.makeForm("presidential pardon", "Marvin");
        if(!form)
            throw Intern::NotAForm();
        b1.executeForm(*form); //sign olmadan execute etmeye çalışma durumu
        delete form;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}