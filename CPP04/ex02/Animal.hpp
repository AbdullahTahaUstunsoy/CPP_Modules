#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define RESET   "\033[0m"
#define BLUE    "\033[34m"

#include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif