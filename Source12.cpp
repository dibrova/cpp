/*12.1. Дан массив целых чисел. Воспользовавшись указате-
лями, поменяйте местами элементы массива с четными и
нечетными индексами (т.е. те элементы массива, которые
стоят на четных местах, поменяйте с элементами, которые
стоят на нечетных местах).
12.2. Даны два массива, упорядоченных по возрастанию:
А[n] и B[m]. Сформируйте массив C[n+m], состоящий из
элементов массивов А и В, упорядоченный по возрастанию.*/


#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

/*
void init(int array[], unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		array[i] = i + 1;
	}
}

template <typename T>
void show(T array[], unsigned int size, int field)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cout << setw(field) << array[i];
	}

	cout << endl;
}

void Swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void main_12()
{
	srand((unsigned int)time(nullptr));
	const unsigned int size = 20;

	int a[size];
	int *ptra;

	init(a, size);
	show(a, size, 3);

	ptra = a;

	for (int i = 0; i < size - 1; i++)
	{
		Swap(ptra+i,ptra+i++);
		show(a, size, 3);
	}
	cout << endl;


	const int sizeA = 4;
	const int sizeB = 7;
	const int sizeC = sizeA + sizeB;
	int arrA[sizeA] = {1,3,8,10};
	int arrB[sizeB] = {2,4,6,7,9,11,13};
	int arrC[sizeC] = { 0 };
	int *ptrA, *ptrB, *ptrC;
	ptrA = arrA;
	ptrB = arrB;
	ptrC = arrC;
	int sA = sizeA;
	int sB = sizeB;
	int sC = sizeC;

//	init(arrA, sizeA);
//	init(arrB, sizeB);
//	init(arrC, sizeC);

	show(arrA, sizeA, 3);
	show(arrB, sizeB, 3);
	
	while (sA != 0 && sB != 0)
	{
		if (*ptrA < *ptrB)
		{
			cout << ptrC << endl;
			*ptrC++ = *ptrA++;
			sA--;
			cout << ptrC << endl;
		}
		else if (*ptrA > *ptrB)
		{
			cout << ptrC << endl;
			*ptrC++ = *ptrB++;
			sB--;
			cout << ptrC << endl;
		}
		else
		{
			*ptrC++ = *ptrA++;
			*ptrC++ = *ptrB++;
			sA--;
			sB--;
		}
	}
	while (sA)
	{
		*ptrC++ = *ptrA++;
		sA--;
	}
	while (sB)
	{
		*ptrC++ = *ptrB++;
		sB--;
	}
	show(arrC, sizeC, 3);

}
*/