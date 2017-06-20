#include <iostream>
using namespace std;

void main_3()

{
	int a;
	int b;
	for (a = 0; a < 11; a++)
	{
		for (b = 0; b < 11; b++)
		{
			if (a==b || 
				a==0 || b==0 || 
				a==10 || b==10 ||
				a+b==10 //||
				// a+b<=10 ||
				//b == 10/2 + a || b == 10/2 - a || a == 10/2  ||
				//a == 10 / 2 + b || a == 10 / 2 - b || b == 10 / 2 + a || b == 10 / 2 - a + 10 ||
				//a <= 10 / 2 && a + b >= 5// || a <= 10/2 && a+b -10 <= 5
				)
			{
				//cout << a << ":" << b << "\t";;
				cout << "* ";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;


	}
	for (int r = 1; r <= 10; r++)
	{
		for (int c = 1; c <= 10 - r; c++)
			cout << ' ';
		for (int c = 1; c <= r * 2 - 1; c++)
			cout << '*';
		cout << '\n';
	}
	for (int r = 10; r >= 1; r--)
	{
		for (int c = 0; c <= 10 - r; c++)
			cout << ' ';
		for (int c = 3; c <= r * 2 - 1; c++)
			cout << '*';
		cout << '\n';
	}
}