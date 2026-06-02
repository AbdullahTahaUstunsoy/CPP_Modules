#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
    type = "Dog";
    std::cout << "Default constructor called for Dog" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)  
{
    std::cout << "Copy constructor called for Dog" << std::endl;
    brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Copy assignment operator called for Dog" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Destructor called for Dog" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdea(int index) const
{
    return (brain->getIdea(index));
}

void Dog::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}
