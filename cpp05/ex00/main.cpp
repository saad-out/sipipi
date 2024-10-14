#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	std::string name("jhon");

	{
		try {
			Bureaucrat b(name, 0);
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		try {
			Bureaucrat b(name, 151);
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		Bureaucrat b(name, 1);
		try {
			b.incrementGrade();
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		Bureaucrat b(name, 150);
		try {
			b.decrementGrade();
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		try {
			Bureaucrat b(name, -199);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}
