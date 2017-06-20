/*3.1. –азработать программу, котора€ выводит на экран
горизонтальную линию из символов. „исло символов,
какой использовать символ, и кака€ будет лини€ Ч верти-
кальна€, или горизонтальна€ Ч указывает пользователь.*/

#include <iostream>
using namespace std;
void main()
{
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
}