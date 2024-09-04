#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

void    print_max_len(std::string str)
{
    std::setw(10);
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << str;
}

int main(void)
{
    std::string prompt = "Enter ADD, SEARCH or EXIT: ";
    PhoneBook phonebook;

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
