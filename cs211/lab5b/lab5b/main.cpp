//
//  main.cpp
//  lab5b
//
//  Created by Lucie Chevreuil on 11/18/23.
//
// main.cpp
// main.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedSortedList.h"
#include "Inventory.h"

using namespace std;

int main() {
    LinkedSortedList<Inventory> inventoryList;

    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int quantity;
    double pricePer;
    string productName;

    while (inputFile >> quantity >> pricePer) {
        // Read the rest of the line to get the product name
        getline(inputFile >> ws, productName);

        // Create Inventory object and insert into the sorted list
        Inventory newItem(quantity, pricePer, productName);
        inventoryList.insertSorted(newItem);
    }

    inputFile.close();

    // Display the inventory report
    cout << "Mustang Sally’s electronics store" << endl;
    cout << "| Product Name     | Price Per  | Quantity | Value on hand  |\n"
    << "|------------------|------------|----------|----------------|\n";
    

    inventoryList.displayInventory();
    
    double totalValue = inventoryList.calculateTotalValue();
    cout << "|------------------|------------|----------|----------------|\n";
    cout << "| Total Value                              | " << setw(14) << totalValue << " |\n";

    return 0;
}
