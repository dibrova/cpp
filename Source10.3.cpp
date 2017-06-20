/*10.3.ƒан массив из 20 целых чисел со значени€ми от 1 до 20.
Ќеобходимо:
* написать функцию, разбрасывающую элементы мас-
сива произвольным образом;
* создать случайное число из того же диапазона и найти
позицию этого случайного числа в массиве;
* отсортировать элементы массива, наход€щиес€ слева
от найденной позиции по убыванию, а элементы массива,
наход€щиес€ справа от найденной позиции по возрастанию.


#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

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

void SelectedSort(int array[], int left, int right, bool sort_param = 0)
{
	int index;
	for (int i = left ; i < right; i++)
	{
		index = i;
		for (int j = i + 1; j < right; j++)
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

int line_search(int key, int a[], int size, int start)
{
	if (start >= size)
	{
		return -1;
	}

	for (int i = start; i < size; i++)
	{
		if (a[i] == key)
		{
			return i;
		}
	}

	return -1;
}

void crazy_sort(int array[],int size, unsigned int round)
{
	for (unsigned int i = 0; i < round; i++)
	{
		swap(array[(rand() % (size - 1))], array[(rand() % (size - 1))]);
	}
}

void main_10()
{
	srand((unsigned int)time(nullptr));
	const unsigned int size = 20;
	int a[size], digit;
	char f;
	do
	{
		system("cls");
		init(a, size);
		show(a, size, 3);
		cout << endl;
		crazy_sort(a, size, 100);
		cout << "AbraKadabra!!!" << endl << endl;
		show(a, size, 3);
		cout << endl;
		digit = rand() % size + 1;
		cout << "Generate rendom didit: " << digit << endl << endl;
		cout << "Digit found! position: " << line_search(digit,a,size,0) + 1 << endl << endl;
		SelectedSort(a, 0, line_search(digit, a, size, 0), 1);
		SelectedSort(a, line_search(digit, a, size, 0) + 1, size);
		show(a, size, 3);
		cout << endl;

		cout << "Again? y/n: ";
		cin >> f;
	} while (f == 'y' || f == 'Y');
}
*/