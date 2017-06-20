/*5.0. "Нарисовать" триугольники 1-4 прямоугольные, 5-6 равнобедренные, 7 ромб закрашенный наполовину*/

#include <iostream>
using namespace std;

void main()
{
	int h, w;
	char key;
	
	do
	{
		cout << "Input value h (ODD) :";
		cin >> h;
		w = h;
		cout << endl;
	} while (h%2 == 0);
	
	cout << "1. see triangle |\\ \n";
	cout << "2. see triangle \\| \n";
	cout << "3. see triangle /|  \n";
	cout << "4. see triangle |/  \n";
	cout << "5. see triangle \\/ \n";
	cout << "6. see triangle /\\ \n";
	cout << "7. see romb \n";
	cout << "0. Exit \n";
	
	do
	{
	cout << "\nchoice :";
	cin >> key;
	cout << endl;
	
	switch (key)
	{
	case '1':
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (j == 0 || i == h - 1 || i == j)
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
		break;
	case '2':
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == 0 || j == w - 1 || i == j)
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
		break;
	case '3':
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == h - 1 || j == w - 1 || i == w - 1 - j)
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
		break;
	case '4':
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == 0 || j == 0 || i == w - 1 - j)
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
		break;
	case '5':
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == 0 || i == 2 * j || i == 2 * (w - 1 - j))
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
		break;
	case '6':
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == h - 1 || 2 * j == w - 1 - i || 2 * j == w - 1 + i)
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
		break;
	case '7':
		for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (i == j + h / 2 || i == w - 1 - j + h / 2 ||
				i >= j - h / 2 && i >= w - 1 - j - h / 2 && i <= h / 2)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	break;
	case '0':
		cout << "Goodbye!\n\n";
		break;
	default:
		cout << "Error choice!\n";
		break;
	}
	cout << endl << endl;
	} while (key != '0');
}