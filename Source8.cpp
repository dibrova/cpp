/*8.1. �������� �������, ������� �������� � �������� ��-
�������� ����� ������������� ����� � ������� ������-
���, � ������� ��� ����� ������ ����������� (�������
��������� �� 2 �� 36). ��������, ��� �������� ����� 27 �
������� ��������� 16 ������ ���������� 1B; 13 � 5-� �
23; 35 � 18-� � 1H.
8.2. ���� �������. �������: ������� ��� ���������
������ �� ���������� �� 1 �� 6. ���� ���������� � ���-
��������, ������ ��������� ����������. ��������� ���,
� ���� ����� �������� ����� �� ������ ���� �������
������. ������������� ����������� ��������� �������
���� ��������� ��� �����������. ������ ������������
� ������� ��������. � ����� ���� ���������� ��������
������� ����� �� ������� ��� ����� ����������.*/


#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void convert(unsigned int num,unsigned int base);
void cube_show(int digit);
int throw_dicegen();

void main_8()
{
	srand((unsigned int)time(nullptr));
	unsigned int comp, player;
	int f;
	char rp;
	unsigned int digit,n;

//-----------------------------------------------------------------

	cout << "Convertor to another base system" << endl;
e:	cout << "Input digit for convertation :";
	cin >> digit;
	cout << "Input base of system 2..36 :";
	cin >> n;
	if (n < 2 || n > 36)
	{
		cout << "Error base system!" << endl;
		goto e;
	}
	else
	{
		cout << digit << " in " << n << " system : "; 
		convert(digit, n);
		cout << "Convert again? Y/N ";
		cin >> rp;
		if (rp == 'y' || rp == 'Y')
		{
			goto e;
		}
	}

//-----------------------------------------------------------------

	system("cls");

	cout << "Start game!!!\n\n";
m:	cout << "Comp and player throw dice...\n\n";

	comp=throw_dicegen();
	player=throw_dicegen();

	if (comp > player)
	{
		cout << "Comp Win!!! and begin first...\n";
		f = 0;
	}
	else if (comp < player)
	{
		cout << "Player Win!!! and begin first...\n";
		f = 1;
	}
	else if (comp == player)
	{
		cout << "Draw!!! new throw...\n";
		goto m;
	}

	comp = 0;
	player = 0;

	if (f == 0)
	{
		cout << "Comp throw dice...\n\n";
		comp += throw_dicegen();
	}

	cout << "Player throw dice...\n\n";
	player += throw_dicegen();

	cout << "Comp throw dice...\n\n";
	comp += throw_dicegen();

	cout << "Player throw dice...\n\n";
	player += throw_dicegen();

	cout << "Comp throw dice...\n\n";
	comp += throw_dicegen();

	cout << "Player throw dice...\n\n";
	player += throw_dicegen();

	cout << "Comp throw dice...\n\n";
	comp += throw_dicegen();

	cout << "Player throw dice...\n\n";
	player += throw_dicegen();

	cout << "Comp throw dice...\n\n";
	comp += throw_dicegen();

	cout << "Player throw dice...\n\n";
	player += throw_dicegen();

	if (f == 1)
	{
		cout << "Comp throw dice...\n\n";
		comp += throw_dicegen();
	}

//	cout << comp << endl;
//	cout << player << endl;

	cout << "Comp Middle count: " << comp / 5.0 << endl;
	cout << "Player Middle count: " << player / 5.0 << endl;

	if (comp > player)
	{
		cout << "Comp Win!\n";
	}
	else if (comp < player)
	{
		cout << "Player Win!\n";
	}
	else if (comp == player)
	{
		cout << "Drow! Replay? Y/N ";
		cin >> rp;
		if (rp == 'y' || rp == 'Y')
		{
			goto m;
		}

	}
	cout << "Play again? Y/N ";
	cin >> rp;
	if (rp == 'y' || rp == 'Y')
	{
		goto m;
	}
	
}

void convert(unsigned int num,unsigned int base)
{
	int size = 0, arr[1000];
	while (num > 0)
	{
		arr[size++] = num % base;
		num /= base;
	}

	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] <= 9)
		{
			cout << arr[i];
		}
		else
		{
			cout << char(arr[i] - 10 + 'A');
		}
	}
	cout << endl;
}

void cube_show(int digit)
{
	if (digit == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i == 0|| j == 0 || i == 6 || j == 6 ||
					i == 3 && j == 3)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}

			}
			cout << endl;
		}
	}
	if (digit == 2)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i == 0 || j == 0 || i == 6 || j == 6 ||
					i == 2 && j == 2 || i == 4 && j == 4)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}

			}
			cout << endl;
		}
	}
	if (digit == 3)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i == 0 || j == 0 || i == 6 || j == 6 ||
					i == 2 && j == 2 || i == 3 && j == 3 || i == 4 && j == 4)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}

			}
			cout << endl;
		}
	}
	if (digit == 4)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i == 0 || j == 0 || i == 6 || j == 6 ||
					i == 2 && j == 2 || i == 2 && j == 4 || 
					i == 4 && j == 4 || i == 4 && j == 2)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}

			}
			cout << endl;
		}
	}
	if (digit == 5)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i == 0 || j == 0 || i == 6 || j == 6 ||
					i == 2 && j == 2 || i == 2 && j == 4 ||
					i == 4 && j == 4 || i == 4 && j == 2 || i == 3 && j == 3)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}

			}
			cout << endl;
		}
	}
	if (digit == 6)
	{
		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (i == 0 || j == 0 || i == 6 || j == 6 ||
					i == 2 && j == 2 || i == 2 && j == 4 ||
					i == 4 && j == 4 || i == 4 && j == 2 ||
					i == 3 && j == 2 || i == 3 && j == 4)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}

			}
			cout << endl;
		}
	}
	cout << endl;
}

int throw_dicegen()
{
	int cube_1 = (rand() % 6 + 1);
	cube_show(cube_1);
	int cube_2 = (rand() % 6 + 1);
	cube_show(cube_2);
	cout << cube_1 + cube_2 << endl << endl;
	return cube_1 + cube_2;
}
