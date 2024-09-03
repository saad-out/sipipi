#include <iostream>
#include <iomanip>

class Contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darket_secret;
        int         index;

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
        void set_index(int i) {
            index = i;
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
        int get_index() {
            return index;
        }
};

class PhoneBook {
    private:
        Contact contacts[8];
        int     index;
        bool    is_full = false;

    public:
        void new_contact() {
            if (index == 8)
                index = 0, is_full = true;
            std::string fname;
            std::string lname;
            std::string nname;
            std::string num;
            std::string sec;

            std::cout << "Enter first name: ";
            std::cin >> fname;
            std::cout << "Enter last name: ";
            std::cin >> lname;
            std::cout << "Enter nickname: ";
            std::cin >> nname;
            std::cout << "Enter phone number: ";
            std::cin >> num;
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin >> std::ws, sec);

            contacts[index].set_first_name(fname);
            contacts[index].set_last_name(lname);
            contacts[index].set_nickname(nname);
            contacts[index].set_phone_number(num);
            contacts[index].set_darkest_secret(sec);
            contacts[index].set_index(index);
            index++;
        }

        Contact* get_contacts() {
            return contacts;
        }

        int get_size() {
            if (is_full)
                return 8;
            return index;
        }

        void display_contact(int index) {
            std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
            std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
            std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
            std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
            std::cout << "Darkest secret: " << contacts[index].get_darkest_secret() << std::endl;
        }
    
    PhoneBook() : index(0) {}
};

void    print_max_len(std::string str)
{
    std::setw(10);
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}

int main(int ac, char **av)
{
    std::string prompt = "Enter ADD, SEARCH or EXIT: ";
    PhoneBook phonebook;

    (void)ac;
    (void)av;
    std::string action = "";
    while (action != "EXIT")
    {
        std::cout << prompt;
        std::cin >> action;
        if (action == "ADD")
            phonebook.new_contact();
        else if (action == "SEARCH")
        {
            Contact *contacts = phonebook.get_contacts();
            int     size = phonebook.get_size();
            if (size == 0)
            {
                std::cout << "No contacts" << std::endl;
                continue;
            }
            for (int i = 0; i < size; i++)
            {
                std::cout << std::setw(10) << contacts[i].get_index() << "|";
                print_max_len(contacts[i].get_first_name());
                std::cout << "|";
                print_max_len(contacts[i].get_last_name());
                std::cout << "|";
                print_max_len(contacts[i].get_nickname());
                std::cout << std::endl;
            }
            int index;
            std::cout << "Enter index: ";
            std::cin >> index;
            while (std::cin.fail() || index < 0 || index >= size)
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid index. Enter index: ";
                std::cin >> index;
            }
            phonebook.display_contact(index);
        }
        else if (action == "EXIT")
            std::cout << "EXIT" << std::endl;
        else
            std::cout << "Invalid action" << std::endl;
    }
}
