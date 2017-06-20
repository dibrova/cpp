/*7.1. ��� ���������� ������ ������������ 3X4. ����-
������ ����� ���������� ��������� �������� �������
����� ����.
7.2. ���� ���������� ������� ������� n (n �����, n ����-
����). ����� ���������� �� �������� ���������, �����-
�������� � ����-����� ������ ������.
��� ������� � ������ �������� ������� �����������
��������� �������.*/


#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

void main_7_2()
{
	srand((unsigned int)time(nullptr));
	int tab = 3;

	const int rows = 3;
	const int cols = 4;
	int x[rows][cols];

	const int n = 15;
	int arr[n][n];

	cout << "Generated array:\n";
	for (int i = 0, f = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			x[i][j] = rand() % 10;
			cout << setw(tab) << x[i][j];
			if (x[i][j] == 0)
			{
				f++;
			}
		}

		cout << endl;
		if (i == rows - 1)
		{
			cout << "\nArray have " << f << " elements with zerro\n";
		}
	}
	system("pause");
	cout << endl << endl;



	cout << "Generated array:\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
			cout << setw(tab) << arr[i][j];

		}

		cout << endl;
	}
	system("pause");
	cout << endl << endl;


	char key = '3';
	for (int i = 0, max = arr[0][0]; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
				if (key == '1' && i >= j)
				{
					cout << setw(tab) << arr[i][j];
					if (max < arr[i][j])
					{
						max = arr[i][j];
					}
				}
				if (key == '2' && i <= j)
				{
				cout << setw(tab) << arr[i][j];
				if (max < arr[i][j])
					{
						max = arr[i][j];
					}
				}
				if (key == '3' && i >= n - 1 - j)
				{
					cout << setw(tab) << arr[i][j];
					if (max < arr[i][j])
					{
						max = arr[i][j];
					}
				}
				if (key == '4' && i <= n - 1 - j)
				{
					cout << setw(tab) << arr[i][j];
					if (max < arr[i][j])
					{
						max = arr[i][j];
					}
				}
				if (key == '5' && j <= n - 1 && j >= i && j >= n - 1 - i)
				{
					cout << setw(tab) << arr[i][j];
					if (max < arr[i][j])
					{
						max = arr[i][j];
					}
				}
				if (key == '6' && j >= 0 && j <= i && j <= n - 1 - i)
				{
					cout << setw(tab) << arr[i][j];
					if (max < arr[i][j])
					{
						max = arr[i][j];
					}
				}
				if (key == '7' && j >= 0 && j <= i && j <= n - 1 - i ||
					j <= n - 1 && j >= i && j >= n - 1 - i)
				{
					cout << setw(tab) << arr[i][j];
					if (max < arr[i][j])
					{
						max = arr[i][j];
					}
				}
				if (key == '8' && i <= n - 1 && j <= i && j >= n - 1 - i)
				{
					cout << setw(tab) << arr[i][j];
					if (max < arr[i][j])
					{
						max = arr[i][j];
					}
				}
				if (key == '9' && i >= 0 && j >= i && j <= n - 1 - i)
				{
					cout << setw(tab) << arr[i][j];
					if (max < arr[i][j])
					{
						max = arr[i][j];
					}
				}
				if (key == '0' && i >= 0 && j >= i && j <= n - 1 - i ||
					i <= n - 1 && j <= i && j >= n - 1 - i)
				{
					cout << setw(tab) << arr[i][j];
					if (max < arr[i][j])
					{
						max = arr[i][j];
					}
				}

			else
			{
				cout << "  ";
			}
			
		}
		cout << endl;
		if (i == n - 1)
		{
			cout << "\nMax value of this arria: " << max << endl;
		}
	}
	system("pause");
	cout << endl << endl;

}