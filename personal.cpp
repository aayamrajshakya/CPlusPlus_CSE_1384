#include "personal.h"

Personal::Personal() : Contact() {
    birthday = "";
    address = "";
    city = "";
    state = "";
    zip = "";
}

Personal::Personal(std::string first, std::string last, std::string cell, std::string birthday, std::string address, std::string city, std::string state, std::string zip) : Contact(first, last, cell) {
    this->birthday = birthday;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
}

std::string Personal::getBirthday() {
    return birthday;
}

std::string Personal::getAddress() {
    return address;
}

std::string Personal::getCity() {
    return city;
}

std::string Personal::getState() {
    return state;
}

std::string Personal::getZip() {
    return zip;
}

void Personal::setBirthday(std::string birthday) {
    this->birthday = birthday;
}

void Personal::setFullAddress(std::string address, std::string city, std::string state, std::string zip) {
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
}
