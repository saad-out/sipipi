#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		// Low grade to sign
		Form f("from_1", 1, 5);
		Bureaucrat b("Jhon", 3);
		b.signForm(f);
	}

	{
		// Valid grade to sign
		Form f("from_2", 1, 5);
		Bureaucrat b("Mike", 1);
		b.signForm(f);
	}
	return (0);
}
