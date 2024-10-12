#include "Animal.hpp"

Animal::Animal(void) : type("Unknown")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator = (const Animal& other)
{
    std::cout << "Animal copy assignement called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}


Animal::~Animal(void)
{
    std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
    return (type);
}

void Animal::makeSound(void) const
{
    std::cout << "No distinct sound!" << std::endl;
}
