#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Unknown") {
    std::cout << "FragTrap Default constructor called" << std::endl;
    hit = 100;
    energy = 100;
    damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap Name constructor called" << std::endl;
    hit = 100;
    energy = 100;
    damage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& other)
{
    std::cout << "FragTrap Copy assignement constructor called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "High fives!!" << std::endl;
}

/*void FragTrap::info2(void)*/
/*{*/
/*    std::cout << "name: " << name*/
/*              << " hit: " << hit*/
/*              << " energy: " << energy*/
/*              << " damage: " << damage << std::endl;*/
/*}*/
