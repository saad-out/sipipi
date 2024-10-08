#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        unsigned int hit;
        unsigned int energy;
        unsigned int damage;
    
    public:
        ClapTrap(void);
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &other);
        ClapTrap& operator = (const ClapTrap &other);
        ~ClapTrap(void);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        /*void info(void); // debug*/
};

#endif // __CLAPTRAP_HPP__
