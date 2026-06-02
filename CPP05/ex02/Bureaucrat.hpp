#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        Bureaucrat(const std::string& name, int grade);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(AForm& aform) const;
        void executeForm(AForm const & aform) const;
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
//Form'ları execute sürecini başlatan ve sonucunu kullanıcıya raporlayan Bureaucrat sınıfındaki executeForm(AForm const & form) fonksiyonudur.

//Süreci Başlatmak	Bureaucrat	executeForm(AForm const & form)
//Karar/Denetleme	AForm	execute(Bureaucrat const & executor)
//Asıl Aksiyonu Yapmak	Somut Formlar	Kendi içindeki uygulama fonksiyonu (doExecute())
#endif