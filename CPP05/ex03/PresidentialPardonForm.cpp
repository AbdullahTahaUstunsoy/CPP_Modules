#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

std::string PresidentialPardonForm::getTarget() const
{
    return target;
}

void PresidentialPardonForm::doExecution() const
{
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}