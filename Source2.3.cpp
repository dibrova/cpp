/*3. Известно, что 1 дюйм равен 2.54 см. Разработать при-
ложение, переводящие дюймы в сантиметры и наоборот.
Диалог с пользователем реализовать через систему меню.*/

#include <iostream>
using namespace std;
void main()
{
	const float inch = 2.54;
	float lenth;
	char key;
	cout << "Input value to convert : ";
	cin >> lenth;
	cout << "if you want convert value to in press (0)\n";
	cout << "if you want convert value to cm press (1)\n";
	cin >> key;
	switch (key)
	{
	case '0':
		cout << lenth << " cm = " << lenth / inch <<" in\n";
		break;
	case '1':
		cout << lenth << " in = " << lenth * inch <<" cm\n";
		break;
	default:
		cout << "\nError choice!\n";
		break;
	}
}
