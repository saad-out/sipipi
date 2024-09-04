#include "PhoneBook.hpp"

void PhoneBook::new_contact() {
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

Contact* PhoneBook::get_contacts() {
    return contacts;
}

int PhoneBook::get_size() {
    if (is_full)
        return 8;
    return index;
}

void PhoneBook::display_contact(int index) {
    std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].get_darkest_secret() << std::endl;
}
