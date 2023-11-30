//
//  LinkedBag.h
//  lab2
//
//  Created by Lucie Chevreuil on 11/28/23.
//

/** ADT bag: Linked-based implementation.
 @file LinkedBag.h */

#ifndef _LINKED_BAG_H
#define _LINKED_BAG_H

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node
    int itemCount;                       // Current count of bag items

    // Returns either a pointer to the node containing a given entry
    // or the null pointer if the entry is not in the bag.
    Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& aBag);  // Copy constructor
    virtual ~LinkedBag();                                             // Destructor should be virtual
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    void displayBagContents() const;
    vector<ItemType> toVector() const;
}; // end LinkedBag

#include "LinkedBag.cpp"

#endif
