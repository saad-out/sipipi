#include <iostream>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darket_secret;

    public:
        void set_first_name(std::string fname) {
            first_name = fname;
        }
        void set_last_name(std::string lname) {
            last_name = lname;
        }
        void set_nickname(std::string nname) {
            nickname = nname;
        }
        void set_phone_number(std::string num) {
            phone_number = num;
        }
        void set_darkest_secret(std::string sec) {
            darket_secret = sec;
        }
        std::string get_first_name() {
            return first_name;
        }
        std::string get_last_name() {
            return last_name;
        }
        std::string get_nickname() {
            return nickname;
        }
        std::string get_phone_number() {
            return phone_number;
        }
        std::string get_darkest_secret() {
            return darket_secret;
        }
};

class PhoneBook {
    private:
        Contact contacts[8];
        int     index;

    public:
        void new_contact() {
            if (index == 8)
                index = 0;
            std::string fname;
            std::string lname;
            std::string nname;
            std::string num;
            std::string sec;

            fname = "";
            while (fname == "")
            {
                std::cout << "Enter first name: ";
                std::cin >> fname;
            }
            while (lname == "")
            {
                std::cout << "Enter last name: ";
                std::cin >> lname;
            }
            while (nname == "")
            {
                std::cout << "Enter nickname: ";
                std::cin >> nname;
            }
            while (num == "")
            {
                std::cout << "Enter phone number: ";
                std::cin >> num;
            }
            while (sec == "")
            {
                std::cout << "Enter darkest secret: ";
                std::cin >> sec;
            }

            contacts[index].set_first_name(fname);
            contacts[index].set_last_name(lname);
            contacts[index].set_nickname(nname);
            contacts[index].set_phone_number(num);
            contacts[index].set_darkest_secret(sec);
            index++;
        }
    
    PhoneBook() : index(0) {}
};
