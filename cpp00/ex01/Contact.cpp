#include "Contact.hpp"

std::string trim(std::string& str)
{
    const char *whitespaces = " \t\v\n";

    size_t first = str.find_first_not_of(whitespaces);
    if (first == std::string::npos)
        return (str);
    size_t last = str.find_last_not_of(whitespaces);
    if (last == std::string::npos)
        last = str.length() - 1;
    return (str.substr(first, last - first + 1));
}

void Contact::set_first_name(std::string fname) {
    first_name = trim(fname);
}
void Contact::set_last_name(std::string lname) {
    last_name = trim(lname);
}
void Contact::set_nickname(std::string nname) {
    nickname = trim(nname);
}
void Contact::set_phone_number(std::string num) {
    phone_number = trim(num);
}
void Contact::set_darkest_secret(std::string sec) {
    darket_secret = trim(sec);
}
void Contact::set_index(int i) {
    index = i;
}
std::string Contact::get_first_name() {
    return first_name;
}
std::string Contact::get_last_name() {
    return last_name;
}
std::string Contact::get_nickname() {
    return nickname;
}
std::string Contact::get_phone_number() {
    return phone_number;
}
std::string Contact::get_darkest_secret() {
    return darket_secret;
}
int Contact::get_index() {
    return index;
}
