#include "PhoneBook.hpp"
#include "Colors.hpp"
#include <cstdlib>

#define MAX_CONTACTS 8

bool is_valid_phone_number(std::string& nbr)
{
    std::string whitespaces = " \t\v\n";

    int i = 0;
    while (whitespaces.find(nbr[i]) != std::string::npos)
        i++;
    while (nbr[i] >= '0' && nbr[i] <= '9')
        i++;
    while (whitespaces.find(nbr[i]) != std::string::npos)
        i++;
    return (nbr[i] == '\0');
}

PhoneBook::PhoneBook() {
    index = 0;
}

void PhoneBook::new_contact() {
    std::string fname;
    std::string lname;
    std::string nname;
    std::string num;
    std::string sec;

    std::cout << "Enter first name: ";
    std::getline(std::cin >> std::ws, fname);
    if (std::cin.eof())
        exit(1);
    std::cout << "Enter last name: ";
    std::getline(std::cin >> std::ws, lname);
    if (std::cin.eof())
        exit(1);
    std::cout << "Enter nickname: ";
    std::getline(std::cin >> std::ws, nname);
    if (std::cin.eof())
        exit(1);
    std::cout << "Enter phone number: ";
    std::getline(std::cin >> std::ws, num);
    if (std::cin.eof())
        exit(1);
    while (!is_valid_phone_number(num))
    {
        if (std::cin.eof())
            exit(1);
        std::cout << RED << "Invalid phone number. Try again: " << RESET;
        std::cout << "Enter phone number: ";
        std::getline(std::cin >> std::ws, num);
    }
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin >> std::ws, sec);
    if (std::cin.eof())
        exit(1);

    contacts[index % MAX_CONTACTS].set_first_name(fname);
    contacts[index % MAX_CONTACTS].set_last_name(lname);
    contacts[index % MAX_CONTACTS].set_nickname(nname);
    contacts[index % MAX_CONTACTS].set_phone_number(num);
    contacts[index % MAX_CONTACTS].set_darkest_secret(sec);
    contacts[index % MAX_CONTACTS].set_index(index % MAX_CONTACTS);
    index++;
}

Contact* PhoneBook::get_contacts() {
    return contacts;
}

int PhoneBook::get_size() {
    return (index < MAX_CONTACTS ? index : MAX_CONTACTS);
}

void PhoneBook::display_contact(int index) {
    std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].get_darkest_secret() << std::endl;
}
