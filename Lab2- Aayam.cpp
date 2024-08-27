/*
Name: Aayam Shakya
NetID: as5160
Submission Date: 2023-02-03
Due Date: 2023-02-03
Instructor: Mr. Aubrey Knight
Program Description: This program uses a combination of while and nested for-loop to
                     generate a coordinate grid based on two sets of user-entered coordinate points.
*/

#include <iostream>

using namespace std;

int main() 
{
    int x1, y1, x2, y2;

    cout << "Enter the starting coordinate points (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Enter the ending coordinate points (x2, y2): ";
    cin >> x2 >> y2;

    while (x2 >= x1 || y2 >= y1) 
    {
        cout << "The ending coordinates must be lower in value than the starting coordinates. Try again." << endl;
        cout << "Enter the ending coordinates again: ";
        cin >> x2 >> y2;
    }
    
    cout << "Result: " << endl;
    for (int i = y1; i >= y2; i--) 
        {
            for (int j = x1; j >= x2; j--) 
        {
        cout << "(" << j << ", " << i << ")" << " ";
        }
    cout << endl;
    }

    return 0;
}