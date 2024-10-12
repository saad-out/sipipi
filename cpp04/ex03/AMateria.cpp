#include "AMateria.hpp"

AMateria::AMateria(void) : type("unknown") {}

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
}

AMateria& AMateria::operator = (const AMateria& other)
{
    /*type = other.type;*/ // copying type is not necessary
    (void)other;
    return (*this);
}

AMateria::~AMateria(void) {}

const std::string& AMateria::getType(void) const
{
    return (type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}
