#ifndef __PHONEBOOK_HPP__

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int     index;
        bool    is_full = false;

    public:
        void new_contact();
        Contact* get_contacts();
        int get_size();
        void display_contact(int index);

    PhoneBook(void);
};

#endif // __PHONEBOOK_HPP__

