/*5.1. ������� ���������, ������� ������� �� ����� ���-
���� ����� � ��������� �� 2 �� 1000. (����� ����������
�������, ���� ��� ������� ������ �� 1 � �� ���� ����
��� �������; ������ ����� 1 � 2 �������� �� ���������).*/

#include <iostream>
using namespace std;

void main()
{
	int j;
	for (int i = 2; i < 1000; i++)
	{
		if (i % 2 == 0)
		{
			continue;
		}
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}

		if (i == j)
		{
			cout << i << ", ";
		}
	}

	cout << endl;
}