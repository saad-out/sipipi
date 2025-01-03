#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        // ShrubberyCreationForm
        std::cout << "=====> ShrubberyCreationForm" << std::endl;
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
    std::cout << std::endl;

    {
        // RobotomyRequestForm
        std::cout << "=====> RobotomyRequestForm" << std::endl;
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        RobotomyRequestForm f1("f1");
        RobotomyRequestForm f2("f2");

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
    std::cout << std::endl;


    {
        // PresidentialPardonForm
        std::cout << "=====> PresidentialPardonForm" << std::endl;
        Bureaucrat b1("b1", 1);
        Bureaucrat b2("b2", 150);
        PresidentialPardonForm f1("f1");
        PresidentialPardonForm f2("f2");

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
    std::cout << std::endl;

    {
        // Instantiate abstract class => should not compile
        /*AForm f;*/
    }

	return (0);
}
