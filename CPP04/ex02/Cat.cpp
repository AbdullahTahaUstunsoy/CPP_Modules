#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
    type = "Cat";
    std::cout << "Default constructor called for Cat" << std::endl;
    brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Copy constructor called for Cat" << std::endl;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Copy assignment operator called for Cat" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Destructor called for Cat" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

std::string Cat::getIdea(int index) const
{
    return (brain->getIdea(index));
}

void Cat::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}