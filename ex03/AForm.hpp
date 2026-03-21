#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    public:
        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);

        void beSigned(const Bureaucrat& bureaucrat);
        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void execute(Bureaucrat const & executor) const;
        virtual void doExecution() const = 0; 

        class GradeTooHighException : public std::exception{
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char* what() const throw();
        };
        
        class FormNotSignedException : public std::exception {
           public:
                virtual const char* what() const throw();
        };
        
};    
std::ostream& operator<<(std::ostream& os, const AForm& aform);
//Formun çalışıp çalışmayacağına karar veren ana merkez AForm sınıfı ve onun içindeki execute(Bureaucrat const & executor) const fonksiyonudur.

#endif