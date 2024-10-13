#include "Character.hpp"

Character::Character(void) : name("unknown")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    unequiped = NULL;
}

Character::Character(const std::string& name)
{
    this->name = name;
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
    unequiped = NULL;
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
    t_unequiped* tmp = unequiped;
    while (tmp != NULL)
    {
        t_unequiped* next = tmp->next;
        if (tmp->materia != NULL)
            delete tmp->materia;
        delete tmp;
        tmp = next;
    }
    unequiped = NULL;
    tmp = other.unequiped;
    while (tmp != NULL)
    {
        add_to_unequiped(tmp->materia);
        tmp = tmp->next;
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
    t_unequiped* tmp = unequiped;
    while (tmp != NULL)
    {
        t_unequiped* next = tmp->next;
        if (tmp->materia != NULL)
            delete tmp->materia;
        delete tmp;
        tmp = next;
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

void Character::add_to_unequiped(AMateria* m)
{
    t_unequiped* tmp = new t_unequiped;
    tmp->materia = m;
    tmp->next = unequiped;
    unequiped = tmp;
}

void Character::unequip(int idx)
{
    if ((idx >= 0 && idx < 4) && inventory[idx] != NULL)
    {
        add_to_unequiped(inventory[idx]);
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if ((idx >= 0 && idx < 4) && inventory[idx] != NULL)
        inventory[idx]->use(target);
}
