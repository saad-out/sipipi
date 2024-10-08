#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string name;
    
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator = (const DiamondTrap& other);
        ~DiamondTrap(void);

        void attack(const std::string &target);
        void whoAmI(void);
        /*void info5(void); // for dev only*/
};

#endif //  __DIAMONDTRAP_HPP__
