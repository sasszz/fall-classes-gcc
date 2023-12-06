//
//  main.cpp
//  ec
//
//  Created by Lucie Chevreuil on 12/6/23.
//

#include "BubbleSort.h"
#include "MergeSort.h"
#include "RadixSort.h"
#include "ArrayMaxHeap.h"

#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>

void customShuffle(int arr[], int size, mt19937 &gen)
{
    for (int i = size - 1; i > 0; --i) {
        uniform_int_distribution<int> distribution(0, i);
        int j = distribution(gen);

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


int main()
{
    random_device rd;
    mt19937 gen(rd());
    
    const int arraySize = 10000;
    int array[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        array[i] = rand() % 1000;
    }
    
    cout << "BEFORE BUBBLE SORT" << endl;
    cout << "First value before sorting: " << array[0] << endl;
    cout << "Last value before sorting: " << array[arraySize - 1] << endl;
    bubbleSort(array, arraySize);
    cout << "----------------------------------" << endl;
    cout << "AFTER BUBBLE SORT" << endl;
    cout << "First value after bubble sort: " << array[0] << endl;
    cout << "Last value after bubble sort: " << array[arraySize - 1] << endl;
    
    cout << endl;
    cout << "SHUFFLING ARRAY FOR NEXT SORT...." << endl;
    cout << endl;
    customShuffle(array, arraySize, gen);
    this_thread::sleep_for(chrono::seconds(1));

    cout << "BEFORE MERGE SORT" << endl;
    cout << "First value after merge sort: " << array[0] << endl;
    cout << "Last value after merge sort: " << array[arraySize - 1] << endl;
    mergeSort(array, 0, arraySize - 1);
    cout << "----------------------------------" << endl;
    cout << "AFTER MERGE SORT" << endl;
    cout << "First value after merge sort: " << array[0] << endl;
    cout << "Last value after merge sort: " << array[arraySize - 1] << endl;

    cout << endl;
    cout << "SHUFFLING ARRAY FOR NEXT SORT...." << endl;
    cout << endl;
    customShuffle(array, arraySize, gen);
    this_thread::sleep_for(chrono::seconds(1));
    
    cout << "BEFORE RADIX SORT" << endl;
    cout << "First value after merge sort: " << array[0] << endl;
    cout << "Last value after merge sort: " << array[arraySize - 1] << endl;
    radixSort(array, arraySize);
    cout << "----------------------------------" << endl;
    cout << "AFTER RADIX SORT" << endl;
    cout << "First value after radix sort: " << array[0] << endl;
    cout << "Last value after radix sort: " << array[arraySize - 1] << endl;

    return 0;
}

