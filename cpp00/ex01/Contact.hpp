#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <iostream>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darket_secret;
        int         index;

    public:
        void set_first_name(std::string fname);
        void set_last_name(std::string lname);
        void set_nickname(std::string nname);
        void set_phone_number(std::string num);
        void set_darkest_secret(std::string sec);
        void set_index(int i);
        std::string get_first_name();
        std::string get_last_name();
        std::string get_nickname();
        std::string get_phone_number();
        std::string get_darkest_secret();
        int get_index();
};

std::string trim(std::string& str);

#endif // __CONTACT_HPP__
