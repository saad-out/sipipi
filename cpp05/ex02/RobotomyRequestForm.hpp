#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        const std::string _target;
        static int _count;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor) const;
};

#endif // __ROBOTOMYREQUESTFORM_HPP__
