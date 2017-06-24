/*13.2. Написать примитивный калькулятор, пользуясь
только указателями.*/

#include <iostream>
using namespace std;

void main_13_2()
{
	double *ptr_Digit1 = new double;
	double *ptr_Digit2 = new double;
	char *ptr_Operation = new char;
	bool *ptr_Error = new bool;

	do
	{
		*ptr_Error = 0;
		cout << "Input digit and operation \"a (+ - * /) b\": ";
		cin >> *ptr_Digit1 >> *ptr_Operation >> *ptr_Digit2;

		switch (*ptr_Operation)
		{
		case '+':
			cout << *ptr_Digit1 << *ptr_Operation << *ptr_Digit2 << " = " << *ptr_Digit1 + *ptr_Digit2 << endl;
			break;
		
		case '-':
			cout << *ptr_Digit1 << *ptr_Operation << *ptr_Digit2 << " = " << *ptr_Digit1 - *ptr_Digit2 << endl;
			break;
		
		case '*':
			cout << *ptr_Digit1 << *ptr_Operation << *ptr_Digit2 << " = " << *ptr_Digit1 * *ptr_Digit2 << endl;
			break;
		
		case '/':
			if (*ptr_Digit2 == 0)
				{
					cout << "Error! Can't /0\n";
					*ptr_Error = 1;
					break;
				}
			cout << *ptr_Digit1 << *ptr_Operation << *ptr_Digit2 << " = " << *ptr_Digit1 / *ptr_Digit2 << endl;
			break;

		default:
			cout << "Error operation!\n";
			*ptr_Error = 1;
			break;
		}

		if (!*ptr_Error)
		{
			cout << "Again ? 1/0:";
			cin >> *ptr_Error;
		}

	} while (*ptr_Error);

}
