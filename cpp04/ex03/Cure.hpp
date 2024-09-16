#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(const Cure& other);
        Cure& operator = (const Cure& other);
        ~Cure(void);

        AMateria* clone(void) const;
        void use(ICharacter& target);
};

#endif // __CURE_HPP__
