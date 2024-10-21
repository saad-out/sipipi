#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
// #include "Bureaucrat.hpp"

class Bureaucrat ;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _toSign;
        const int _toExec;
    public:
        Form();
        Form(const std::string name, int to_sign, int to_exec);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

		const std::string& getName() const;
        bool isSigned() const;
        int toSign() const;
        int toExec() const;
        void beSigned(Bureaucrat &b);

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Grade too high!";
				};
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Grade too low!";
				};
		};
};

std::ostream & operator << (std::ostream &out, const Form &f);

#endif // __FORM_HPP__
