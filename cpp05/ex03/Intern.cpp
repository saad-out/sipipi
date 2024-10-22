#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator = (const Intern& other)
{
    (void)other;
    return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string name, std::string target) const
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    while (i < 3 && names[i] != name)
        i++;
    switch (i) {
        case 0:
            return new ShrubberyCreationForm(target);
            break;
        case 1:
            return new RobotomyRequestForm(target);
            break;
        case 2:
            return new PresidentialPardonForm(target);
            break;
        default:
            std::cout << "Form type does not exist!" << std::endl;
            return NULL;
    }
}

