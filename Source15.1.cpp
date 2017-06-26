/*15.1. Написать программу, которая осуществляет до-
бавление строки или столбца в любое место двумерной
матрицы по выбору пользователя.*/

#include <stdlib.h>
#include <iostream>

using namespace std;

void main_15_1()
{
	
	int rows = 10;
	int cols = 10;

	cout << "Input size matrix (rows columns): ";
	cin >> rows >> cols;
	cout << "Generate matrix...\n";

	int** ptr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		ptr[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			ptr[i][j] = rand() % 9 + 1;
			cout << ptr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;


	char place = 'c';//rows cols
	int position = 5;
	int new_rows = rows;
	int new_cols = cols;

	cout << "What we'll insert column or rows? (c/r): ";
	cin >> place;
	cout << "What position used for insert? : ";
	cin >> position;
	position--;
	cout << endl;

	if (place == 'r')
	{
		new_rows++;
		int** ptr_new = new int*[new_rows];
		for (int i = 0; i < new_rows; i++)
		{
			ptr_new[i] = new int[new_cols];
		}
		for (int i = 0, ii = 0; ii < new_rows; i++, ii++)
		{
			for (int j = 0; j < new_cols; j++)
			{
				if (ii == position)
				{
					ptr_new[ii][j] = 0;
					cout << ptr_new[ii][j] << ' ';
					if (j == new_cols-1)
					{
						i--;
					}
				}
				else
				{
					ptr_new[ii][j] = ptr[i][j];
					cout << ptr_new[ii][j] << ' ';
				}


			}
			cout << endl;
		}
		cout << endl;

		for (int i = 0; i < new_rows; i++)
		{
			delete[]ptr_new[i];
		}

		delete[]ptr_new;
	}
	else if (place == 'c')
	{
		new_cols++;
		int** ptr_new = new int*[new_rows];
		for (int i = 0; i < new_rows; i++)
		{
			ptr_new[i] = new int[new_cols];
		}

		for (int i = 0; i < new_rows; i++)
		{
			for (int j = 0, jj = 0; jj < new_cols; j++, jj++)
			{
				if (jj == position)
				{
					ptr_new[i][jj] = 0;
					cout << ptr_new[i][jj] << ' ';
					j--;
				}
				else
				{
					ptr_new[i][jj] = ptr[i][j];
					cout << ptr_new[i][jj] << ' ';
				}


			}
			cout << endl;
		}
		cout << endl;
	
		for (int i = 0; i < new_rows; i++)
		{
			delete[]ptr_new[i];
		}

		delete[]ptr_new;
	}
	
	else
	{
		cout << "Error data! \n";
	}


	for (int i = 0; i < rows; i++)
	{
		delete[]ptr[i];
	}

	delete[]ptr;
	
}
