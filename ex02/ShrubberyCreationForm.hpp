#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& target);
        std::string getTarget() const;
        void doExecution() const;
};
//Her sınıf kendi özel eylemini gerçekleştiren doExecution() fonksiyonunu kullanır
#endif