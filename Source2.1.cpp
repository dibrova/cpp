/*1. Напишите программу, проверяющую число, введен-
ное с клавиатуры на четность.*/

#include <iostream>
using namespace std;
void main()
{
	int a;
	cout << "input digit :";
	cin >> a;
	if (a%2==0)
	{
		cout << a << "\t is even \n";
	}
	else
	{
		cout << a << "\t is odd \n";
	}	
}
