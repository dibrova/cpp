/*3.2. Ќаписать программу, котора€ находит сумму всех
целых нечетных чисел в диапазоне, указанном пользователем.*/

#include <iostream>
using namespace std;
void main()
{
	
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
		}
		i++;
	}
	cout << "Sum of ODD digit :" << sum << endl;
}