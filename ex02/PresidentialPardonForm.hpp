#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm ();
        PresidentialPardonForm (const PresidentialPardonForm & other);
        PresidentialPardonForm & operator=(const PresidentialPardonForm & other);
        ~PresidentialPardonForm ();
        PresidentialPardonForm (const std::string& target);
        std::string getTarget() const;
        void doExecution() const;
};
#endif