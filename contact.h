#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
    Contact();
    Contact(std::string first, std::string last, std::string cell);

    // Getter functions
    std::string getFirst() const;
    std::string getLast() const;
    std::string getCell() const;

    // Setter functions
    void setFirst(std::string first);
    void setLast(std::string last);
    void setCell(std::string cell);

private:
    std::string first;
    std::string last;
    std::string cell;
};

#endif
