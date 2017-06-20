/*
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void init(int array[], unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		array[i] = rand() % 100;
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

void BubbleSort(int array[], unsigned int size)
{
	int count = 0;
	bool flag = true;
	for (unsigned int i = 0; i < size && flag; i++)
	{
		count++;
		flag = false;
		for (unsigned int j = size - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
				flag = true;
			}
		}
	}

	cout << "count = " << count << endl;
}

void SelectedSort(int array[], unsigned int size)
{
	int index;
	for (unsigned int i = 0; i < size - 1; i++)
	{
		index = i;
		for (unsigned int j = i + 1; j < size; j++)
		{
			if (array[j] < array[index])
			{
				index = j;
			}
		}

		if (i != index)
		{
			swap(array[i], array[index]);
		}
	}
}

void InsertedSort(int a[], char c[], unsigned int size)
{
	int tempN;
	char tempC;
	for (int i = 1; i < size; i++)
	{
		tempN = a[i];
		tempC = c[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] <= tempN)
			{
				break;
			}

			a[j + 1] = a[j];
			a[j] = tempN;

			c[j + 1] = c[j];
			c[j] = tempC;
		}
	}
}


void main_10()
{
	srand((unsigned int)time(nullptr));
	const unsigned int size = 10;
	int a[size] = { 5,   2,   8,   3,   2,   2,   9,   0,   1,   4 };
	char b[size] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	// = { 0,  5, 24, 34, 41, 45, 58, 27, 61, 62, 64, 67, 69, 78, 81 };
	// init(a, size);
	show(a, size, 2);
	show(b, size, 2);
	cout << endl;
	// BubbleSort(a, size);
	 SelectedSort(a, size);
	//InsertedSort(a, b, size);
	show(a, size, 2);
	show(b, size, 2);
}*/