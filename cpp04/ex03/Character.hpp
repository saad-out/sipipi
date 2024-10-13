#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

struct unequiped
{
    AMateria* materia;
    struct unequiped* next;
};
typedef struct unequiped t_unequiped;

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
        t_unequiped* unequiped;

    public:
        Character(void);
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator = (const Character& other);
        ~Character(void);

        std::string const & getName() const;
        void equip(AMateria* m);
        void add_to_unequiped(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
};

#endif // __CHARACTER_HPP__
