/*10.1. ��� ������ ����� ������������ 10 ���������. ��������
�������, ������� ��������� ������ �� ����������� ��� ��
��������, � ����������� �� �������� ��������� �������.
���� �� ����� 1, ���������� ���� �� ��������, ���� 0, �� ��
�����������. ������ 2 ��������� ������� � ��� ������ �
��� ������, ������ �������� �� ��������� ����� 1.

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

template <typename T>
void show(T array[], unsigned int size, int field)
{
	for (unsigned int i = 0; i < size; i++)
	{
		cout << setw(field) << array[i];
	}

	cout << endl;
}

void SelectedSort(int array[], unsigned int size, bool param = 1)
{
	int index;
	for (unsigned int i = 0; i < size - 1; i++)
	{
		index = i;
		for (unsigned int j = i + 1; j < size; j++)
	{
		if (param)
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

void main()
{
	const unsigned int size = 10;
	int a[size] = { 5,   2,   8,   3,   2,   2,   9,   0,   1,   4 };
	show(a, size, 2);
	cout << endl;
	SelectedSort(a, size);
	show(a, size, 2);
	SelectedSort(a, size, 0);
	show(a, size, 2);
}
*/