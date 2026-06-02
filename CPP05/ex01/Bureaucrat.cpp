#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    int temp = grade;
    if(--temp < 1)
        throw Bureaucrat::GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade()
{
    int temp = grade;
    if(++temp > 150)
        throw Bureaucrat::GradeTooLowException();
    ++grade;
}

void Bureaucrat::signForm(Form& form) const{ //eğer isSigned zaten true'ysa yazmasına gerek yok başka mesaj basılabilir
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() //catch içinde çalışacak
{
    return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
