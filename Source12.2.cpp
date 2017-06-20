/*12.2. Даны два массива, упорядоченных по возрастанию:
А[n] и B[m]. Сформируйте массив C[n+m], состоящий из
элементов массивов А и В, упорядоченный по возрастанию.*/


#include <iostream>
#include <iomanip>
using namespace std;

void Show(int *ptr_arr, unsigned int size, int field)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cout << setw(field) << *(ptr_arr + i);
	}

	cout << endl;
}


void main_12_2()
{
	const int sizeA = 15;
	const int sizeB = 11;
	const int sizeC = sizeA + sizeB;
	int arrA[sizeA], arrB[sizeB], arrC[sizeC];
	int *ptrA, *ptrB, *ptrC;
	ptrA = arrA;
	ptrB = arrB;
	ptrC = arrC;
	int a = sizeA;
	int b = sizeB;
	int c = sizeC;

	for (int i = 0; i < sizeA; i++)
	{
		*(ptrA + i) = i * 2 + 1;
	}
	for (int i = 0; i < sizeB; i++)
	{
		*(ptrB + i) = i * 3 + 2;
	}
	
	Show(arrA, sizeA, 3);
	Show(arrB, sizeB, 3);

	while (a != 0 && b != 0)
	{
		if (*ptrA < *ptrB)
		{
			*ptrC++ = *ptrA++;
			a--;
		}
		else if (*ptrA > *ptrB)
		{
			*ptrC++ = *ptrB++;
			b--;
		}
		else
		{
			*ptrC++ = *ptrA++;
			*ptrC++ = *ptrB++;
			a--;
			b--;
		}
	}
	
	while (a)
	{
		*ptrC++ = *ptrA++;
		a--;
	}
	
	while (b)
	{
		*ptrC++ = *ptrB++;
		b--;
	}

	Show(arrC, sizeC, 3);

}