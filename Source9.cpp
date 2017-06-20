/*9.2.Написать перегруженные шаблоны функций для
нахождения корней линейного (a*x + b = 0) и квадрат-
ного (a*x2+b*x + c = 0) уравнений. Замечание: в функции
передаются коэффициенты уравнений.
9.3.Написать функцию, которая принимает в качестве
параметров вещественное число и количество знаков
после десятичной точки, которые должны остаться. За-
дачей функции является округление вышеуказанного
вещественного числа с заданной точностью*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

template <typename T1, typename T2>
void fn(T1 a, T2 b);
template <typename T1, typename T2, typename T3 >
void fn(T1 a, T2 b, T3 c);
double around(double digit, int n);
int tenX(int n);

void main_9()
{
//	setlocale(LC_ALL, "rus");
	double A, B, C, dig;
	int num;
	char f;

m1:	system("cls");
	cout << "input a,b for ax+b=0 \n";
	cin >> A >> B;
	fn(A, B);

	cout << endl;
	cout << "Again? Y/N...: ";
	cin >> f;
	if (f == 'y' || f == 'Y')
	{
		goto m1;
	}

m2:	system("cls");
	cout << "input a,b,c for ax^2+bx+c=0 \"1,3,2\"\n";
	cin >> A >> B >> C;
	fn(A, B, C);
	
	cout << endl;
	cout << "Again? Y/N...: ";
	cin >> f;
	if (f=='y'||f=='Y')
	{
		goto m2;
	}

m3:	system("cls");
	cout << "Input digit for around \"12.123456\" and numer of sign \n";
	cin >> dig >> num;
	cout << around(dig, num) << endl;

	cout << endl;
	cout << "Again? Y/N...: ";
	cin >> f;
	if (f == 'y' || f == 'Y')
	{
		goto m3;
	}

}

template <typename T1, typename T2>
void fn(T1 a, T2 b)
{
	if (a == 0)
	{
		cout << "Error data! X not found...\n";
	}
	else
	{
	double	x = -b/a;
	cout << "X = " << x << endl;
	}
	
}

template <typename T1, typename T2, typename T3 >
void fn(T1 a, T2 b, T3 c)
{
	double d = (b * b) - (4 * a * c);

//	cout << d << endl;
//	cout << sqrt(d) << endl;

	if (d < 0||a == 0)
	{
		cout << "Error data! X not found...\n";
	}
	else if (d == 0)
	{
		double x = -b / (2 * a);
		cout << "X = "<< x << endl;
	}
	else if (d > 0)
	{
		double x1 = (-b + sqrt(d)) / (2 * a);
		double x2 = (-b - sqrt(d)) / (2 * a);
		cout << "X1 = " << x1 << endl;
		cout << "X2 = " << x2 << endl;
	}
}



double around(double digit,int n)
{
	int temp = digit * tenX(n + 1);

//	cout << digit << endl;
//	cout << temp << endl;

	if (temp%10>=5)
	{
		temp += 10;
	}
	temp /= 10;

//	cout << temp << endl;
//	cout << tenX(n) << endl;

	return double(temp) / tenX(n);
}

int tenX(int m)
{
	int ten = 1;
	for (int i = 0; i < m; i++)
	{
		ten *= 10;
	}
	return ten;
}