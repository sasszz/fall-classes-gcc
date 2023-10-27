#ifndef SORTSUPPORT_H
#define SORTSUPPORT_H

#include "bubbleSort.h"

const int MAX_VALUE = 10000;
const int MAX_SIZE = 10000;
const int MAX_DIGITS = 4;

template<class ItemType>
void makeArray(ItemType ary[], int max, int seed);

template<class ItemType>
void printEnds(ItemType ary[], int max);

#include "sortSupport.cpp"
#endif
