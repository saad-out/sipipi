#include "Cure.hpp"

Cure::Cure(void)
{
    type = "cure";
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    *this = other;
}

Cure& Cure::operator = (const Cure& other)
{
    AMateria::operator=(other);
    return (*this);
}

Cure::~Cure(void) {}

AMateria* Cure::clone(void) const
{
    AMateria *obj = new Cure();
    *obj = *this;
    return (obj);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

