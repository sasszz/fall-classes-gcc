//
//  ArrayStack.hpp
//  lab3_hpair
//
//  Created by Lucie Chevreuil on 10/25/23.
//

#ifndef ArrayStack_hpp
#define ArrayStack_hpp

#include "StackInterface.h"

const int MAX_STACK = 50;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType>
{
private:
    ItemType items[MAX_STACK]; // Array of stack items
    int top; // Index to top of stack

public:
    ArrayStack(); // Default constructor
    bool isEmpty() const;
    bool push(const ItemType& newEntry);
    bool pop();
    ItemType peek() const;
}; // end ArrayStack

#include "ArrayStack.cpp"

#endif
