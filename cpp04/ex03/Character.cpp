#include "Character.hpp"

Character::Character(void) : name("unknown")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const std::string& name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& other)
{
    *this = other;
}

Character& Character::operator = (const Character& other)
{
    this->name = other.name;
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
        if (other.inventory[i] != NULL)
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
    return (*this);
}

Character::~Character(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] != NULL)
            delete inventory[i];
    }
}

const std::string& Character::getName(void) const
{
    return (name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if ((idx >= 0 && idx < 4) && inventory[idx] != NULL)
        inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if ((idx >= 0 && idx < 4) && inventory[idx] != NULL)
        inventory[idx]->use(target);
}
