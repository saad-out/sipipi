#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : name("Unknown")
{
    std::cout << "DiamondTrap Default constructor called " <<  std::endl;
    ClapTrap::name = name + "_clap_name";
    hit = 100;
    energy = 50;
    damage = 30;
    // name = ClapTrap::name + "_clap_name";
    // // std::cout << name << "\n";
    // hit = FragTrap::hit;
    // energy = ScavTrap::energy;
    // damage = FragTrap::damage;
}

DiamondTrap::DiamondTrap(std::string new_name)
{
    // (void)name;
    std::cout << "DiamondTrap name constructor called " <<  std::endl;
    name = new_name;
    ClapTrap::name = name + "_clap_name";
    hit = 100;
    energy = 50;
    damage = 30;
    // name = ClapTrap::name + "_clap_name";
    // // std::cout << name << "\n";
    // hit = FragTrap::hit;
    // energy = ScavTrap::energy;
    // damage = FragTrap::damage;
    // std::cout << name << " " << hit << " " << energy << " " << damage << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    name = other.name;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& other)
{
    std::cout << "DiamondTrap Copy assignement constructor called" << std::endl;
    ClapTrap::operator=(other);
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap deconstructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "Name: (" << name
              << ") ClapTrapName: (" << ClapTrap::name << ")" << std::endl;
}

void DiamondTrap::info5(void)
{
    std::cout << "nameeee: " << name
              << " hit: " << hit
              << " energy: " << energy
              << " damage: " << damage << std::endl;
}
