//
//  main.cpp
//  lab4
//
//  Created by Lucie Chevreuil on 10/26/23.
//

#include <iostream>
#include <iomanip>

#include "mergeSort.h"
#include "bubbleSort.h"
#include "radix.h"

using namespace std;

void printStyledTitle(const string &title) {
    int titleWidth = title.length() + 4;
    
    // Print top border
    cout << setfill('*') << setw(titleWidth) << "" << endl;
    
    // Print title
    cout << "* " << title << " *" << endl;
    
    // Print bottom border
    cout << setfill('*') << setw(titleWidth) << "" << endl;
}

int main() {
    
    unsigned int seed;
    cout << "Enter the seed to use: ";
    cin >> seed;
    cout << endl;

    srand(seed); // use this line to reset after each sort

    const int arraySize = 10000;
    
    int aryBubble[arraySize];
    int aryMerge[arraySize];
    int aryRadix[arraySize];
    
    int temp[arraySize];
    
    for (int x = 0; x < arraySize; x++) {
        aryBubble[x] = rand() % 10000;
        aryMerge[x] = aryBubble[x];
        aryRadix[x] = aryBubble[x];
    }
        
    // Bubble Sort and count the swaps
    int numSwapsBubble = 0;

    // Merge Sort and count the moves
    int numMovesMerge = 0;
    
    // Radix Sort and count the moves
    int numMovesRadix = 0;
    
    
    // #################################################################//
    //                                                                  //
    //                              BUBBLE SORT                         //
    //                                                                  //
    // #################################################################//
    
    string bubbleSortTitle = "Bubble Sort";
    printStyledTitle(bubbleSortTitle);
    
    cout << "BEFORE MERGE: The first 10 values: ";
    
    for (int i = 0; i < 10; i++) {
        cout << aryBubble[i] << " ";
    }
    
    cout << endl;

    bubbleSort(aryBubble, arraySize, numSwapsBubble);

    cout << "Bubble sort had " << numSwapsBubble << " swaps." << endl;

    cout << "The first 10 values: ";
    for (int i = 0; i < 10; i++) {
        cout << aryBubble[i] << " ";
    }
    
    cout << endl;

    cout << "The last 10 values: ";
    for (int i = arraySize - 10; i < arraySize; i++) {
        cout << aryBubble[i] << " ";
    }

    cout << endl;
    cout << endl;
    
    // #################################################################//
    //                                                                  //
    //                              MERGE SORT                          //
    //                                                                  //
    // #################################################################//
    
    string mergeSortTitle = "Merge Sort";
    printStyledTitle(mergeSortTitle);
    
    cout << "BEFORE MERGE: The first 10 values: ";
    for (int i = 0; i < 10; i++) {
        cout << aryMerge[i] << " ";
    }
    
    cout << endl;
    
    mergeSort(aryMerge, 0, arraySize-1, numMovesMerge);

    cout << "Merge sort had " << numMovesMerge << " moves." << endl;
    
    cout << "The first 10 values: ";
    for (int i = 0; i < 10; i++) {
        cout << aryMerge[i] << " ";
    }

    cout << endl;

    cout << "The last 10 values: ";
    for (int i = arraySize - 10; i < arraySize; i++) {
        cout << aryMerge[i] << " ";
    }

    cout << endl;
    cout << endl;

    
    // #################################################################//
    //                                                                  //
    //                              RADIX SORT                          //
    //                                                                  //
    // #################################################################//
    
    string radixSortTitle = "Radix Sort";
    printStyledTitle(radixSortTitle);
    
    cout << "BEFORE MERGE: The first 10 values: ";
    for (int i = 0; i < 10; i++) {
        cout << aryRadix[i] << " ";
    }
    
    cout << endl;
    
    radixSort<int>(aryRadix, arraySize, 4, numMovesRadix);

    cout << "Radix sort had " << numMovesRadix << " moves." << endl;
    
    cout << "The first 10 values: ";
    for (int i = 0; i < 10; i++) {
        cout << aryRadix[i] << " ";
    }

    cout << endl;

    cout << "The last 10 values: ";
    for (int i = arraySize - 10; i < arraySize; i++) {
        cout << aryRadix[i] << " ";
    }

    cout << endl;
    
    return 0;
}
