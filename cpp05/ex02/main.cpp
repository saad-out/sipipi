#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        // ShrubberyCreationForm
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        ShrubberyCreationForm f1("f1");
        ShrubberyCreationForm f2("f2");

        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        try {
            f1.beSigned(b1);
            f1.execute(b1);
            std::cout << "f1 executed" << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }

        try {
            f2.beSigned(b2);
            f2.execute(b2);
            std::cout << "f2 executed" << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
	return (0);
}
