#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator = (const FragTrap& other);
        ~FragTrap(void);
        void info2(void); // for dev info only
        void highFivesGuys(void);
};

#endif // __FRAGTRAP_HPP__
