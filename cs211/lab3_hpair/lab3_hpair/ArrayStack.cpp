//
//  ArrayStack.cpp
//  lab3_hpair
//
//  Created by Lucie Chevreuil on 10/25/23.
//

#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

#include "ArrayStack.hpp"
#include <cassert> // for assert

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1)
{
} // end default constructor

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const
{
    return top < 0;
}

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType& newEntry)
{
    bool result = false;
    if (top < MAX_STACK - 1) // Does the stack have room for newEntry?
    {
        top++;
        items[top] = newEntry;
        result = true;
    } // end if
    return result;
} // end push

template<class ItemType>
bool ArrayStack<ItemType>::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        top--;
        result = true;
    } // end if
    return result;
} // end pop

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const
{
    assert(!isEmpty()); // Enforce precondition
    // Stack is not empty; return the top
    return items[top];
} // end peek

#endif
// end of implementation file
