#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H

#include "contact.h"
#include <string>

class Professional : public Contact {
private:
    std::string company;
    std::string position;
    std::string workNumber;

public:
    Professional();
    Professional(std::string first, std::string last, std::string cell, std::string workNumber, std::string company, std::string position);
    std::string getCompany() const;
    std::string getPosition() const;
    std::string getWorkNumber() const;
    void setCompany(std::string company);
    void setPosition(std::string position);
    void setWorkNumber(std::string workNumber);
};

#endif
