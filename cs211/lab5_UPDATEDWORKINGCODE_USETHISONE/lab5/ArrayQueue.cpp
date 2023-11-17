
#ifndef ARRAY_QUEUE_CPP
#define ARRAY_QUEUE_CPP

#include "ArrayQueue.h"  // Header file

template<class ItemType>
ArrayQueue<ItemType>::ArrayQueue() : front(0), back(DEFAULT_CAPACITY - 1), count(0) {
    // Constructor implementation
} // No semicolon here

template<class ItemType>
bool ArrayQueue<ItemType>::isEmpty() const
{
   return count == 0;
} // end isEmpty

template<class ItemType>
bool ArrayQueue<ItemType>::enqueue(const ItemType& newEntry)
{
   bool result = false;
   if (count < DEFAULT_CAPACITY)
   {
      // Queue has room for another item
      back = (back + 1) % DEFAULT_CAPACITY;
      items[back] = newEntry;
      count++;
      result = true;
   } // end if
   
   return result;
} // end enqueue

template<class ItemType>
bool ArrayQueue<ItemType>::dequeue()
{
   bool result = false;
   if (!isEmpty())
   {
      front = (front + 1) % DEFAULT_CAPACITY;
      count--;
      result = true;
   } // end if
   
   return result;
} // end dequeue

template<class ItemType>
ItemType ArrayQueue<ItemType>::peekFront() const noexcept(false)
{
   // Enforce precondition
   if (isEmpty())
      throw PrecondViolatedExcep("peekFront() called with empty queue");
   
   // Queue is not empty; return front
   return items[front];
} // end peekFront
// End of implementation file.
#endif
