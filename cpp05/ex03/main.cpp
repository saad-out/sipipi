#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    {
        Intern someRandomInter;
        AForm *rrf;

        rrf = someRandomInter.makeForm("robotomy request", "Bender");
        if (rrf)
            delete rrf;
    }

    {
        Intern someRandomInter;
        AForm *rrf;

        rrf = someRandomInter.makeForm("shrubbery creation", "Bender");
        if (rrf)
            delete rrf;
    }

    {
        Intern someRandomInter;
        AForm *rrf;

        rrf = someRandomInter.makeForm("presidential pardon", "Bender");
        if (rrf)
            delete rrf;
    }

    {
        Intern someRandomInter;
        AForm *rrf;

        rrf = someRandomInter.makeForm("some class", "Bender");
        if (rrf)
            delete rrf;
    }

	return (0);
}
