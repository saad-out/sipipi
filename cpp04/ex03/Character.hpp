#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];

    public:
        Character(void);
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator = (const Character& other);
        ~Character(void);

        // virtual ~ICharacter() {}
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif // __CHARACTER_HPP__
