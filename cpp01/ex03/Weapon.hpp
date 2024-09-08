#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>

class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(void);
        Weapon(std::string type);
        const std::string& getType(void) const;
        void setType(std::string type);
};

#endif // __WEAPON_HPP__
