/*
Name: Aayam Shakya                       NetID: as5160
Date: 2/24/2023                         Due Date: 3/3/2023

Description: This program is an address book manager that allows the user to read, add, and delete
            contacts in a file named "contacts.txt". Contacts are stored in a vector of Person objects, 
            each representing a person's information including their first name, last name, phone number, 
            and email address. The program provides a menu-based user interface for interacting with the address book, 
            and reads from and writes to the contacts file as needed.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "person.h"

using namespace std;

void readContacts(vector<Person>& contacts, string filename) {
    ifstream file(filename);

    if (file.is_open()) {
        string line;

        while (getline(file, line)) {
            stringstream ss(line);
            string firstName, lastName, phone, email;
            ss >> firstName >> lastName >> phone >> email;

            Person person;
            person.setFirstName(firstName);
            person.setLastName(lastName);
            person.setPhone(phone);
            person.setEmail(email);

            contacts.push_back(person);
        }

        file.close();
    }
    else {
        cout << "Unable to open file " << filename << endl;
    }
}

void addContacts(vector<Person>& contacts, string filename) {
    string firstName, lastName, phone, email;
    cout << "Let's gather some information!" << endl;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter phone number: ";
    cin >> phone;
    cout << "Enter email: ";
    cin >> email;

    Person person;
    person.setFirstName(firstName);
    person.setLastName(lastName);
    person.setPhone(phone);
    person.setEmail(email);

    contacts.push_back(person);

    ofstream file(filename, ios_base::app);
    if (file.is_open()) {
        file << firstName << " " << lastName << " " << phone << " " << email << endl;
        file.close();
    }
    else {
        cout << "Unable to open file " << filename << endl;
    }
}

void displayContacts(vector<Person>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts found." << endl << endl;
    }
    else {
        for (int i = 0; i < contacts.size(); i++) {
            cout << "Contact " << i+1 << ":" << endl;
            cout << "Name: " << contacts[i].getFirstName() << " " << contacts[i].getLastName() << endl;
            cout << "Phone number: " << contacts[i].getPhone() << endl;
            cout << "Email address: " << contacts[i].getEmail() << endl << endl;
            cout << endl;
        }
    }
}
void deleteContact(vector<Person>& contacts, string filename) {
    if (contacts.empty()) {
        cout << "No contacts found." << endl << endl;
        return;
    }

    displayContacts(contacts);

    int indexToDelete;
    cout << "Enter the index of the contact to delete: ";
    cin >> indexToDelete;

    if (indexToDelete < 1 || indexToDelete > contacts.size()) {
        cout << "Invalid index." << endl << endl;
        return;
    }

    contacts.erase(contacts.begin() + (indexToDelete - 1));

    ofstream file(filename, ios::out);
    if (file.is_open()) {
        for (int i = 0; i < contacts.size(); i++) {
            file << contacts[i].getFirstName() << " "
                 << contacts[i].getLastName() << " "
                 << contacts[i].getPhone() << " "
                 << contacts[i].getEmail() << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open file " << filename << endl;
    }

    cout << "Contact deleted." << endl << endl;
}

int main() {
    vector<Person> contacts;
    string filename;
    cout << "Welcome to your address book manager!" << endl;
    
    while (true) {
        
        cout << "Please enter the name of the file to read your contacts from (include extension): ";
        cin >> filename;

        ifstream file(filename);
        if (file.good()) {
            cout << "File read. Closing the file from read mode." << endl << endl;
            file.close();
            break;
        }
        else {
            cout << "Incorrect filename. Please try again." << endl << endl;
        }
    }

    readContacts(contacts, filename);

    int option = -1;

    while (option != 4) {
        cout << "Menu:" << endl;
        cout << "1. Display Contacts" << endl;
        cout << "2. Add Contacts" << endl;
        cout << "3. Delete Contacts" << endl;
        cout << "4. Exit" << endl;
        cout << "Select an option: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1:
                displayContacts(contacts);
                break;
            case 2:
                addContacts(contacts, filename);
                break;
            case 3:
                deleteContact(contacts, filename);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl << endl;
                break;
        }
    }

    return 0;
}
