/*4.1. ������������ ������ � ���������� ����� � ���-
������ ������ �������� ������� � ������ ����� ����.
����� �������� ������� � ���� ����������.
����������: ��������, ������������ ���� ����� 12345.
�� ������ ������ ��������� ��������� � ���, ��� �
����� 5 ����.*/

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