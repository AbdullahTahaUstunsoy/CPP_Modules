#include "Bureaucrat.hpp"

int main()
{
    std::cout << "*****************************************" << std::endl;
    try{
        Bureaucrat b1("Taha", 1); // normal durum
        std::cout << b1 << std::endl; // yazdırılacak
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        Bureaucrat b2("Taha", 150); // normal durum
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "*****************************************" << std::endl;
    
    std::cout << "--------------------------------------" << std::endl;
    try{
        Bureaucrat b3("Taha", 151); // -> throw GradeTooLowException() çağırılıyor yani GradeTooHighException class'ından geçici bir nesne oluşturuluyor
        std::cout << b3 << std::endl; // yazdırılmayacak
    }
    catch (const Bureaucrat::GradeTooLowException& e){
        std::cout << e.what() << std::endl; // burada da oluşturulan geçici nesnenin what() fonksiyonu çağırılarak hata mesajı ekrana yazdırılıyor
    }
    try{
        Bureaucrat b4("Taha", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "--------------------------------------" << std::endl;

    std::cout << "*****************************************" << std::endl;
    try{
        Bureaucrat b5("Taha", 0);
    }
    catch(const Bureaucrat::GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "*****************************************" << std::endl;


}


