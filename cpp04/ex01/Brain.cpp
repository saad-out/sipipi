#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator = (const Brain &other)
{
    std::cout << "Brain copy assignement called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
    return (*this);
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

/*void Brain::setChar(char c)*/
/*{*/
/*    for (int i = 0; i < 100; i++)*/
/*        ideas[i] = c;*/
/*}*/
/**/
/*void Brain::printChar(void) const*/
/*{*/
/*    std::cout << ideas[0] << std::endl;*/
/*}*/
