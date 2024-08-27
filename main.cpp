/*
Name: Aayam Shakya                       NetID: as5160
Date: 10 February 2023                   Due Date: 10 February 2023

Description: This is a program designed to manage quiz grades and provide average scores.
            The user is presented with a menu of options, including "display average", "display grades",
            and "add new grade". Once the user enters a choice, the program will perform the corresponding action.
            If the user selects "display average", the program will read in the grades from a file and compute the 
            average of the grades. If the user selects "display grades", the program will display all the grades 
            contained in the file. If the user selects "add new grade", the program will add a new grade to the 
            existing list of grades in the file. The program continues to run until the user selects "exit", at
            which point it will display a goodbye message and exit.
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<float> grades;

int main()
{
    cout << "Welcome to quiz grade averaging!" << endl << endl;

    // ***** file validation and file reading *****
    ifstream file;
    string fileName;
    while (1) {
        cout << "Enter the name of the file: ";
        cin >> fileName;
        cout << endl;
        file.open(fileName);
        if (file.is_open()) {
            break;
        }
        cout << "File not found, please try again." << endl << endl;
    }

    float grade;
    while (file >> grade) {
        grades.push_back(grade);
    }
    file.close();

    // menuing
    while (1)
    {
        string option;

        // displays menu
        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display average" << endl;
        cout << "2. Display grades" << endl;
        cout << "3. Add new grade" << endl;
        cout << "Enter choice: ";
        cin >> option;

        cout << endl;

        // exit
        if (option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // ***** add menu option handling *****
        if (option == "1") {
            float sum = 0;
            for (float g : grades) {
                sum += g;
            }
            cout << "The average of the grades is: " << sum / grades.size() << endl;
        } else if (option == "2") {
            for (int i = 0; i < grades.size(); i++) {
                cout << "Grade " << i + 1 << ": " << grades[i] << endl;
            }
        } else if (option == "3") {
            float newGrade;
            while (1) {
                cout << "Enter a new grade: ";
                cin >> newGrade;
                if (newGrade >= 0.0 && newGrade <= 100.0) {
                    grades.push_back(newGrade);
                    break;
                }
                cout << "Invalid grade, allowed range is (0-100)." << endl;
            }
        } else {
            cout << "Invalid option, please try again." << endl;
        }

        cout << endl;
    }
}    
 
