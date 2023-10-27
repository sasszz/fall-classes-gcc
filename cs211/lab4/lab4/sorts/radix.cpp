#ifndef RADIX_CPP
#define RADIX_CPP

#include <cmath>

#include "sortSupport.h"
#include "Node.h"
#include "radix.h"

template <class ItemType>
void radixSort(ItemType theArray[], int n, int d)
{
	Node<ItemType>* bucket[10];
	Node<ItemType>* bucketEnd[10];
	int counter;

	for (int j = d; j >= 1; j--)
	{
		for (int bIndex = 0; bIndex < 10; bIndex++)
		{
			bucket[bIndex] = nullptr;
			bucketEnd[bIndex] = nullptr;
		}
		for (int i = 0; i < n; i++)
		{
			int dDigit = d - j;
			int mDigit = dDigit + 1;
			int k = (theArray[i] % (int)pow(10, mDigit)) / (int)pow(10, dDigit);

			Node<ItemType>* newNode = new Node<ItemType>(theArray[i]);
			if (bucket[k] == nullptr)
			{
				bucket[k] = newNode;
				bucketEnd[k] = newNode;
			}
			else
			{
				bucketEnd[k]->setNext(newNode);
				bucketEnd[k] = newNode;
			}
		}

		counter = 0;
		for (int bIndex = 0; bIndex < 10; bIndex++)
		{
			Node<ItemType>* cur = bucket[bIndex];
			while (cur != nullptr)
			{
				theArray[counter] = cur->getItem();
				counter++;
				Node<ItemType>* deletePtr = cur;
				cur = cur->getNext();
				delete deletePtr;
			}
		}
	}
}
#endif
