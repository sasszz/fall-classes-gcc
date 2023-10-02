//
//  DoublyNode.h
//  assignment4
//
//  Created by Lucie Chevreuil on 9/28/23.
//

#ifndef DoublyNode_hpp
#define DoublyNode_hpp

template <class ItemType>
class DoublyNode {
private:
    ItemType data;
    DoublyNode* next;
    DoublyNode* prev;

public:
    // Constructors
    DoublyNode() : next(nullptr), prev(nullptr) {}
    DoublyNode(const ItemType& item) : data(item), next(nullptr), prev(nullptr) {}

    // Public methods
    ItemType getData() const { return data; }
    DoublyNode* getNext() const { return next; }
    DoublyNode* getPrev() const { return prev; }
    void setData(const ItemType& item) { data = item; }
    void setNext(DoublyNode* nextNode) { next = nextNode; }
    void setPrev(DoublyNode* prevNode) { prev = prevNode; }
};

#include "DoublyNode.cpp"

#endif
