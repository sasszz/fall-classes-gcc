//
//  recursion.cpp
//  lab1
//
//  Created by Lucie Chevreuil on 9/14/23.
//
//  IMPLEMENTATION FILE
//  PSEUDOCODE AT BOTTOM

#include <stdio.h>
#include <iostream>
#include "recursion.h"
using namespace std;

// Recursive Factorial Function
unsigned long long recursiveFactorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * recursiveFactorial(n - 1);
    }
}

// Towers of Hanoi Function
void towersOfHanoi(int count, char source, char destination, char spare) {
    if (count == 1) {
        cout << "Move top disk from pole " << source << " to pole " << destination << endl;
    }
    else {
        towersOfHanoi(count - 1, source, spare, destination);
        cout << "Move top disk from pole " << source << " to pole " << destination << endl;
        towersOfHanoi(count - 1, spare, destination, source);
    }
}

// Recursive Summation Function
int recursiveSummation(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + recursiveSummation(n - 1);
    }
}


// PSEUDOCODE
// Recursive Factorial Function ############################################################
// This function calculates the factorial of a number `n` (product of all positive integers up to `n`).
// - If `n` is 0 or 1, it returns 1.
// - For larger `n`, it multiplies `n` by the factorial of `n-1` obtained through recursion.

// Towers of Hanoi Function ############################################################
// This function solves the Towers of Hanoi puzzle by moving disks between three pegs.
// - For one disk (`count` is 1), it directly moves it from the `source` peg to the `destination` peg.
// - For more disks (`count` > 1), it uses recursion to:
//   - Move `count-1` disks from `source` to `spare`.
//   - Move the largest disk from `source` to `destination`.
//   - Move `count-1` disks from `spare` to `destination`.

// Recursive Summation Function ############################################################
// This function calculates the sum of positive integers from 1 to `n`.
// - If `n` is 0, it returns 0.
// - For larger `n`, it adds `n` to the sum of positive integers from 1 to `n-1` through recursion.
