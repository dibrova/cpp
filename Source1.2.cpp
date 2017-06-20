/*Напишите программу, которая переводит гривны в
$,Є, российские рубли.*/

#include <iostream>
using namespace std;
void main()
{
	float usd, eur, rub, uah;
	cout << "input cost 1 USD=";
	cin >> usd;
	cout << "input cost 1 EUR=";
	cin >> eur;
	cout << "input cost 1 RUB=";
	cin >> rub;
	cout << "input sum in UAH to convert \n";
	cin >> uah;
	float resu = uah / usd;
	cout << "You can buy: \n" << resu << "\t USD \n";
	resu = uah / eur;
	cout << resu << "\t EUR \n";
	resu = uah / rub;
	cout << resu << "\t RUB \n";
}