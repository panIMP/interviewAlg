#pragma once

typedef int valueType;

struct binaryTreeNode
{
	valueType m_nValue;
	binaryTreeNode* m_pLeft;
	binaryTreeNode* m_pRight;
};

typedef binaryTreeNode* pBinaryTreeNode;


enum traverSalOrder
{
	PRE_ORDER = 1,
	IN_ORDER,
	POST_ORDER,
	BREADTH_FIRST_ORDER,
};


// Create a binary search tree
pBinaryTreeNode
createBinarySearchTree(valueType array[], int nodeNum);


// Insert a node into binary search tree
pBinaryTreeNode
insertIntoBinarySearchTree(valueType value, pBinaryTreeNode pNode);


// Print all the tree node in certain traveral order
void
printBinaryTree(pBinaryTreeNode pNode, traverSalOrder order);


// Print in preorder
void
printBinaryTreePreorder(pBinaryTreeNode pNode);


// Print in inorder
void
printBinaryTreeInorder(pBinaryTreeNode pNode);


// Print in postorder
void
printBinaryTreePostorder(pBinaryTreeNode pNode);


// Print in breadth-first order
void
printBinaryTreeBreadthFirstOrder(pBinaryTreeNode pNode);


// Find the node through the value(Condition: no duplicate value in the tree)
pBinaryTreeNode
findByValue(pBinaryTreeNode pNode, valueType value);


// Reconstruct the tree through preorder traversal and inorder traversal
pBinaryTreeNode
reconstructTree(valueType* preOrder, valueType* inOrder, int nodeNum);

