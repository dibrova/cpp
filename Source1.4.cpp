/*4. В C нет операции возведения в квадрат. Напишите
программу, которая вычисляет квадрат любого, введен-
ного числа.*/

#include <iostream>
using namespace std;
void main()
{
	cout << "input value to take x^2 x=";
	float x;
	cin >> x;
	cout << x << "^2=" << x*x << "\n";
}
