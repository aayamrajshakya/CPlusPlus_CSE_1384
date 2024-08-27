#include <iostream>
#include <fstream>
#include <vector>
#include "professional.h"
#include "personal.h"

int main() {
    std::vector<Professional> profContacts;
    std::vector<Personal> persContacts;
    std::string filename;
    std::ifstream file;

    do {
        std::cout << "Enter the file name: ";
        std::cin >> filename;
        file.open(filename);
        if (!file) {
            std::cout << "Invalid file. Please try again.\n";
        }
    } while (!file);

    std::string line;
    while (getline(file, line)) {
        if (line == "professional") {
            std::string first, last, cell, work, title;
            getline(file, first);
            getline(file, last);
            getline(file, cell);
            getline(file, work);
            getline(file, title);
            profContacts.push_back(Professional(first, last, cell, work, title));
        } else if (line == "personal") {
            std::string first, last, cell, bday, address, city, state, zip;
            getline(file, first);
            getline(file, last);
            getline(file, cell);
            getline(file, bday);
            getline(file, address);
            getline(file, city);
            getline(file, state);
            getline(file, zip);
            persContacts.push_back(Personal(first, last, cell, bday, address, city, state, zip));
        }
    }
    file.close();

    std::cout << "\nPersonal contacts:\n";
    for (size_t i = 0; i < persContacts.size(); i++) {
        std::cout << "Contact " << i+1 << ": " << persContacts[i].getFirst() << " " << persContacts[i].getLast() << "\n";
        std::cout << "Cell: " << persContacts[i].getCell() << "\n";
        std::cout << "Address: " << persContacts[i].getAddress() << "\n";
        std::cout << "Birthday: " << persContacts[i].getBirthday() << "\n\n";
    }

    std::cout << "Business contacts:\n";
    for (size_t i = 0; i < profContacts.size(); i++) {
        std::cout << "Contact " << i+1 << ": " << profContacts[i].getFirst() << " " << profContacts[i].getLast() << "\n";
        std::cout << "Cell: " << profContacts[i].getCell() << "\n";
        std::cout << "Work: " << profContacts[i].getWork() << "\n";
        std::cout << "Title: " << profContacts[i].getTitle() << "\n\n";
    }

    return 0;
}
