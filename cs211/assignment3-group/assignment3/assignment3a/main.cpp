//
//  main.cpp
//  assignment3
//
//  Created by Lucie Chevreuil on 9/19/23.
//

#include "ArrayBag.h"
#include <iostream>

using namespace std;

int main() {
    ArrayBag bag;
    
    bag.add(10);
    bag.add(20);
    bag.add(30);

    int sum = bag.sum();
    cout << "Sum of all elements in the ArrayBag: " << sum << endl;

    return 0;
}
