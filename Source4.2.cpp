/*4.2. Пользователь вводит с клавиатуры число, необходимо
перевернуть его (число) и вывести на экран.
Примечание: Например, пользователь ввел число 12345.
На экране должно появиться число наоборот — 54321.*/


#include <iostream>
using namespace std;
void main()
{
	int i, digit, res = 0;

	cout << "Input digit for reverse: ";
	cin >> digit;
	cout << endl;

	for (i = 1; ; i++)
	{
		res = res * 10 + digit % 10;
		digit = (digit - digit % 10) / 10;
		if (digit == 0)
		{
			break;
		}
	}
	cout << "Your reverse digit: " << res << endl << endl;

}