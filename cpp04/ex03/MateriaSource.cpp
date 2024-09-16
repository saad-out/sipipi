#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
        stock[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    *this = other;
}

MateriaSource& MateriaSource::operator = (const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->stock[i] != NULL)
            delete this->stock[i];
        this->stock[i] = other.stock[i]->clone();
    }
    return (*this);
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->stock[i] != NULL)
            delete this->stock[i];
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (stock[i] == NULL)
        {
            stock[i] = m->clone();
            delete m;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < 4; i++)
    {
        if (stock[i] != NULL && stock[i]->getType() == type)
            return (stock[i]->clone());
    }
    return (NULL);
}

