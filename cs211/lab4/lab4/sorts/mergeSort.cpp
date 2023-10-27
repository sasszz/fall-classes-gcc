#include "mergeSort.h"
#include "sortSupport.h"

#ifndef MERGESORT_CPP
#define MERGESORT_CPP

#include <iostream>
#include <string>

template<class ItemType>

void merge(ItemType theArray[], int first, int mid, int last, int &numSwaps)
{
    ItemType tempArray[MAX_SIZE];
    
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    
    int index = first1;
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (theArray[first1] <= theArray[first2])
        {
            tempArray[index] = theArray[first1];
            first1++;
        }
        else
        {
            tempArray[index] = theArray[first2];
            first2++;
            numSwaps++;
        }
        index++;
    }
    
    while (first1 <= last1)
    {
        tempArray[index] = theArray[first1];
        first1++;
        index++;
    }
    
    while (first2 <= last2)
    {
        
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    }
    
    for (index = first; index <= last; index++)
        theArray[index] = tempArray[index];
}


template<class ItemType>
void mergeSort(ItemType theArray[], int first, int last, int &numSwaps)
{
    if (first < last)
    {
        int mid = first + (last - first) / 2; // Index of midpoint
        
        mergeSort(theArray, first, mid, numSwaps);
        
        mergeSort(theArray, mid + 1, last, numSwaps);
        
        merge(theArray, first, mid, last, numSwaps);
    }
}
#endif
