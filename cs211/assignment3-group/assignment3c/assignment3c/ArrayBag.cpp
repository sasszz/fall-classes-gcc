//
//  ArrayBag.cpp
//  assignment3c
//
//  Created by Lucie Chevreuil on 9/20/23.
//

#include "ArrayBag.h"

ArrayBag::ArrayBag() : size(0) {}

void ArrayBag::add(int item) {
    if (size < MAX_SIZE) {
        elements[size++] = item;
    }
}

int ArrayBag::getSize() const {
    return size;
}

int ArrayBag::sum() const {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += elements[i];
    }
    return total;
}

ArrayBag ArrayBag::merge(const ArrayBag& otherBag) const {
    ArrayBag mergedBag;
    for (int i = 0; i < size; i++) {
        mergedBag.add(elements[i]);
    }
    for (int i = 0; i < otherBag.size; i++) {
        mergedBag.add(otherBag.elements[i]);
    }
    return mergedBag;
}
