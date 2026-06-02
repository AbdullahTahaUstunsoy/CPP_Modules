#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this); //atayacak bir şey yok
}

Intern::~Intern()
{
}

const char* Intern::NotAForm::what() const throw()
{
    return "The form could not be created";
}

AForm* Intern::createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    static const std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    typedef AForm* (Intern::*Forms)(std::string);
    static Forms forms[] = {
        &Intern::createShrubbery,
        &Intern::createRobotomy,
        &Intern::createPardon
    };
    
    for(int i = 0; i < 3; i++){
        if(formName == formNames[i]){
            std::cout << "Intern creates " << target << std::endl;
            return (this->*forms[i])(target);
        }
    }
    std::cerr << "Form couldn't found" << std::endl;
    return (NULL);
}

