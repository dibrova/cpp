/*6.1. Написать программу, которая выводит содержимое
массива наоборот.
Пример: массив 23 11 6 превращается в 6 23 11.
6.2. Написать программу, которая находит сумму четных
и сумму нечетных элементов массива.
6.3. Написать программу, которая находит в массиве
значения, повторяющиеся два и более раз, и показывает
их на экран.
6.4. Написать программу, которая находит в массиве са-
мое маленькое нечетное число и показывает его на экран.*/

#include <iostream>
#include <time.h>

using namespace std;

void main_6()
{
	const int size = 10;
	int arr[size] = {};

	srand((unsigned int)time(nullptr));

mark:

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 25 - 10;
	}


	cout << "Generated array:\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;



	int minOdd, sumOdd = 0, sumEven = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2)
		{
			minOdd = arr[i];
			break;
		}
	}


	cout << "Reverse array:\n";
	for (int i = size - 1; i >= 0; i--)
	{
		cout << arr[i] << " ";

		if (arr[i] % 2)
		{
			sumOdd += arr[i];
		}
		else
		{
			sumEven += arr[i];
		}

		if ((arr[i] % 2) && (minOdd > arr[i]))
		{
			minOdd = arr[i];
		}

	}


	cout << "\n\nSum Odd: " << sumOdd << endl;
	cout << "Sum Even: " << sumEven << endl;
	cout << "\nMin Odd: " << minOdd << endl;


	for (int i = 0, f; i < size; i++)
	{
		f = 0;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				f++;
			}
		}
		if (f == 1)
		{
			cout << "\nRepeat digit: " << arr[i];
		}

	}


	cout << "\n\ninput 0 to exit:";
	char key;
	cin >> key;
	if (key != '0')
	{
		system("cls");
		goto mark;
	}

}