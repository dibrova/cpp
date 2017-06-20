/*3.3. Дано натуральное число n. Написать программу,
которая вычисляет факториал неотрицательных целых
чисел n (т.е. число целое и больше 0). Формула вычисле-
ния факториала приведена ниже.
n! = 1*2*3*....*n, (формула вычисления факториала числа n)
0! = 1 (факториал 0 равен 1 (по определению факториала))*/

#include <iostream>
using namespace std;
void main_0()
{
	int n, i = 1;
	long long res = 1;
		
	cout << "Input value (n!) n = ";
	cin >> n;

	if (n < 0)
	{
		cout << "Error input!\n";
	}
	else
	{
		while (i <= n)
		{
			res = res*i;
			i++;
		}
		cout << n << "! = " << res << endl;	
	}


	/*	
	int begin, end, sum, i;
	do
	{
		cout << "Enter begin digit :";
		cin >> begin;
		cout << "Enter end digit :";
		cin >> end;
		if (begin >= end)
		{
			cout << "\nError input!\n\n";
		}
	} while (begin>=end);
	
	sum = 0;
	i = begin;

	while (i<=end)
	{
		if (i%2==1)
		{
			sum = sum + i;
			//i++;
		}
		i++;
	}
	cout << "Sum of ODD digit :" << sum << endl;
	*/	
	
	/*
	char simbol,key;
	int count,i=1;
	
	cout << "Input simbol to use in line :";
	cin >> simbol;

	cout << "Input number symbols to use in line :";
	cin >> count;
	do
	{
	cout << "Input line type \"h\"-horizontal or \"v\"-vertical :";
	cin >> key;
	
	cout << (key == 'h' || key == 'v') << endl;
	cout << (key != 'h' && key != 'v') << endl;
	cout << (key == 'v') << endl;

	} while (key != 'h' && key != 'v');
	
	while (i<=count)
	{
		cout << simbol;
		i++;
			if (key == 'v')
			{
				cout << endl;
			}
		
	}
	cout << endl;
	*/

	/*
	const float inch = 2.54;
	float lenth;
	char key;
	cout << "Input value to convert : ";
	cin >> lenth;
	cout << "if you want convert value to in press (0)\n";
	cout << "if you want convert value to cm press (1)\n";
	cin >> key;
	switch (key)
	{
	case '0':
		cout << lenth << " cm = " << lenth / inch <<" in\n";
		break;
	case '1':
		cout << lenth << " in = " << lenth * inch <<" cm\n";
		break;
	default:
		cout << "\nError choice!\n";
		break;
	}
	*/

	/*
	int a;
	cout << "input digit : ";
	cin >> a;
	if (a%2==0)
	{
		cout << "digit " << a << " is even \n";
	}
	else
	{
		cout << "digit " << a << " is odd \n";
	}
	*/
}
