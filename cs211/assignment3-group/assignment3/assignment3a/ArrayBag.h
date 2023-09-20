//
//  ArrayBag.hpp
//  assignment3
//
//  Created by Lucie Chevreuil on 9/19/23.
//

#ifndef ARRAYBAG_H
#define ARRAYBAG_H

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
};

#endif
