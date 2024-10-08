#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator = (const ScavTrap& other);
        ~ScavTrap(void);

        void attack(const std::string &target);
        void guardGate(void);
        /*void info(void); // for dev info only*/
};

#endif // __SCAVTRAP__HPP__
