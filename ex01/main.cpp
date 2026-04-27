#include "iter.hpp"

class Cars
{
    private:
        std::string brand;
    public:
        Cars(std::string b) : brand(b) {}
        std::string getBrand() const { return brand; }
};

std::ostream & operator<<(std::ostream& os, const Cars& car)
{
    os << car.getBrand();
    return os;         
}

void printCars(Cars& x) {
    std::cout << x.getBrand() << std::endl;
}

void printCarsConst(const Cars& x) {
    std::cout << x.getBrand() << std::endl;
}



int main()
{
    Cars cars[] = {Cars("BMW"), Cars("Mercedes"), Cars("Audi")};
    std::string str[] = {"Hello", "World", "!"};
    int numbers [] = {1, 2, 3, 4, 5};
    ::iter(cars, 3, printCars);
    std::cout << "-----------------" << std::endl;
    ::iter(cars, 3, printCarsConst);
    std::cout << "-----------------" << std::endl;

}

