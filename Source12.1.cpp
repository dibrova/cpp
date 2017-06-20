/*12.1. ƒан массив целых чисел. ¬оспользовавшись указате-
л€ми, помен€йте местами элементы массива с четными и
нечетными индексами (т.е. те элементы массива, которые
сто€т на четных местах, помен€йте с элементами, которые
сто€т на нечетных местах).*/

#include <iostream>
#include <iomanip>
using namespace std;

void Swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void show(int *ptr_arr, unsigned int size, int field)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cout << setw(field) << *(ptr_arr+i);
	}

	cout << endl;
}


void main_12_1()
{
	srand((unsigned int)time(nullptr));
	const unsigned int size = 20;

	int a[size];
	int *ptra = a;
	for (int i = 0; i < size; i++)
	{
		*(ptra + i) = rand() % size + 1;
	}
	show(a, size, 3);
	
	for (int i = 0; i < size - 1; i++)
	{
		Swap(ptra + i, ptra + i++);
	}
	
	cout << endl;
	show(a, size, 3);
}
