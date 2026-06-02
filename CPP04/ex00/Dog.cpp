#include "Animal.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    type = "Dog";
    std::cout << "Default constructor called for Dog" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)  
{
    std::cout << "Copy constructor called for Dog" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator called for Dog" << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Destructor called for Dog" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}