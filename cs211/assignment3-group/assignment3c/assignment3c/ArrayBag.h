//
//  ArrayBag.hpp
//  assignment3c
//
//  Created by Lucie Chevreuil on 9/20/23.
//

#ifndef ARRAYBAG_H
#define ARRAYBAG_H

#include <iostream>

const int MAX_SIZE = 100;

class ArrayBag {
private:
    int elements[MAX_SIZE];
    int size;

public:
    ArrayBag();
    void add(int item);
    int getSize() const;
    int sum() const;
    ArrayBag merge(const ArrayBag& otherBag) const;
};

#endif
