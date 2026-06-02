#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "Default constructor called for WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
    std::cout << "Copy constructor called for WrongAnimal" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "Copy assignment operator called for WrongAnimal" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor called for WrongAnimal" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "A WrongAnimal makes a sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}