#include "Node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
    // Default constructor, initializes 'next' to nullptr
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr)
{
    // Constructor with an item, initializes 'item' and 'next'
}

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr)
{
    // Constructor with an item and a next node pointer, initializes 'item' and 'next'
}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
}

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
    return item;
}

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
    return next;
}
