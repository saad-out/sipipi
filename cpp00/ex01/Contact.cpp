#include "Contact.hpp"

void Contact::set_first_name(std::string fname) {
    first_name = fname;
}
void Contact::set_last_name(std::string lname) {
    last_name = lname;
}
void Contact::set_nickname(std::string nname) {
    nickname = nname;
}
void Contact::set_phone_number(std::string num) {
    phone_number = num;
}
void Contact::set_darkest_secret(std::string sec) {
    darket_secret = sec;
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
