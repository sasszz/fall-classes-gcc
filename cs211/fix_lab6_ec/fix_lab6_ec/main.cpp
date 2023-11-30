//
//  main.cpp
//  lab6
//
//  Created by Lucie Chevreuil on 11/27/23.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "BinarySearchTreeNode.hpp"

using namespace std;

void printVal(string& val) {
    cout << val << endl;
}

using namespace std;

int main() {
    int choice;
    string value;
    string filename;
    BinarySearchTreeNode<string> bst;
    
    do {
        cout << "Binary Search Tree Menu \n"
        << "1. Add value \n"
        << "2. Remove value \n"
        << "3. Write file \n"
        << "4. Read file \n"
        << "5. Show height \n"
        << "6. Print tree inorder \n"
        << "7. Balance tree from file \n"
        << "8. Quit \n"
        << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value: ";
                getline(cin>>ws, value);
                bst.add(value);
                break;
            case 2:
                cout << "Value to remove: ";
                getline(cin>>ws, value);
                if(bst.remove(value))
                    cout << "Value removed\n" ;
                else
                    cout << "Value not removed\n" ;
                break;
            case 3:
                cout << "Enter inorder filename: ";
                getline(cin>>ws, filename);
                bst.writeTree(filename);
                break;
            case 4:
                cout << "Enter filename to take inorder data: ";
                getline(cin>>ws, filename);
                bst.readTree(filename);
                break;
            case 5:
                cout << bst.getHeight() << endl;
                break;
            case 6:
                bst.inorderTraverse(printVal);
                break;
            case 7:
                cout << "Provide filename: \n";
                getline(cin>>ws, filename);
                cout << "Writing tree to file...\n";
                bst.writeTree(filename);
                bst.clear(); // Erase tree
                cout << "Balancing tree from file...\n";
                bst.readTreeEC(filename);
                break;
            case 8:
                cout << "Quit.\n";
                break;
            default:
                cout << "Invalid choice.\n";
                
        }
    } while (choice != 8);
    return 0;
}

// Office hour on Wednesday:
// Removing leaf Antonio causes tree height to skyrocket
// Professor able to replicate on his machine
