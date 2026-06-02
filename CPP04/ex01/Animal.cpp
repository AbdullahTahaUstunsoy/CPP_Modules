#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal")
{
    std::cout << "Default constructor called for Animal" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
    std::cout << "Copy constructor called for Animal" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Copy assignment operator called for Animal" << std::endl;
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Destructor called for Animal" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "An animal makes a sound" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}