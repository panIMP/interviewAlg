#include "fibonacci.h"
#include "listHp.h"
#include "stringHp.h"
#include "userTypes.h"
#include "findInPartiallySortedMatrix.h"
#include "replaceBlank.h"
#include "mergeSortedArray.h"
#include "treeHp.h"


int
main()
{
	valueType a[12] = { 5, 2, 3, 1, 10, 6, 9, 7, 8, 4, 11, 0};

	pBinaryTreeNode root = createBinarySearchTree(a, 12);

	printBinaryTreePostorderRecursive(root);

	std::cout << "\n";

	printBinaryTreePostorderStack(root);

	std::cout << "\n";

	system("pause");

	return 0;
}