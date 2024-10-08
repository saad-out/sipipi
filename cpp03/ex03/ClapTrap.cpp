#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Unknown"), hit(10), energy(10), damage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit(10), energy(10), damage(0)
{
    std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &other)
{
    std::cout << "Copy assignement constructor called" << std::endl;
    this->name = other.name;
    this->hit = other.hit;
    this->energy = other.energy;
    this->damage = other.damage;
    return (*this);
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energy > 0 && hit > 0)
    {
        energy--;
        std::cout << "ClapTrap " << name << " attacks " << target
                << ", causing " << damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " is exhausted!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > hit)
        amount = hit;
    hit -= amount;
    std::cout << "ClapTrap " << name << " lost " << amount
              << " hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    hit += amount;
    std::cout << "ClapTrap " << name << " gets " << amount
              << " hit points back!" << std::endl;
}

/*void ClapTrap::info(void)*/
/*{*/
/*    std::cout << "name: " << name*/
/*              << " hit: " << hit*/
/*              << " energy: " << energy*/
/*              << " damage: " << damage << std::endl;*/
/*}*/
