#include "Ice.hpp"

Ice::Ice(void)
{
    type = "ice";
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    *this = other;
}

Ice& Ice::operator = (const Ice& other)
{
    AMateria::operator=(other);
    return (*this);
}

Ice::~Ice(void) {}

AMateria* Ice::clone(void) const
{
    AMateria *obj = new Ice();
    *obj = *this;
    return (obj);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
