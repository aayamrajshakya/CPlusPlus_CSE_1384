/*
Name: Aayam Shakya          NetID: as5160
Date: 17 April 2023         Due Date: 18 April 2023
Description: This program converts a binary number to its decimal equivalent using a stack data structure.
            The user is prompted to enter a binary number, which is stored in a stack. The program then converts 
            the binary number to decimal using the binaryToDecimal function, which iterates through the stack and computes
            the decimal equivalent using the 2^n formula. The user can choose to convert another binary number or exit the program 
            by responding to a simple yes/no prompt.
            
            Also, if the input is not a valid binary number, the program prints an error message and prompts the user to enter another binary number.
            
*/



#include <iostream>
#include <string>
#include <cmath>
#include "stack.h"

using namespace std;

int binaryToDecimal(Stack &binaryStack);

int main() {
    string input;
    string repeat;
    bool valid;
    cout << "Welcome to binary to decimal conversion." << endl << endl;

    do {
        Stack binaryStack;

        cout << "Enter in a binary number to convert: ";
        cin >> input;

        for (char c : input) {
            binaryStack.add(c);
        }

        int decimal = binaryToDecimal(binaryStack);
        if (decimal == 0) {
            continue;
        }
        cout << "Your number converted is: " << decimal << endl << endl;

        do {
            valid = true;
            cout << "Would you like to enter another binary number (yes/no)? ";
            cin >> repeat;
            if (repeat != "yes" && repeat != "no") {
                cout << "That's not a valid response. Try again." << endl << endl;
                valid = false;
            }
        } while (!valid);

    } while (repeat == "yes");

    cout << "Good-bye!" << endl;

    return 0;
}

int binaryToDecimal(Stack &binaryStack) {
    int decimal = 0;
    int power = 0;

    while (true) {
        char current = binaryStack.remove();
        if (current == '\0') {
            break;
        }
        if (current != '0' && current != '1') {
            cerr << "Your input is not a binary number. Try again." << endl;
            return 0;
        }
        if (current == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}