/*13.4. Найти заданную степень числа, пользуясь только
указателями.*/

#include <iostream>
using namespace std;

void main_13_4()
{
	int *ptr_x = new int;
	int *ptr_y = new int;
	int *ptr_i = new int;
	int *ptr_res = new int;
	bool *ptr_Error = new bool;

	do
	{
		*ptr_Error = 0;
		*ptr_res = 1;
		
		cout << "Input value x^y: ";
		cin >> *ptr_x >> *ptr_y;
		
		if (*ptr_y < 0)
		{
			cout << "Error! I can't calculate this, I give up (o_O) \n";
			*ptr_Error = 1;
		}
		else
		{

		for ( *ptr_i = 0; *ptr_i < *ptr_y; (*ptr_i)++)
		{
			*ptr_res *= *ptr_x;
		}
		cout << *ptr_x << " ^ " << *ptr_y << " = " << *ptr_res << endl;
		}
		if (!*ptr_Error)
		{
			cout << "Again ? 1/0: ";
			cin >> *ptr_Error;
		}
	} while (*ptr_Error);
	

}
