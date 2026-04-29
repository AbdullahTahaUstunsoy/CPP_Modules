#include "Array.hpp"
#include <string>

#define RESET   "\033[0m"
#define BLUE    "\033[34m"

class Cars
{
    private:
        std::string brand;
        int modelYear;
    public:
        Cars(): brand(), modelYear(0) {}
        Cars(std::string b, int year): brand(b) , modelYear(year){}
        Cars& operator=(const Cars& other)
        {
            if(this != &other)
            {
                brand = other.getBrand(); //other.brand burada olur fakat daha iyi olanı getBrand() yapmaktır çünkü bu bir template olsaydı her zaman other.brand çalışmayabilirdi çünkü farklı bir tür referans da gelebilir.
                modelYear = other.getModelYear();
            }
            return *this;
        }
        std::string getBrand() const
        {
            return brand;
        }
        int getModelYear() const
        {
            return modelYear;
        }
};
    std::ostream& operator<<(std::ostream& os, const Cars& car)
    {
        os << "Car Brand:" << car.getBrand() << std::endl;
        os << "Model Year:" << car.getModelYear() << std::endl;
        return os;
    }


int main()
{   
    std::cout << BLUE <<"---Testing with string type---" << RESET <<std::endl;
    std::string strArray[] = {"Hello", "World", "!"};
    Array<std::string> arr(3);
    for(unsigned int i = 0; i < arr.size(); i++)
        arr[i] = strArray[i];
    for(unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << BLUE <<"---Testing with int type---" << RESET <<std::endl;
    int intArray[] = {1, 2, 3};
    Array<int> arr2(3);
    for(unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = intArray[i];
    for(unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;
    std::cout << BLUE <<"---Initialized by Default Control---" << RESET <<std::endl;
    Array<int> arr3(3);
    for(unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << " "; // default olarak 0 atanır.
    std::cout << std::endl;
    Array<Cars> arr4(3);
    for(unsigned int i = 0; i < arr4.size(); i++)
        std::cout << arr4[i];
    //kendi yazığımız class'lar ile de bu template'in çalıştığını göstermek istedim.
    std::cout << BLUE <<"---Out of Range Control---" << RESET <<std::endl;
    Array<int> arr5(3);
    try{
        arr5[3] = 10; // index out of range hatası vermelidir.
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << BLUE << "---Empty Array Control---" << RESET << std::endl;
    try {
        Array<int> empty; // Boyut 0, array NULL
        std::cout << "Empty array size: " << empty.size() << std::endl;
        std::cout << empty[0] << std::endl; // Boyut 0 olduğu için erişim hatası vermelidir.
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << BLUE << "---Copy Constructor Control---" << RESET << std::endl;
    Array<int> original(3);
    for(unsigned int i = 0; i < original.size(); i++)
        original[i] = i + 1; // original array'ini 1, 2, 3 ile dolduralım.
    Array<int> copy = original; // copy constructor'ı test edelim.
    for(unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " "; // copy array'inin original array'inin aynısı olduğunu görmeliyiz.
    std::cout << std::endl;
    std::cout << BLUE << "---Assignment Operator Control---" << RESET << std::endl;
    Array<int> assigned(3);
    assigned = original; // assignment operator'ı test edelim.
    for(unsigned int i = 0; i < assigned.size(); i++)
        std::cout << assigned[i] << " "; // assigned array'inin original array'nin aynısı olduğunu görmeliyiz.
    std::cout << std::endl;
    std::cout << BLUE << "---Deep Copy Control---" << RESET << std::endl;
    original[0] = 42; // original array'inin ilk elemanını değiştirelim.
    std::cout << "Original: " << original[0] << std::endl;
    std::cout << "Copy: " << copy[0] << std::endl; // copy array'inin ilk elemanının hala 1 olduğunu görmeliyiz.
    std::cout << "Assigned: " << assigned[0] << std::endl; // assigned array'inin ilk elemanının hala 1 olduğunu görmeliyiz.
    return 0;
}