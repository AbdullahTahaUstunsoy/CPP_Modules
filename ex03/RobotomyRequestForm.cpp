#include "RobotomyRequestForm.hpp"
#include <cstdlib>
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::doExecution() const
{
    std::cout << " ZZZZZZZZZZZZZZZZZZZZZZZ " << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    } else {
        std::cout << this->getTarget() << " robotomy failed" << std::endl;
    }
}