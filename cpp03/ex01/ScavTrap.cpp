#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Unknown", 100, 50, 20) {
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& other)
{
    std::cout << "ScavTrap Copy assignement constructor called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (energy > 0 && hit > 0)
    {
        energy--;
        std::cout << "ScavTrap " << name << " attacks " << target
                << ", causing " << damage << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << name << " is exhausted!" << std::endl;
}

void ScavTrap::info(void)
{
    std::cout << "name: " << name
              << " hit: " << hit
              << " energy: " << energy
              << " damage: " << damage << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << name << " is now in Gate keeper mode" << std::endl;
}
