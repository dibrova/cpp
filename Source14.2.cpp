/*14.2 Показать на экран с m по n символов строки, введен-
ной пользователем и записать данный отрезок в другой
массив. (m и n также вводятся пользователем)*/

#include <stdlib.h>
#include <iostream>
using namespace std;

void main_14_2()
{
	int m, n;
	int size = 30;
	char *string = new char[size] {};
	char *newstring = new char[size] {};

	gets_s(string, size);

	cout << string << endl;
	cout << "Input number position from and to move string (m n): ";
	cin >> m >> n;

	cout << "Show elemens from m to n position:\n";
	for (int i = m; i <= n; i++)
	{
		cout << string[i];
	}
	cout << endl;

//	int j;
	for (int i = m, j = 0; j <= n-m; i++, j++)
	{
		newstring[j] = string[i];
	}
//	newstring[j+1] = NULL;
	cout << newstring << endl;


}
