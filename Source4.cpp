#include <iostream>
using namespace std;

void main_4()
{
	int h = 15;
	int w = 15;

/*	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (i == 0 || j == 0 || i == h - 1 || j == w - 1 ||
				i == j || i == w - 1 - j || j == w / 2 || i == h / 2)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;
	}

	cout << endl << endl;
*/


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (
				//i == 0 //���� ��������
				j == 0 //��� ����
				|| i == h - 1 //��� ��������
				//|| j == w - 1 //���� ����
				|| i == j // ���� ���� ��� ����
				//|| i == w - 1 - j //���� ���� ���� ��� ���
				//|| j == w / 2 //����� ����
				//|| i == h / 2 //���� ������

				)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;
	}

	cout << endl << endl;
//------------------------------------------------------------------------

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (
				i == 0 //���� ��������
					   //				|| j == 0 //��� ����
					   //				|| i == h - 1 //��� ��������
				|| j == w - 1 //���� ����
				|| i == j // ���� ���� ��� ����
						  //				|| i == w - 1 - j //���� ���� ���� ��� ���
						  //				|| j == w / 2 //����� ����
						  //				|| i == h / 2 //���� ������

				)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;
	}

	cout << endl << endl;
//------------------------------------------------------------------------


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (
//				i == 0 //���� ��������
//				|| j == 0 //��� ����
				i == h - 1 //��� ��������
				|| j == w - 1 //���� ����
//				|| i == j // ���� ���� ��� ����
				|| i == w - 1 - j //���� ���� ���� ��� ���
 //				|| j == w / 2 //����� ����
 //				|| i == h / 2 //���� ������

				)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;
	}

	cout << endl << endl;
	//------------------------------------------------------------------------

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (
				i == 0 //���� ��������
				|| j == 0 //��� ����
 //				|| i == h - 1 //��� ��������
//				|| j == w - 1 //���� ����
//				|| i == j // ���� ���� ��� ����
				|| i == w - 1 - j //���� ���� ���� ��� ���
//				|| j == w / 2 //����� ����
 //				|| i == h / 2 //���� ������

				)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;
	}

	cout << endl << endl;
	//------------------------------------------------------------------------


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (
				i == 0 //���� ��������
 				|| i == 2*j //���� ����
				|| i == 2*(w-1-j) // ���� ���� ��� ����
				)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;
	}

	cout << endl << endl;
	//------------------------------------------------------------------------


	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (
								//i == 10 //���� ��������
								 //j == i //��� ����
				i == h - 1 //��� ��������
				//				|| j == w - 1 //���� ����
				|| 2*j == w-1-i 
				|| 2*j == w-1+i
				//2*i == w/2 + j// ���� ���� ��� ����
				//				|| i == w - 1 - j //���� ���� ���� ��� ���
				//				|| j == w / 2 //����� ����
				//i == h / 2 || i == h / 2 + j
				//|| i == h / 2 - j
				//|| j == w / 2 + i
				//|| j == w / 2 - i + w - 1//���� ������

				)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;
	}

	cout << endl << endl;
	//------------------------------------------------------------------------

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (i == j + h/2 || i == w - 1 - j + h/2 ||
				i >= j - h/2 && i >= w - 1 -j - h/2 && i <= h/2)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl << endl;
	}

	
}