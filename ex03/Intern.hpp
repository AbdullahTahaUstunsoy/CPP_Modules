#ifndef INTERN_CPP
#define INTERN_CPP

#include <string>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    
    AForm* createShrubbery(std::string target);
    AForm* createRobotomy(std::string target);
    AForm* createPardon(std::string target);
    AForm* makeForm(std::string formName, std::string target);
};

#endif