//
//  ArrayBag.cpp
//  assignment3
//
//  Created by Lucie Chevreuil on 9/19/23.
//

#include "ArrayBag.h"
#include <iostream>

using namespace std;

ArrayBag::ArrayBag() : size(0) {}

void ArrayBag::add(int item) {
    if (size < MAX_SIZE) {
        elements[size++] = item;
    } else {
        cout << "ArrayBag is full. Cannot add more items." << endl;
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
