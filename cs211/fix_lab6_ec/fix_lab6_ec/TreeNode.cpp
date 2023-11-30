//
//  TreeNode.cpp
//  y
//
//  Created by Tony Biehl on 4/30/20.
//  Copyright © 2020 Tony Biehl. All rights reserved.
//

#ifndef TREE_NODE_CPP
#define TREE_NODE_CPP

#include "TreeNode.h"

template<class ItemType>
TreeNode<ItemType>::TreeNode(){
    leftChild = rightChild = NIL_NODE;
}

template<class ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& nodeItem, int left, int right){
    leftChild = left;
    rightChild = right;
    item = nodeItem;
}

// Declarations of the methods setItem, getItem, setLeft, getLeft,
// setRight, and getRight are here.
template<class ItemType>
void TreeNode<ItemType>::setItem(const ItemType& anItem) {
    item = anItem;
}

template<class ItemType>
ItemType TreeNode<ItemType>::getItem() const{
    return item;
}

template<class ItemType>
void TreeNode<ItemType>::setLeft(int left){
    leftChild = left;
}

template<class ItemType>
int TreeNode<ItemType>::getLeft() const{
    return leftChild;
}

template<class ItemType>
void TreeNode<ItemType>::setRight(int right){
    rightChild = right;
}

template<class ItemType>
int TreeNode<ItemType>::getRight() const{
    return rightChild;
}

template<class ItemType>
bool TreeNode<ItemType>::isLeaf() {
    return (leftChild == NIL_NODE && rightChild == NIL_NODE);
}

#endif
