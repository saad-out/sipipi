#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Unknown")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& other)
{
    std::cout << "WrongAnimal copy assignement called" << std::endl;
    this->type = other.type;
    return (*this);
}


WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "No distinct sound!" << std::endl;
}
