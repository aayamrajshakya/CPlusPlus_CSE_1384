/*
Name: Aayam Shakya          NetID: as5160
Date: April 27 2023         Due Date: May 1 2023
Description: This code defines a function called buildEq that takes in a string eqTemplate and a string tab. 
            The eqTemplate string consists of a mixture of characters that are used to create an equation template
            that the user is prompted to fill in.

            The function loops through the eqTemplate string character by character. If the character is an 'a', 
            the user is prompted to enter a number which is added to the equation string. If the character is 'b', 
            the user is prompted to enter a variable which is added to the equation string. If the character is a '(', 
            the function recursively calls itself with the sub-equation contained within the parenthesis. The sub-equation
            is added to the equation string within parentheses. Finally, the final equation string is returned by the function.

*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

// function declaration
string buildEq(string eqTemplate, string tab);

int main()
{
    // vector of equation templates to test...
    vector<string> equations{
        "a + a",
        "((b - b)^2 + (b - b)^2)^1/2",
        "a + b",
        "ab + (b - b / a(a + a))",
        "(a ^ a) + (a - a + b)",
        "ab"
    };

    cout << "Welcome to the equation builder!" << endl << endl;

    // iterates through the vector
    // calls function on each vector item
    for(int i = 0; i < equations.size(); i++)
    {
        cout << "Starting equation: " << equations[i] << endl << endl;

        // builds equation
        string eq = buildEq(equations[i], "");

        cout << endl << "Equation built: " << eq << endl << endl;
    }

    return 0;
}


string buildEq(string eqTemplate, string tab)
{
    string eqn = "";

    for (int i = 0; i < eqTemplate.length(); i++)
    {
        // If the current character is an 'a', ask for a number and add it to the equation string
        if (eqTemplate[i] == 'a')
        {
            cout << tab << "Enter in a number: ";
            string num;
            cin >> num;
            eqn += num;
        }
        // If the current character is a 'b', ask for a variable and add it to the equation string
        else if (eqTemplate[i] == 'b')
        {
            cout << tab << "Enter in a variable: ";
            string var;
            cin >> var;
            eqn += var;
        }
        // If the current character is a '(', this is a recursive case
        else if (eqTemplate[i] == '(')
        {
            eqn += '(';

            // Create a string to hold the sub-equation
            string subEqn = "";

            int ParenCount = 1;
            for (int j = i + 1; j < eqTemplate.length(); j++)
            {
                if (eqTemplate[j] == '(')
                {
                    ParenCount++;
                }
                else if (eqTemplate[j] == ')')
                {
                    ParenCount--;
                    if (ParenCount == 0)
                    {
                        subEqn = buildEq(eqTemplate.substr(i + 1, j - i - 1), tab + "\t");
                        i = j;
                        break;
                    }
                }
            }

            cout << tab << "Sub-equation: " << subEqn << endl;

            // Add the built sub-equation to the equation string
            eqn += subEqn;

            // Add the closing parenthesis to the equation string after the sub-equation has been built
            eqn += ')';
        }
        // If the character is anything else, add it to the equation string
        else
        {
            eqn += eqTemplate[i];
        }
    }

    // Return the built equation string
    return eqn;
}
