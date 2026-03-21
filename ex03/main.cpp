#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>
//Testi düzenleyebilirim, try catch'te leak riski olabilir
int main()
{
    srand(time(NULL)); // Robotomy için rastgelelik
    std::cout << "-----Test1-----" << std::endl;
    try
    {
        Bureaucrat b1("Taha", 50);

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
        std::cout << "---shrubbery test---"<<std::endl;
        b1.signForm(*form1);
        (*form1).execute(b1);
        b1.executeForm(*form1);
        std::cout << "---robotomy test---"<<std::endl;
        b1.signForm(*form2);
        (*form2).execute(b1);
        b1.executeForm(*form2);
        std::cout << "---presidential test---"<<std::endl;
        b1.signForm(*form3);
        (*form3).execute(b1);
        b1.executeForm(*form3);
        delete form1;
        delete form2;
        delete form3;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---invalid test---"<<std::endl;
    try
    {
        Bureaucrat b2("Taha", 50);
        std::cout << b2 << std::endl;
        Intern intern;
        AForm* form = intern.makeForm("non-existent form", "null");
        if(!form)
            throw Intern::NotAForm();
        else
            std::cout << *form << std::endl;
        b2.signForm(*form);
        (*form).execute(b2);
        b2.executeForm(*form);

        delete form;
    }
    catch(std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}