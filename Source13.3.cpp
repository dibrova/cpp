/*13.3. Найти факториал числа, пользуясь только указателями.*/

#include <iostream>
using namespace std;

void main_13_3()
{
	int *ptr_n = new int;
	int *ptr_i = new int;
	long long *ptr_res = new long long;
	bool *ptr_Error = new bool;

	do
	{
		*ptr_i = 1;
		*ptr_res = 1;
		*ptr_Error = 0;
		cout << "Input value (n!) n = ";
		cin >> *ptr_n;

		if (*ptr_n < 0)
		{
			cout << "Error input!\n";
			*ptr_Error = 1;
		}
		else
		{
			while (*ptr_i <= *ptr_n)
			{
				*ptr_res = *ptr_res * *ptr_i;
				(*ptr_i)++;
			}
			cout << *ptr_n << "! = " << *ptr_res << endl;
		}
		if (!*ptr_Error)
		{
			cout << "Again ? 1/0: ";
			cin >> *ptr_Error;
		}
	} while (*ptr_Error);
}
