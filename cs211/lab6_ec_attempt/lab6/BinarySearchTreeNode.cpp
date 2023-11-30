//
//  BinarySearchTreeNode.cpp
//  CSIS4
//
//  Created by Tony Biehl on 11/14/23.
//
#ifndef BinarySearchTreeNode_cpp
#define BinarySearchTreeNode_cpp
#include "BinarySearchTreeNode.hpp"
#include "PrecondViolatedExcep.h"

using namespace std;

//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
template<class ItemType>
BinarySearchTreeNode<ItemType>::BinarySearchTreeNode(){
    root = NIL_NODE;
    free = 0;
    for (int i = 0; i < MAX_NODES; i++){
        tree[i].setLeft(NIL_NODE);
        if (i == MAX_NODES-1)
            tree[i].setRight(NIL_NODE);
        else
            tree[i].setRight(i+1);
    }
}
template<class ItemType>
BinarySearchTreeNode<ItemType>::BinarySearchTreeNode(const ItemType& rootItem){
    BinarySearchTreeNode();
    add(rootItem);
}

//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
template<class ItemType>
int BinarySearchTreeNode<ItemType>::getHeightHelper(int subTreePtr) const{
    if (subTreePtr == NIL_NODE)
       return 0;
    else
       return 1 + max(getHeightHelper(tree[subTreePtr].getLeft()),
                      getHeightHelper(tree[subTreePtr].getRight()));
}
template<class ItemType>
int BinarySearchTreeNode<ItemType>::getNumberOfNodesHelper(int subTreePtr) const{
    if (subTreePtr == NIL_NODE)
       return 0;
    else
       return 1 + getNumberOfNodesHelper(tree[subTreePtr].getLeft())
                + getNumberOfNodesHelper(tree[subTreePtr].getRight());
}
// Removes the given target value from the tree while maintaining a
// binary search tree.
template<class ItemType>
int BinarySearchTreeNode<ItemType>::removeValue(int subTreePtr, const ItemType target, bool& success) {
    if (subTreePtr == NIL_NODE)
    {
       // Not found here
       success = false;
       return subTreePtr;
    }
    if (tree[subTreePtr].getItem() == target)
    {
       // Item is in the root of some subtree
       subTreePtr = removeNode(subTreePtr);
       success = true;
       return subTreePtr;
    }
    else
    {
       if (tree[subTreePtr].getItem() > target)
       {
          // Search the left subtree
           tree[subTreePtr].setLeft(removeValue(tree[subTreePtr].getLeft(), target, success));
       }
       else
       {
          // Search the right subtree
           tree[subTreePtr].setRight(removeValue(tree[subTreePtr].getRight(), target, success));
       }
       return subTreePtr;
    }  // end if
}

// Removes a given node from a tree while maintaining a
// binary search tree.
template<class ItemType>
auto BinarySearchTreeNode<ItemType>::removeNode(int nodePtr){
    // Case 1) Node is a leaf - it is deleted
    // Case 2) Node has one child - parent adopts child
    // Case 3) Node has two children:
    //               Traditional implementation: Find successor node.
    //               Alternate implementation: Find successor value and replace node's value;
    //                  alternate does not need pass-by-reference
    int temp;
    if (tree[nodePtr].isLeaf())
    {
       //nodePtr.reset();
        deallocateNode(nodePtr);
       return nodePtr; // delete and return nullptr
    }
    else if (tree[nodePtr].getLeft() == NIL_NODE)  // Has rightChild only
    {
        temp = tree[nodePtr].getRight();
        deallocateNode( nodePtr);
       return temp;
    }
    else if (tree[nodePtr].getRight() == NIL_NODE) // Has left child only
    {
        temp = tree[nodePtr].getLeft();
        deallocateNode( nodePtr);
       return temp;
    }
    else                                             // Has two children
    {
        // Traditional way to remove a value in a node with two children
        ItemType newNodeValue;
        tree[nodePtr].setRight(removeLeftmostNode(tree[nodePtr].getRight(), newNodeValue));
        tree[nodePtr].setItem(newNodeValue);
        return nodePtr;
    }
}
template<class ItemType>
auto BinarySearchTreeNode<ItemType>::removeLeftmostNode(int subTreePtr,
                        ItemType& inorderSuccessor){
    if (tree[subTreePtr].getLeft() == NIL_NODE)
    {
       inorderSuccessor = tree[subTreePtr].getItem();
       return removeNode(subTreePtr);
    }
    else
    {
        tree[subTreePtr].setLeft(removeLeftmostNode(tree[subTreePtr].getLeft(), inorderSuccessor));
       return subTreePtr;
    }  // end if
}
// Recursively searches for target value in the tree by using a
// preorder traversal.
template<class ItemType>
auto BinarySearchTreeNode<ItemType>::findNode(int treePtr, const ItemType& target, bool& success) const{
    if (treePtr == NIL_NODE) // not found here
       return treePtr;
    
    if (tree[treePtr].getItem() == target) // found it
    {
       success = true;
       return treePtr;
    }
    else
    {
        int targetNodePtr = findNode(tree[treePtr].getLeft(), target, success);
        if (!success) // no need to search right subTree
        {
            targetNodePtr = findNode(tree[treePtr].getRight(), target, success);
        }  // end if
        
        return targetNodePtr;
    }
}

// Recursively deletes all nodes from the tree.
template<class ItemType>
    void BinarySearchTreeNode<ItemType>::destroyTree(int subTreePtr){
        if (subTreePtr != NIL_NODE)
        {
           destroyTree(tree[subTreePtr].getLeft());
           destroyTree(tree[subTreePtr].getRight());
           //subTreePtr.reset(); // decrement reference count to node
            deallocateNode(subTreePtr);
        }  // end if
    }

// Recursive traversal helper methods:
template<class ItemType>
void BinarySearchTreeNode<ItemType>::preorder(void visit(ItemType&), int treePtr) const{
    if (treePtr != NIL_NODE)
    {
       ItemType theItem = tree[treePtr].getItem();
       visit(theItem);
 //      visit(treePtr->getItem());
       preorder(visit, tree[treePtr].getLeft());
       preorder(visit, tree[treePtr].getRight());
    }  // end if
}
template<class ItemType>
void BinarySearchTreeNode<ItemType>::inorder(void visit(ItemType&), int treePtr) const{
    if (treePtr != NIL_NODE)
    {
        inorder(visit, tree[treePtr].getLeft());
        ItemType theItem = tree[treePtr].getItem();
        visit(theItem);
  //      visit(treePtr->getItem());
        inorder(visit, tree[treePtr].getRight());
    }  // end if
}
template<class ItemType>
void BinarySearchTreeNode<ItemType>::postorder(void visit(ItemType&), int treePtr) const{
    if (treePtr != NIL_NODE)
    {
        postorder(visit, tree[treePtr].getLeft());
        postorder(visit, tree[treePtr].getRight());
        ItemType theItem = tree[treePtr].getItem();
        visit(theItem);
  //      visit(treePtr->getItem());
    }  // end if
}
template<class ItemType>
int BinarySearchTreeNode<ItemType>::allocateNode(const ItemType& item){
    int newNodePtr = free;
    if (free == NIL_NODE)
        return false;
    free = tree[newNodePtr].getRight();
    tree[newNodePtr].setItem(item);
    tree[newNodePtr].setLeft(NIL_NODE);
    tree[newNodePtr].setRight(NIL_NODE);
    return newNodePtr;
}
template<class ItemType>
void BinarySearchTreeNode<ItemType>::deallocateNode(int nodePtr){
    if (nodePtr == NIL_NODE)
        return;
    tree[nodePtr].setRight(free);
    tree[nodePtr].setLeft(NIL_NODE);
    free = nodePtr;
}
//------------------------------------------------------------
// Public BinaryTreeInterface Methods Section.
//------------------------------------------------------------
template<class ItemType>
bool BinarySearchTreeNode<ItemType>::isEmpty() const{
    return root == NIL_NODE;
}
template<class ItemType>
int BinarySearchTreeNode<ItemType>::getHeight() const{
    return getHeightHelper(root);
}
template<class ItemType>
int BinarySearchTreeNode<ItemType>::getNumberOfNodes() const{
    return getNumberOfNodesHelper(root);
}
//------------------------------------------------------------
// Recursively finds where the given node should be placed and
// inserts it in a leaf at that point.
template<class ItemType>
auto BinarySearchTreeNode<ItemType>::placeNode(int subTreePtr, int newNodePtr){
    if (subTreePtr == NIL_NODE)
       return newNodePtr;
    else
    {
        if (tree[subTreePtr].getItem() > tree[newNodePtr].getItem())
            tree[subTreePtr].setLeft(placeNode(tree[subTreePtr].getLeft(), newNodePtr));
        else
            tree[subTreePtr].setRight(placeNode(tree[subTreePtr].getRight(), newNodePtr));
        
        return subTreePtr;
    }
}


template<class ItemType>
ItemType BinarySearchTreeNode<ItemType>::getRootData() const noexcept(false){
    if (isEmpty())
       throw PrecondViolatedExcep("getRootData() called with empty tree."); 
    return tree[root].getItem();
}
template<class ItemType>
void BinarySearchTreeNode<ItemType>::setRootData(const ItemType& newData) const noexcept(false){
    // dummy function
    throw PrecondViolatedExcep("Cannot change root value in a BST!");
}
template<class ItemType>
bool BinarySearchTreeNode<ItemType>::add(const ItemType& newData) // Adds a node
{
    int newNodePtr = allocateNode(newData);
    root = placeNode(root, newNodePtr);
    return true;
}
template<class ItemType>
bool BinarySearchTreeNode<ItemType>::remove(const ItemType& target){ // Removes a node
    bool isSuccessful = false;
    // call may change isSuccessful
    root = removeValue(root, target, isSuccessful);
    return isSuccessful;
}
template<class ItemType>
void BinarySearchTreeNode<ItemType>::clear(){
    destroyTree(root);
}
template<class ItemType>
ItemType BinarySearchTreeNode<ItemType>::getEntry(const ItemType& anEntry) const noexcept(false){
    bool success;
    int nodeWithEntry = findNode(root, anEntry, success);
    if (nodeWithEntry == NIL_NODE)
       throw PrecondViolatedExcep("Entry not found in tree.");
    else
       return tree[nodeWithEntry].getItem();
}
template<class ItemType>
bool BinarySearchTreeNode<ItemType>::contains(const ItemType& anEntry) const{
    bool success;
    return (findNode(root, anEntry, success) == NIL_NODE);
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
template<class ItemType>
void BinarySearchTreeNode<ItemType>::preorderTraverse(void visit(ItemType&)) const{
    preorder(visit, root);
}
template<class ItemType>
void BinarySearchTreeNode<ItemType>::inorderTraverse(void visit(ItemType&)) const{
    inorder(visit, root);
}
template<class ItemType>
void BinarySearchTreeNode<ItemType>::postorderTraverse(void visit(ItemType&)) const{
    postorder(visit, root);
}
#endif
