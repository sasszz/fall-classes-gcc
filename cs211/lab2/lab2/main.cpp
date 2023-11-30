//
//  main.cpp
//  lab2
//
//  Created by Lucie Chevreuil on 11/28/23.
//

#include "LinkedBag.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    int choice;
    string userSubmission;
    int convertedValue;
    LinkedBag<int> myLinkedBag;

    do {
        cout << "Binary Search Tree Menu \n"
        << "1. Show size \n"
        << "2. Add new entry \n"
        << "3. Remove entry \n"
        << "4. Search for an entry \n"
        << "5. Give the count of an entry \n"
        << "6. Print the bag contents \n"
        << "7. Clear \n"
        << "0. Quit \n"
        << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Size of bag: ";
                cout << myLinkedBag.getCurrentSize() << endl;
                break;
            case 2:
                cout << "Submit entry that you would like added: ";
                getline(cin>>ws, userSubmission);
                convertedValue = stoi(userSubmission);
                myLinkedBag.add(convertedValue);
                cout << "Entry of " << convertedValue << " has been added." << endl;
                break;
            case 3:
                cout << "Submit entry that you would like removed: ";
                getline(cin>>ws, userSubmission);
                convertedValue = stoi(userSubmission);
                if(myLinkedBag.contains(convertedValue)) {
                    myLinkedBag.remove(convertedValue);
                    cout << "Entry of " << convertedValue << " has been removed." << endl;
                }
                else {
                    cout << "Entry of " << convertedValue << " does NOT exist in the bag." << endl;
                }
                break;
            case 4:
                cout << "Submit entry that you would like to search for: ";
                getline(cin>>ws, userSubmission);
                convertedValue = stoi(userSubmission);
                if(myLinkedBag.contains(convertedValue) == 1) {
                    cout << "Entry of " << convertedValue << " DOES exist in the bag." << endl;
                }
                else {
                    cout << "Entry of " << convertedValue << " does NOT exist in the bag." << endl;
                }
                break;
            case 5:
                cout << "Submit entry that you would like the count of: ";
                getline(cin>>ws, userSubmission);
                convertedValue = stoi(userSubmission);
                cout << "Entry of " << convertedValue << " occurs" << myLinkedBag.getFrequencyOf(convertedValue) << " times in the bag." << endl;
                break;
            case 6:
                cout << "Printing contents:" << endl;
                myLinkedBag.displayBagContents();
                break;
            case 7:
                cout << "Clear." << endl;
                myLinkedBag.clear();
                break;
            case 0:
                cout << "Quit."  << endl;
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
