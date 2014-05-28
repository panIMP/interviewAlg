#include "fibonacci.h"
#include "findKth2Tail.h"
#include "listHp.h"
#include "str2Num.h"
#include "userTypes.h"
#include "findInPartiallySortedMatrix.h"
#include "replaceBlank.h"
#include "mergeSortedArray.h"


using namespace std;



int
main()
{
	int a[50] = { 1, 4, 6, 9, 10, 12, 17};
	int b[8] = { 8, 11, 12, 14, 16, 17, 19, 21};
	
	mergeSortedArray(a, 7, b, 8);
	int value;
	for (int i = 0; i < 15 && (value = a[i]) != '\0'; ++i)
		cout << value << endl;


	system("pause");

	return 0;
}