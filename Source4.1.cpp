/*4.1. Пользователь вводит с клавиатуры число — про-
грамма должна показать сколько в данном числе цифр.
Число вводится целиком в одну переменную.
Примечание: Например, пользователь ввел число 12345.
На экране должно появиться сообщение о том, что в
числе 5 цифр.*/

#include <iostream>
using namespace std;
void main()
{
	int i, digit;

	cout << "Input value for calculate digits: ";
	cin >> digit;
	cout << endl;

	for (i = 1; ; i++)
	{
		digit = (digit - digit % 10) / 10;
		if (digit == 0)
		{
			break;
		}
	}
	cout << "Value have " << i << " digits" << endl << endl;
}