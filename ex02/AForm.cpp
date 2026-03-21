#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name(""), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        name = other.name;
        isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}

std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute()) 
        throw AForm::GradeTooLowException();
    this->doExecution(); 
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low.";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& aform)
{
    os << "Form name:" << aform.getName() << ", is signed: " << aform.getIsSigned() << ", grade to sign: " << aform.getGradeToSign() << ", grade to execute: " << aform.getGradeToExecute();
    return os;
}
