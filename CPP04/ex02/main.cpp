#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
    int i = 0;
    std::cout << BLUE << "Creating animals..."<< RESET << std::endl;
    const Animal* animals[4];
    while(i < 2)
        animals[i++] = new Dog();
    while(i < 4)
        animals[i++] = new Cat();
    
    std::cout << "---------------------------------" << std::endl;
    
    i = 0;
    std::cout << BLUE << "Making sounds..." << RESET << std::endl;
    
    while(i < 4) 
        animals[i++]->makeSound();
    
    std::cout << "---------------------------------" << std::endl;
    
    i = 0;
    std::cout << BLUE << "Deleting animals..." << RESET << std::endl;
    while(i < 4)
        delete animals[i++];
    std::cout << "---------------------------------" << std::endl;
    
    std::cout << BLUE << "Deep copy test for Dog using the copy constructor" << RESET << std::endl;
    Dog dog1;
    dog1.setIdea(0, "I want some steak!");
    Dog dog2(dog1);
    dog2.setIdea(0, "I want some bones!");
    std::cout << "Dog1's idea: " << dog1.getIdea(0) << std::endl;
    std::cout << "Dog2's idea: " << dog2.getIdea(0) << std::endl;
    
    std::cout << "---------------------------------" << std::endl;

    std::cout << BLUE << "Deep copy test for Cat using the copy assignment operator" << RESET << std::endl;
    Cat cat1;
    cat1.setIdea(0, "I want some fish!");
    Cat cat2;
    cat2 = cat1;
    cat2.setIdea(0, "I want some milk!");
    std::cout << "Cat1's idea: " << cat1.getIdea(0) << std::endl;
    std::cout << "Cat2's idea: " << cat2.getIdea(0) << std::endl;
    std::cout << "---------------------------------" << std::endl;

    return (0);
}