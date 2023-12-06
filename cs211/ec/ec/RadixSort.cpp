//
//  RadixSort.cpp
//  ec
//
//  Created by Lucie Chevreuil on 12/6/23.
//

#include "RadixSort.h"

void countingSort(int arr[], int size, int exp);

void radixSort(int arr[], int size)
{
    int maxNum = arr[0];
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }

    for (int exp = 1; maxNum / exp > 0; exp *= 10)
    {
        countingSort(arr, size, exp);
    }
}

void countingSort(int arr[], int size, int exp)
{
    const int RADIX = 10;
    int output[size];
    int count[RADIX] = {0};

    for (int i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % RADIX]++;
    }

    for (int i = 1; i < RADIX; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % RADIX] - 1] = arr[i];
        count[(arr[i] / exp) % RADIX]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}
