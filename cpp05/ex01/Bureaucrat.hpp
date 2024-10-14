#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat(const std::string name, int grade);
		const std::string& getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const _NOEXCEPT
				{
					return "Grade too high!";
				};
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const _NOEXCEPT
				{
					return "Grade too low!";
				};
		};
};

std::ostream & operator << (std::ostream &out, const Bureaucrat &b);

#endif //  __BUREAUCRAT_HPP__
