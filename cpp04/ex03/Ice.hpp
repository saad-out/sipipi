#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(const Ice& other);
        Ice& operator = (const Ice& other);
        ~Ice(void);

        AMateria* clone(void) const;
        void use(ICharacter& target);
};

#endif // __ICE_HPP__
