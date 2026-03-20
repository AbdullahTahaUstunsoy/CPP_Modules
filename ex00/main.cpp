#include "Bureaucrat.hpp"

int main()
{
    std::cout << "Situation with no exceptions" << std::endl;
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
    
    std::cout << "Situation where exceptions are caught using specific exception types" << std::endl;
    try{
        Bureaucrat b4("Taha", 0);
    }
    catch (const Bureaucrat::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }
    try{
        Bureaucrat b3("Taha", 151); //-> throw GradeTooLowException() çağrılıyor yani GradeTooLowException sınıfından geçici bir nesne oluşturuluyor
        std::cout << b3 << std::endl; // yazdırılmayacak
    }
    catch (const Bureaucrat::GradeTooLowException& e){
        std::cout << e.what() << std::endl; // burada da oluşturulan geçici nesnenin what() fonksiyonu çağırılarak hata mesajı ekrana yazdırılıyor
    }
    std::cout << "Situation where exceptions are caught using the general exception" << std::endl;
    try{
        Bureaucrat b5("Taha", 0);
    }
    catch(const Bureaucrat::GradeTooLowException& e){
        std::cout << e.what() << std::endl;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        Bureaucrat b6("Taha", 151);
    }
    catch(const Bureaucrat::GradeTooHighException& e){
        std::cout << e.what() << std::endl;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    std::cout << "Increment and decrement test" << std::endl;
    try{
        Bureaucrat b7("Taha", 15);
        std::cout << b7 << std::endl; // yazdırılacak
        b7.incrementGrade(); // grade 14
        std::cout << b7 << std::endl; // yazdırılacak
        b7.decrementGrade(); // grade 15
        std::cout << b7 << std::endl; // yazdırılacak
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }

}


