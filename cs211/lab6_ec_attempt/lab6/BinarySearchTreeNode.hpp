//
//  BinarySearchTreeNode.hpp
//  CSIS4
//
//  Created by Tony Biehl on 11/14/23.
//

#ifndef BinarySearchTreeNode_hpp
#define BinarySearchTreeNode_hpp

#include "TreeNode.h"
#include "BinaryTreeInterface.h"

const int MAX_NODES = 500;

template<class ItemType>
class BinarySearchTreeNode : public BinaryTreeInterface<ItemType>
{
private:
    TreeNode<ItemType> tree[MAX_NODES];
    int root;
    int free;
protected:
    //------------------------------------------------------------
    // Protected Utility Methods Section:
    // Recursive helper methods for the public methods.
    //------------------------------------------------------------
    
    int getHeightHelper(int subTreePtr) const;
    int getNumberOfNodesHelper(int subTreePtr) const;
    
    //------------------------------------------------------------
    // Recursively finds where the given node should be placed and
    // inserts it in a leaf at that point.
    auto placeNode(int subTreePtr, int newNode);
    
    // Removes the given target value from the tree while maintaining a
    // binary search tree.
    int removeValue(int subTreePtr, const ItemType target,
                                      bool& success) ;
    
    // Removes a given node from a tree while maintaining a
    // binary search tree.
    auto removeNode(int nodePtr);
    
    // Removes the leftmost node in the left subtree of the node
    // pointed to by nodePtr.
    // Sets inorderSuccessor to the value in this node.
    // Returns a pointer to the revised subtree.
    auto removeLeftmostNode(int subTreePtr,
                                             ItemType& inorderSuccessor);
    
    // Recursively searches for target value in the tree by using a
    // preorder traversal.
    auto findNode(int treePtr, const ItemType& target,
                                   bool& success) const;
    
    // Recursively deletes all nodes from the tree.
    void destroyTree(int subTreePtr);
    
    // Recursive traversal helper methods:
    void preorder(void visit(ItemType&), int treePtr) const;
    void inorder(void visit(ItemType&), int treePtr) const;
    void postorder(void visit(ItemType&), int treePtr) const;
    int allocateNode(const ItemType& item);
    void deallocateNode(int nodePtr);
    
    int readTreeHelper(ifstream& infile, int n);
    void writeTreeHelper(ofstream& outfile, int subTreePtr);
    
    int readTreeHelperEC(const vector<ItemType>& sortedItems, int start, int end);
    
public:
    //------------------------------------------------------------
    // Constructor and Destructor Section.
    //------------------------------------------------------------
    BinarySearchTreeNode();
    BinarySearchTreeNode(const ItemType& rootItem);
    
    //------------------------------------------------------------
    // Public BinaryTreeInterface Methods Section.
    //------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const noexcept(false);
    void setRootData(const ItemType& newData) const noexcept(false);
    bool add(const ItemType& newData); // Adds a node
    bool remove(const ItemType& data); // Removes a node
    void clear();
    ItemType getEntry(const ItemType& anEntry) const noexcept(false);
    bool contains(const ItemType& anEntry) const;
    
    //------------------------------------------------------------
    // Public Traversals Section.
    //------------------------------------------------------------
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;
    
    void readTree(string filename);
    void writeTree(string filename);
    
    void readTreeEC(string filename);
};
#include "BinarySearchTreeNode.cpp"
#endif /* BinarySearchTreeNode_hpp */
