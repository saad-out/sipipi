#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other), brain(NULL)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog& Dog::operator = (const Dog& other)
{
    std::cout << "Dog copy assignement called" << std::endl;
    Animal::operator=(other);
    if (brain)
        delete brain;
    Brain *newBrain = new Brain();
    brain = newBrain;
    *brain = *(other.brain);
    return (*this);
}


Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound(void) const
{
    std::cout << "Haw Haw!" << std::endl;
}

Brain* Dog::getBrain(void) const
{
    return (brain);
}
