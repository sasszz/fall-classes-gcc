
#ifndef mergesort_h
#define mergesort_h

template<class ItemType>
void mergeSort(ItemType theArray[], int first, int last);

template<class ItemType>
void merge(ItemType theArray[], int first, int mid, int last);

#include "mergeSort.cpp"
#endif
