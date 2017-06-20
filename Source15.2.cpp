/*15.2.Дана матрица порядка MxN(M строк, N столбцов).
Необходимо заполнить ее значениями и написать функ -
цию, осуществляющую циклический сдвиг строк и / или
столбцов массива указанное количество раз и в указан -
ную сторону.*/

#include <iostream>
#include <conio.h>
using namespace std;

enum Dir { UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ESC = 27, CODE = 224 };
void VMove(int** array, unsigned int rows, Dir dir);
void HMove(int** array, unsigned int rows, unsigned int cols, Dir dir);
void KeyEvent(int** array, unsigned int rows, unsigned int cols);
void Show(int** array, unsigned int rows, unsigned int cols);

void main_15_2()
{
	unsigned int rows = 5;
	unsigned int cols = 5;
	int **array = new int*[rows];
	for (unsigned int i = 0; i < rows; i++)
	{
		array[i] = new int[cols] {0};
	}


	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			array[i][j] = j;//rand() % 9 + 1;
			cout << array[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	KeyEvent(array, rows, cols);


	for (unsigned int i = 0; i < rows; i++)
	{
		delete[]array[i];
	}

	delete[]array;
}

void VMove(int** array, unsigned int rows, Dir dir)
{
	int* temp;

	if (dir == UP)
	{
		temp = array[0];
		for (unsigned int i = 0; i < rows - 1; i++)
		{
			array[i] = array[i + 1];
		}
		array[rows - 1] = temp;
	}
	else if (dir == DOWN)
	{
		temp = array[rows - 1];
		for (unsigned int i = rows - 1; i > 0; i--)
		{
			array[i] = array[i - 1];
		}
		array[0] = temp;
	}
}

void HMove(int** array, unsigned int rows, unsigned int cols, Dir dir)
{
	int temp;
	if (dir == LEFT)
	{
		for (unsigned int i = 0; i < rows; i++)
		{
			temp = array[i][0];
			for (unsigned int j = 0; j < cols - 1; j++)
			{
				array[i][j] = array[i][j + 1];
			}
			array[i][cols - 1] = temp;
		}
	}
	else if (dir == RIGHT)
	{
		for (unsigned int i = 0; i < rows; i++)
		{
			temp = array[i][cols - 1];
			for (unsigned int j = cols - 1; j > 0 ; j--)
			{
				array[i][j] = array[i][j - 1];
			}
			array[i][0] = temp;
		}
		
	}
}

void KeyEvent(int** array, unsigned int rows, unsigned int cols)
{
	unsigned char ch;
	while (1)
	{
		ch = _getch();
		if (ch == ESC)
		{
			break;
		}
		else if (ch == CODE)
		{
			ch = _getch();
			switch (ch)
			{
			case UP:
				VMove(array, rows, UP);
				break;
			case DOWN:
				VMove(array, rows, DOWN);
				break;
			case LEFT:
				HMove(array, rows, cols, LEFT);
				break;
			case RIGHT:
				HMove(array, rows, cols, RIGHT);
				break;
			}
		}

		Show(array, rows, cols);
	}
}

void Show(int** array, unsigned int rows, unsigned int cols)
{
	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			cout << array[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
