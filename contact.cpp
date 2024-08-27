#include "contact.h"
using namespace std;

Contact::Contact() {
    first = "";
    last = "";
    cell = "";
}

Contact::Contact(std::string first, std::string last, std::string cell) {
    this->first = first;
    this->last = last;
    this->cell = cell;
}

string Contact::getFirst() {
    return first;
}

string Contact::getLast() {
    return last;
}

string Contact::getCell() {
    return cell;
}

void Contact::setFirst(std::string first) {
    this->first = first;
}

void Contact::setLast(std::string last) {
    this->last = last;
}

void Contact::setCell(std::string cell) {
    this->cell = cell;
}
