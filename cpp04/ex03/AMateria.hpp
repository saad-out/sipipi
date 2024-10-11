#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;

    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(const AMateria& other);
        AMateria& operator = (const AMateria& other);
        virtual ~AMateria(void);
    
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif // __AMATERIA_HPP__
