/*14.1. ������������ ������ ������ � ���������� � ���-
���������� ������. ���������� ���������, �������
��������� ������� ������ ������ � ������� ��������.*/

#include <stdlib.h>
#include <iostream>
using namespace std;

void main_14_1()
{
	int size = 31;
	char *string = new char[size];

	
//	char line[21]; // room for 20 chars + '\0'

	cout << "Input string " << size - 1 << " chars:\n";
	gets_s(string, size - 1);
	cout << "Resived string:\n" << string << endl;

	cout << "Using " << strlen(string) + 1 << " elements of array" << endl;// +1 ���� '\0'
	cout << "Free " << size - strlen(string) - 1 << " elements of array" << endl;
	
	delete[]string;
}
