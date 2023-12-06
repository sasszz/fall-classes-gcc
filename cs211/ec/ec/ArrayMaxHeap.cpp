//
//  ArrayMaxHeap.cpp
//  ec
//
//  Created by Lucie Chevreuil on 12/6/23.
//

#ifndef _ARRAY_MAX_HEAP_CPP
#define _ARRAY_MAX_HEAP_CPP

#include <cmath>
#include "ArrayMaxHeap.h"


template <class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
    return (nodeIndex * 2 + 1);
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const
{
    return (nodeIndex * 2 + 2);
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const
{
    return (nodeIndex - 1) / 2;
}


template <class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const
{
    bool isLeaf = false;
    if (getLeftChildIndex(nodeIndex) >= itemCount)
        isLeaf = true;
    return isLeaf;
}

template <class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex)
{
    if (!isLeaf(subTreeRootIndex))
    {
        
        // The root must have a left child; assume it is the larger child
        int largerChildIndex = getLeftChildIndex(subTreeRootIndex);    // Left child index
        int rightChildIndex = largerChildIndex + 1;    // Right child index
        if (rightChildIndex < itemCount) // the root has a right child?
        { // yes!
            if (items[rightChildIndex] > items[largerChildIndex])
                largerChildIndex = rightChildIndex;    // Larger child index
        }
        // If the item in the root is smaller than the item in the larger child, swap items
        if (items[subTreeRootIndex] < items[largerChildIndex])
        {
            //Swap items[rootIndex] and items[largerChildIndex]
            ItemType temp = items[subTreeRootIndex];
            items[subTreeRootIndex] = items[largerChildIndex];
            items[largerChildIndex] = temp;
            // Transform the semiheap rooted at largerChildIndex into a heap
            heapRebuild(largerChildIndex);
        }

    // Else root is a leaf, so you are done
    }
}

template <class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
    for (int index = itemCount / 2; index >= 0; index--)
        heapRebuild(index);
}

template <class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
    items = new ItemType[maxItems];
}

template <class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize):
itemCount(arraySize), maxItems(arraySize * 2)
{
    items = new ItemType[maxItems];
    for (int x = 0; x < itemCount; x++)
        items[x] = someArray[x];
    heapCreate();
}

template <class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
    delete [] items;
    items = nullptr;
}

template <class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
    return itemCount;
}

template <class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
    if (itemCount == 0)
        return 0;
    return log2(itemCount) + 1;
}

template <class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const// throw (PrecondViolatedExcep)
{
    //if (isEmpty())
        //throw PrecondViolatedExcep("Attempted peek into empty heap");
    return items[ROOT_INDEX];
}

template <class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType & newData)
{
    if (itemCount == maxItems)
        return false; // no more room
    items[itemCount] = newData;
    int newDataIndex = itemCount;
    bool inPlace = false;
    while (newDataIndex > 0 && !inPlace)
    {
        int parentIndex = (newDataIndex - 1) / 2;
        if (items[newDataIndex] < items[parentIndex])
            inPlace = true;
        else
        {
            ItemType temp = items[newDataIndex];
            items[newDataIndex] = items[parentIndex];
            items[parentIndex] = temp;
            newDataIndex = parentIndex;
        }
    }
    itemCount++;
    return true;
}

template <class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
    if (isEmpty())
        return false;
    itemCount--;
    items[ROOT_INDEX] = items[itemCount];
    heapRebuild(ROOT_INDEX);
    return true;
}

template <class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
    itemCount = 0;
}



#endif
