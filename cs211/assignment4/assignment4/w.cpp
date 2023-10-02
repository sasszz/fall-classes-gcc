//
//  LinkedBag.cpp
//  assignment4
//
//  Created by Lucie Chevreuil on 9/28/23.
//

#include "LinkedBag.hpp"

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry) {
    Node<ItemType>* newNodePtr = new Node<ItemType>();
    newNodePtr->setItem(newEntry);
    newNodePtr->setNext(nullptr);
    if (isEmpty()) {
        headPtr = newNodePtr;
    } else {
        Node<ItemType>* currentPtr = headPtr;
        while (currentPtr->getNext() != nullptr) {
            currentPtr = currentPtr->getNext();
        }
        currentPtr->setNext(newNodePtr);
    }
    itemCount++;
    return true;
}

