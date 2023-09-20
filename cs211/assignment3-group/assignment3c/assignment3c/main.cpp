//
//  main.cpp
//  assignment3c
//
//  Created by Lucie Chevreuil on 9/20/23.
//
#include "ArrayBag.h"
using namespace std;

int main() {
    ArrayBag bag1;
    ArrayBag bag2;

    bag1.add(10);
    bag1.add(20);

    bag2.add(30);
    bag2.add(40);

    cout << "Bag 1 Elements before merge:" << endl;
    for (int i = 0; i < bag1.getSize(); i++) {
        cout << bag1.sum() << endl;
    }

    cout << "Bag 2 Elements before merge:" << endl;
    for (int i = 0; i < bag2.getSize(); i++) {
        cout << bag2.sum() << endl;
    }

    ArrayBag mergedBag = bag1.merge(bag2);

    cout << "Merged Bag Elements:" << endl;
    for (int i = 0; i < mergedBag.getSize(); i++) {
        cout << mergedBag.sum() << endl;
    }

    cout << "Bag 1 Elements after merge:" << endl;
    for (int i = 0; i < bag1.getSize(); i++) {
        cout << bag1.sum() << endl;
    }

    cout << "Bag 2 Elements after merge:" << endl;
    for (int i = 0; i < bag2.getSize(); i++) {
        cout << bag2.sum() << endl;
    }

    return 0;
}
