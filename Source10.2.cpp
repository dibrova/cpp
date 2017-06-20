/*10.2. Дан массив случайных чисел в диапазоне от –20 до
+20. Необходимо найти позиции крайних отрицательных
элементов (самого левого отрицательного элемента и са-
мого правого отрицательного элемента) и отсортировать
элементы, находящиеся между ними.

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void init(int array[], unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
	{
		array[i] = rand() % 40 - 20;
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

void SelectedSort(int array[], int left, int right, bool sort_param = 0)
{
	int index;
	for (unsigned int i = left + 1; i < right; i++)
	{
		index = i;
		for (unsigned int j = i + 1; j < right; j++)
		{
			if (sort_param)
			{
				if (array[j] > array[index])
				{
					index = j;
				}
			}
			else
			{
				if (array[j] < array[index])
				{
					index = j;
				}
			}
		}

		if (i != index)
		{
			swap(array[i], array[index]);
		}
	}
}


int search_l(int a[], int size)
{
	for (int i = 0; i < size - 1 ; i++)
		{
			if (a[i] < 0)
			{
				return i;
			}
		}
	return -1;
}

int search_r(int a[], int size)
{
	for (int i = size - 1; i > 0; i--)
	{
		if (a[i] < 0)
		{
			return i;
		}
	}
	return -1;
}

void main()
{
	srand((unsigned int)time(nullptr));
	const unsigned int size = 20;
	int a[size];

	init(a, size);
	show(a, size, 4);
	cout << endl;
	cout << "sort from " << search_l(a, size) << " to " << search_r(a, size) << endl << endl;
	SelectedSort(a, search_l(a, size), search_r(a, size));
	show(a, size, 4);
	SelectedSort(a, search_l(a, size), search_r(a, size),1);
	show(a, size, 4);
	cout << endl;

}*/