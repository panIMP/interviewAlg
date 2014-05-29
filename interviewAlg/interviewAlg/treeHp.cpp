#include "treeHp.h"
#include <iostream>


// Create a binary search tree
pBinaryTreeNode 
createBinarySearchTree(valueType array[], int nodeNum)
{
	pBinaryTreeNode root = new binaryTreeNode;
	root->m_nValue = array[0];
	root->m_pRight = root->m_pLeft = nullptr;

	for (int i = 1; i < nodeNum; ++i)
		insertIntoBinarySearchTree(array[i], root);

	return root;
}


// Insert a node into binary search tree
pBinaryTreeNode
insertIntoBinarySearchTree(valueType value, pBinaryTreeNode pNode)
{
	if (pNode == nullptr)
	{
		// Make an empty tree
		pNode = new binaryTreeNode;
		if (pNode == nullptr)
			return nullptr;

		pNode->m_nValue = value;
		pNode->m_pRight = pNode->m_pLeft = nullptr;
	}
	
	else
	{	
		if (pNode->m_nValue > value)
			insertIntoBinarySearchTree(value, pNode->m_pRight);

		else if (pNode->m_nValue < value)
			insertIntoBinarySearchTree(value, pNode->m_pLeft);
	}

	return pNode;
}


// Print all the tree node in certain traveral order
void
printBinaryTree(pBinaryTreeNode pNode, traverSalOrder order)
{
	if (pNode == nullptr)
		return;

	switch (order)
	{
	case PRE_ORDER:
		printBinaryTreePreorder(pNode);
		break;
	case IN_ORDER:
		printBinaryTreeInorder(pNode);
		break;
	case POST_ORDER:
		printBinaryTreePostorder(pNode);
		break;
	case BREADTH_FIRST_ORDER:
		printBinaryTreeBreadthFirstOrder(pNode);
		break;
	default:
		std::cout << "Not a valid order type!" << std::endl;
		break;
	}
}


// Print in preorder
void
printBinaryTreePreorder(pBinaryTreeNode pNode)
{
	if (pNode == nullptr)
		return;

	std::cout << pNode->m_nValue << " ";

	if (pNode->m_pLeft != nullptr)
		printBinaryTreePreorder(pNode->m_pLeft);

	if (pNode->m_pRight != nullptr)
		printBinaryTreePreorder(pNode->m_pRight);
}


// Print in inorder
void
printBinaryTreeInorder(pBinaryTreeNode pNode)
{
	if (pNode == nullptr)
		return;

	if (pNode->m_pLeft != nullptr)
		printBinaryTreeInorder(pNode->m_pLeft);

	std::cout << pNode->m_nValue << " ";

	if (pNode->m_pRight != nullptr)
		printBinaryTreeInorder(pNode->m_pRight);
}


// Print in postorder
void
printBinaryTreePostorder(pBinaryTreeNode pNode)
{
	if (pNode == nullptr)
		return;

	if (pNode->m_pLeft != nullptr)
		printBinaryTreePostorder(pNode->m_pLeft);
	
	if (pNode->m_pRight != nullptr)
		printBinaryTreePostorder(pNode->m_pRight);
	
	std::cout << pNode->m_nValue << " ";
}


// Print in breadth-first order
void
printBinaryTreeBreadthFirstOrder(pBinaryTreeNode pNode)
{
	if (pNode == nullptr)
		return;

	if (pNode->m_pLeft != nullptr)
		std::cout << pNode->m_pLeft->m_nValue << " ";

	if (pNode->m_pRight != nullptr)
		std::cout << pNode->m_pRight->m_nValue << " ";

}


// Find the node through the value(Condition: no duplicate value in the tree)
pBinaryTreeNode
findByValue(pBinaryTreeNode pNode, valueType value)
{
	if (pNode == nullptr)
		return nullptr;

	if (pNode->m_nValue != value)
	{
		findByValue(pNode->m_pLeft, value);
		findByValue(pNode->m_pRight, value);
	}

	return pNode;
}



// Reconstruct the tree through preorder traversal and inorder traversal
pBinaryTreeNode
reconstructTree(valueType* preOrder, valueType* inOrder, int nodeNum)
{
	if (nodeNum <= 0)
		return nullptr;

	pBinaryTreeNode father = new binaryTreeNode;
	pBinaryTreeNode leftSon = new binaryTreeNode;
	pBinaryTreeNode rightSon = new binaryTreeNode;

	int rootValue = father->m_nValue = *preOrder;
	int i;
	for (i = 0; i < nodeNum; ++i)
	{
		if (inOrder[i] == rootValue)
			break;
	}
	int leftSonNum = i;
	int rightSonNum = nodeNum - i - 1;

	father->m_pLeft = leftSon;
	leftSon->m_nValue = *(preOrder + 1);
	father->m_pRight = rightSon;
	rightSon->m_nValue = *(preOrder + leftSonNum);

	reconstructTree(preOrder + 1, inOrder, leftSonNum);
	reconstructTree(preOrder + leftSonNum, inOrder + leftSonNum + 1, rightSonNum);

	return father;
}