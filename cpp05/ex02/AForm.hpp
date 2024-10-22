#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
// #include "Bureaucrat.hpp"

class Bureaucrat ;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _toSign;
        const int _toExec;

    public:
        AForm();
        AForm(const std::string name, int to_sign, int to_exec);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        ~AForm();

		const std::string& getName() const;
        bool isSigned() const;
        int toSign() const;
        int toExec() const;
        void beSigned(Bureaucrat &b);
        void execute(Bureaucrat const &executor) const;
        virtual void myType() const = 0;

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
        class FormNotSignedException: public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Form not signed!";
                };
        };
};

std::ostream & operator << (std::ostream &out, const AForm &f);

#endif // __FORM_HPP__
