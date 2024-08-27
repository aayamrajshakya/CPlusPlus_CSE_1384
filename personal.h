#ifndef PERSONAL_H
#define PERSONAL_H

#include "contact.h"

class Personal : public Contact {
public:
    Personal();
    Personal(std::string first, std::string last, std::string cell, std::string birthday,
             std::string address, std::string city, std::string state, std::string zip);

    // Getter functions
    std::string getBirthday() const;
    std::string getAddress() const;
    std::string getCity() const;
    std::string getState() const;
    std::string getZip() const;

    // Setter functions
    void setBirthday(std::string birthday);
    void setFullAddress(std::string address, std::string city, std::string state, std::string zip);

private:
    std::string birthday;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
};

#endif
