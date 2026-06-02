#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;
    public:
        RobotomyRequestForm ();
        RobotomyRequestForm (const RobotomyRequestForm & other);
        RobotomyRequestForm & operator=(const RobotomyRequestForm & other);
        ~RobotomyRequestForm();
        RobotomyRequestForm (const std::string& target);
        std::string getTarget() const;
        void doExecution() const;
};
#endif