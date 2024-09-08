#ifndef __HUMAN_B_HPP__
#define __HUMAN_B_HPP__

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
    
    public:
        HumanB(std::string name);
        void attack(void) const;
        void setWeapon(Weapon &weapon);
};

#endif // __HUMAN_B_HPP__
