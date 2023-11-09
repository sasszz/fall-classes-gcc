//
//  main.cpp
//  inclassprogram
//
//  Created by Lucie Chevreuil on 11/9/23.
//

#include <iostream>
#include "ArrayStack.hpp"


using namespace std;


template <class ItemType>
void shuffle(ArrayStack<ItemType>& stack1, ArrayStack<ItemType>& stack2, ArrayStack<ItemType>& resultStack) {
    while (!stack1.isEmpty() || !stack2.isEmpty()) {
        if (!stack1.isEmpty()) {
            resultStack.push(stack1.peek());
            stack1.pop();
        }
        if (!stack2.isEmpty()) {
            resultStack.push(stack2.peek());
            stack2.pop();
        }
    }
}

int main() {
    ArrayStack<int> stack1;
    ArrayStack<int> stack2;
    ArrayStack<int> resultStack;

    // Push some elements into the stacks
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack2.push(4);
    stack2.push(5);
    stack2.push(6);
    stack2.push(7);
    stack2.push(8);
    stack2.push(9);
    stack2.push(10);

    // Shuffle the elements into the result stack
    shuffle(stack1, stack2, resultStack);

    // Display the result stack
    while (!resultStack.isEmpty()) {
        cout << resultStack.peek() << " ";
        resultStack.pop();
    }

    return 0;
}
