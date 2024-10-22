#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
        Bureaucrat();
		Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

		const std::string& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signAForm(AForm& form) const;
        void executeAForm(AForm const &form) const;

		class GradeTooHighException: public std::exception
		{
			public:
				/*const char *what() const _NOEXCEPT*/
				const char *what() const throw()
				{
					return "Grade too high!";
				};
		};
		class GradeTooLowException: public std::exception
		{
			public:
				/*const char *what() const _NOEXCEPT*/
				const char *what() const throw()
				{
					return "Grade too low!";
				};
		};
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &b);

#endif //  __BUREAUCRAT_HPP__
