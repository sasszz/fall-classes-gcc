//
//  Inventory.hpp
//  lab5b
//
//  Created by Lucie Chevreuil on 11/18/23.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>

class Inventory {
private:
    int quantity;
    double pricePer;
    std::string productName;

public:
    // Constructor
    Inventory(int q, double pp, const std::string& pn);

    // Getter for quantity
    int getQuantity() const;

    // Getter for pricePer
    double getPricePer() const;

    // Getter for productName
    std::string getProductName() const;

    // Calculate the value of the inventory
    double value() const;

    // Overloaded == operator
    bool operator==(const Inventory& other) const;

    // Overloaded > operator
    bool operator>(const Inventory& other) const;

    // Overloaded != operator
    bool operator!=(const Inventory& other) const;

    // Friend function to overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const Inventory& obj);
    
};

#endif // INVENTORY_H
