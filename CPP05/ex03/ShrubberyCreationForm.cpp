#include "ShrubberyCreationForm.hpp"
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) ,target(other.target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::doExecution() const
{
    std::string fileName = this->getTarget() + "_shrubbery";
    std::ofstream outfile(fileName.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error: Could not create/open file " << fileName << std::endl;
        return;
    }
    outfile << "       .   " << std::endl;
    outfile << "      /*\\   " << std::endl;
    outfile << "     /***\\     " << std::endl;
    outfile << "    /*****\\    " << std::endl;
    outfile << "   /*******\\   " << std::endl;
    outfile << "  /*********\\  " << std::endl;
    outfile << " /***********\\ " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile.close();
}
