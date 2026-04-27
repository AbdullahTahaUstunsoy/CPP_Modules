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
    std::cout << x << " ";
}

void printCarsConst(const Cars& x) {
    std::cout << x << " ";
}

void printStr(std::string& x) {
    std::cout << x << " ";
}

void printStrConst(const std::string& x) {
    std::cout << x << " ";
}

void printInt(int& x) {
    std::cout << x << " ";
}

void printIntConst(const int& x) {
    std::cout << x << " ";
}

template <typename T>
void print(T& x){
    std::cout << x << " ";
}

int main()
{
    Cars cars[] = {Cars("BMW"), Cars("Mercedes"), Cars("Audi")};
    std::string str[] = {"Hello", "World", "!"};
    int numbers [] = {1, 2, 3, 4, 5};
    const int nums[] = {10, 20, 30, 40, 50};
    std::cout << "-----printCars-----" << std::endl;
    ::iter(cars, 3, printCars);
    std::cout << std::endl;
    std::cout << "-----printCarsConst-----" << std::endl;
    ::iter(cars, 3, printCarsConst);
    std::cout << std::endl;
    std::cout << "-----printStr-----" << std::endl;
    ::iter(str, 3, printStr);
    std::cout << std::endl;
    std::cout << "-----printStrConst-----" << std::endl;
    ::iter(str, 3, printStrConst);
    std::cout << std::endl;
    std::cout << "-----printInt-----" << std::endl;
    ::iter(numbers, 5, printInt);
    std::cout << std::endl;
    std::cout << "-----printIntConst-----" << std::endl;
    ::iter(numbers, 5, printIntConst);
    std::cout << std::endl;
    std::cout << "-----printIntConst with const array-----" << std::endl;
    ::iter(nums, 5, printIntConst);
    std::cout << std::endl;
    std::cout << "-----Instantiated Template Function-----" << std::endl;
    ::iter(cars, 3, print<Cars>);
    std::cout << std::endl;
    ::iter(str, 3, print<std::string>);
    std::cout << std::endl;
    ::iter(numbers, 5, print<int>);
    std::cout << std::endl;
    ::iter(nums, 5, print<const int>);
    std::cout << std::endl;
    
    return (0);
}