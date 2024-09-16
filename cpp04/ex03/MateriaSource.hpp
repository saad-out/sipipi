#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* stock[4];

    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator = (const MateriaSource& other);
        ~MateriaSource(void);

        // virtual ~IMateriaSource() {}
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif // __MATERIASOURCE_HPP__
