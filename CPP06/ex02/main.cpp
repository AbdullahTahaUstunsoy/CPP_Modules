#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate(void)
{
    int random = rand() % 3;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    }
    catch (const std::exception& e) {}

    try
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        (void)b;
        return;
    }
    catch (const std::exception& e) {}

    try
    {
        C& c = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return;
    }
    catch (const std::exception& e) {}
}

int main()
{
    srand(std::time(NULL));
    int i = 0;
    while (i < 3)
    {
        std::cout << "Test " << i + 1 << ":" << std::endl;
        Base* base = generate();
        std::cout << "Identifying with pointer: " << std::endl;
        identify(base);
        std::cout << "Identifying with reference: " << std::endl;
        identify(*base);
        delete base;
        i++;
    }
}