#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "-----------------------------" << std::endl;
    try
    {
        Bureaucrat b1("Taha", 40);
        Bureaucrat b2("Ahmet", 80);
        Form f1("SalesContract", 60, 60);

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;
        b2.signForm(f1);
        std::cout << f1 << std::endl;
        b1.signForm(f1);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------" << std::endl;
    try //invalid form
    {
        Form f2("LeaseAgreement", 1, 151); //gradeToExecute > 150 olduğu için exception throw olacak ve catch'e girecek
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------------------------" << std::endl;
    try //Increment grade'ten sonra sign olunabilsin
    {
        Bureaucrat b3("Mehmet", 40);
        Form f3("Contract", 39, 39);

        std::cout << b3 << std::endl;
        std::cout << f3 << std::endl;
        b3.signForm(f3); //grade 40 olduğu için imzalama işlemi başarısız olacak ve catch'e girecek
        std::cout << f3 << std::endl;
        b3.incrementGrade(); //grade 39 olacak
        b3.signForm(f3); //grade 39 olduğu için imzalama işlemi başarılı olacak ve "Mehmet signed Contract" mesajı basılacak
        std::cout << f3 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----------------------------" << std::endl;
    return 0;
}