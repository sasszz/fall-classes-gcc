//
//  main.cpp
//  lab1
//
//  Created by Lucie Chevreuil on 9/14/23.
//
//  MAIN FILE
//  PSEUDOCODE AT BOTTOM

#include <iostream>
#include "recursion.h"
using namespace std;

int main() {
    int choice;
    
    do {
        cout << "Recursive Functions Test Menu" << endl;
        cout << "1. Recursive Factorial" << endl;
        cout << "2. Towers of Hanoi" << endl;
        cout << "3. Recursive Summation" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter selection: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int n;
                cout << "Enter a non-negative integer: ";
                cin >> n;
                unsigned long long result = recursiveFactorial(n);
                cout << "Factorial of " << n << " is " << result << endl;
                cout << endl;
                break;
            }
            case 2: {
                int n;
                cout << "Enter the number of disks: ";
                cin >> n;
                towersOfHanoi(n, 'A', 'B', 'C');
                cout << endl;
                break;
            }
            case 3: {
                int n;
                cout << "Enter an integer: ";
                cin >> n;
                int result = recursiveSummation(n);
                cout << "Summation of numbers from 1 to " << n << " is " << result << endl;
                cout << endl;
                break;
            }
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid selection. Please try again." << endl;
        }
    } while (choice != 0);
    
    return 0;
}

// PSEUDOCODE

// Declare variables

// Display menu with four options:
//  1. Calculate the factorial of a non-negative integer.
//  2. Solve the Towers of Hanoi puzzle.
//  3. Calculate the summation of numbers from 1 to a given integer.
//  0. Exit the program.

// Enter a DO/WHILE loop, repeatedly displaying the menu and waiting for the user's choice.
// DO: run program
// WHILE: userChoice != 0

//User selects one of the following actions:

// Recursive Factorial
// Prompts the user to enter a non-negative integer `n`.
// Call function and display output

// Towers of Hanoi
// Prompts the user to enter the number of disks `n`.
// Call function and display output

// Recursive Summation
// Prompts the user to enter an integer `n`.
// Call function and display output

// Exit
// Print a goodbye message and terminate  program.

// Invalid Selection
// Display an error message and allow the user to try again.

// The loop continues until the user chooses to exit (chooses 0).
