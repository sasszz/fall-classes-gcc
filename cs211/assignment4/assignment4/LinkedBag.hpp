//
//  LinkedBag.hpp
//  assignment4
//
//  Created by Lucie Chevreuil on 9/28/23.
//
#ifndef LinkedBag_hpp
#define LinkedBag_hpp

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType> {
private:
    Node<ItemType>* headPtr;
    int itemCount;

    Node<ItemType>* getPointerTo(const ItemType& target) const;

public:
    LinkedBag();
    LinkedBag(const LinkedBag<ItemType>& aBag);
    virtual ~LinkedBag();

    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;
};

#include "LinkedBag.cpp"

#endif
