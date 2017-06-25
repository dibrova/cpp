/*14.3. Удалить с m по n символов, перезаписать строку и
показать ее на экран.*/

#include <stdlib.h>
#include <iostream>
using namespace std;

void main_14_3()
{
	int m, n;
	char string[] = "Hello world! 2016 - 2017";
	cout << string << endl;
	cout << "Input number position from and to cut string (m n): ";
	cin >> m >> n;

	for (; string[n] != '\0'; n++ , m++)
	{
		string[m] = string[n];
	}
		
	string[m] = NULL;

	cout << string << endl;

}
