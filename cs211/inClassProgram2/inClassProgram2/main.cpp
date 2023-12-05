//
//  main.cpp
//  CSIS4
//
//  Created by Tony Biehl on 11/14/23.
//

#include <iostream>
#include "BinarySearchTreeNode.hpp"

using namespace std;

void printVal(int& val){
    cout << val << endl;
}

int main() {
    // insert code here...
    int choice, value;
    BinarySearchTreeNode<int> bst;
    do
    {
        cout << "Binary Search Tree with TreeNode\n"
            << "1. Add value\n"
            << "2. Remove value\n"
            << "3. Print tree inorder\n"
            << "4. Print tree height\n"
            << "5. Recursively sum tree\n"
            << "0. Quit\n\n"
            << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                bst.add(value);
                break;
            case 2:
                cout << "Value to remove: ";
                cin >> value;
                if (bst.remove(value))
                    cout << "Value removed\n";
                else
                    cout << "Value not removed\n";
                break;
            case 3:
                bst.inorderTraverse(printVal);
                break;
            case 4:
                cout << bst.getHeight() << endl;
                break;
            case 5:
                cout << "The sum is: " << bst.sumTree() << endl;
                break;
            case 0:
                cout << "Quit\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 0);
    
    return 0;
}
