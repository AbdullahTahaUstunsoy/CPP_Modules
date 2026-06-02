#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name(""), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}
Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        name = other.name;
        isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form()
{
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    isSigned = true;
}

std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low.";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form name:" << form.getName() << ", is signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
    return os;
}

//beSigned() fonksiyonunda form imzalanacak mı imzalanmayacak mı bunu anlıyoruz
//signForm() fonksiyonunda ise imzalama işlemini gerçekleştiriyoruz ve ekrana mesaj basıyoruz