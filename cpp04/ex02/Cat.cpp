#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    brain = new Brain(); 
}

Cat::Cat(const Cat& other) : Animal(other), brain(NULL)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator = (const Cat& other)
{
    std::cout << "Cat copy assignement called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (brain)
            delete brain;
        if (other.brain)
        {
            brain = new Brain();
            *brain = *(other.brain);
        }
        else
            brain = NULL;
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound(void) const
{
    std::cout << "Meaow!" << std::endl;
}

Brain* Cat::getBrain(void) const
{
    return (brain);
}
