#include "bubbleSort.h"

#ifndef BUBBLESORT_CPP
#define BUBBLESORT_CPP

using namespace std;

template<class ItemType>

void bubbleSort(ItemType theArray[], int n, int &numSwaps)
{
	bool sorted = false;
	int pass = 1;
	while (!sorted && (pass < n))
	{
		sorted = true;
		for (int index = 0; index < n - pass; index++)
		{
			int nextIndex = index + 1;
			if (theArray[index] > theArray[nextIndex])
			{
				swap(theArray[index], theArray[nextIndex]);
				sorted = false;
                numSwaps++;
			}
		}
		pass++;
	}
}
#endif
