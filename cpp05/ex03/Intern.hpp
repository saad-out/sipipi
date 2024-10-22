#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator = (const Intern& other);
        ~Intern();

        AForm* makeForm(std::string name, std::string target) const;
};

#endif // __INTERN_HPP__
