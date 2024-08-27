#include "professional.h"
using namespace std;

Professional::Professional() : Contact() {
    company = "";
    position = "";
    workNumber = "";
}

Professional::Professional(std::string first, std::string last, std::string cell, std::string workNumber, std::string company, std::string position) : Contact(first, last, cell) {
    this->workNumber = workNumber;
    this->company = company;
    this->position = position;
}

string Professional::getCompany() {
    return company;
}

string Professional::getPosition() {
    return position;
}

string getWorkNumber() {
    return workNumber;
}

void setCompany(string company) {
    this->company = company;
}

void setPosition(string position) {
    this->position = position;
}

void Professional::setWorkNumber(string workNumber) {
    this->workNumber = workNumber;
}
