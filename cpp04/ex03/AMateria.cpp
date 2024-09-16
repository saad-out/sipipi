#include "AMateria.hpp"

AMateria::AMateria(void) : type("unknown") {}

AMateria::AMateria(const std::string& type) : type(type) {}

AMateria::AMateria(const AMateria& other)
{
    *this = other;
}

AMateria& AMateria::operator = (const AMateria& other)
{
    type = other.type;
    return (*this);
}

AMateria::~AMateria(void) {}

const std::string& AMateria::getType(void) const
{
    return (type);
}
