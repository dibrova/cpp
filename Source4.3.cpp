/*4.3. Пользователь вводит с клавиатуры число, необходимо
показать на экран сумму его цифр.
Примечание: Например, пользователь ввел число 12345.
На экране должно появиться сообщение о том, что сумма
цифр числа 15.*/


#include <iostream>
using namespace std;
void main()
{
	int i, digit, sum = 0;

	cout << "Input digits for sum: ";
	cin >> digit;
	cout << endl;

	for (i = 1; ; i++)
	{
		sum = sum + digit % 10;
		digit = (digit - digit % 10) / 10;
		if (digit == 0)
		{
			break;
		}
	}
	cout << "Sum of digits: " << sum << endl << endl;

}