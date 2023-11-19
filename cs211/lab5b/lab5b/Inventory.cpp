//
//  Inventory.cpp
//  lab5b
//
//  Created by Lucie Chevreuil on 11/18/23.
//
// Inventory.cpp

#include "Inventory.h"
#include <iomanip>
#include <string>

using namespace std;

// Constructor
Inventory::Inventory(int q, double pp, const string& pn)
    : quantity(q), pricePer(pp), productName(pn) {}

// Getter for quantity
int Inventory::getQuantity() const {
    return quantity;
}

// Getter for pricePer
double Inventory::getPricePer() const {
    return pricePer;
}

// Getter for productName
string Inventory::getProductName() const {
    return productName;
}

// Calculate the value of the inventory
double Inventory::value() const {
    return quantity * pricePer;
}

// Overloaded == operator
bool Inventory::operator==(const Inventory& other) const {
    return (quantity == other.quantity) &&
           (pricePer == other.pricePer) &&
           (productName == other.productName);
}

// Overloaded > operator
bool Inventory::operator>(const Inventory& other) const {
    return value() > other.value();
}

// Overloaded != operator
bool Inventory::operator!=(const Inventory& other) const {
    return !(*this == other);
}

// Friend function to overload the << operator
ostream& operator<<(ostream& os, const Inventory& obj) {
    os 
       << "| " << setw(16) << left << obj.productName << " | $"
       << setw(9) << fixed << setprecision(2) << right << obj.pricePer << " | "
       << setw(8) << left << obj.quantity << " | $"
       << setw(13) << fixed << setprecision(2) << right << (obj.pricePer * obj.quantity) << " |";

    return os;
}
