/*21.2. –азработать класс String, который в дальнейшем будет использоватьс€ дл€
работы со строками.  ласс должен содержать:
конструктор по умолчанию, позвол€ющий создать строку длиной 80 символов;
конструктор, позвол€ющий создавать строку произвольного размера;
конструктор, который создаЄт строку и инициализирует еЄ строкой, полученной от пользовател€.
 ласс должен содержать методы дл€ ввода строк с клавиатуры и вывода строк на экран.*/

#include <iostream>
#include <stdio.h>
using namespace std;

class String
{
public:
	char * my_string;
	int size;
	String();
	String(int size);
	String(char *n_string);
	void Set(char *n_string);
	void GetStr();
	void Show();
	~String();
};

String::String()
{
	my_string = new char[80];
}

String::String(int size)
{
	my_string = new char[size];
}

String::String(char * n_string)
{
	my_string = new char[strlen(n_string) + 1];
	strcpy(my_string, n_string);
}

void String::Set(char * n_string)
{
	if (strlen(my_string) >= strlen(n_string))
	{
		strcpy(my_string, n_string);
	}
	else
	{
		delete[]my_string;
		my_string = new char[strlen(n_string) + 1];
		strcpy(my_string, n_string);
	}
	
}

void String::GetStr()
{
	char *buff = new char;
	gets_s(buff,100);
	if (strlen(my_string) >= strlen(buff))
	{
		strcpy(my_string, buff);
	}
	else
	{
		delete[]my_string;
		my_string = new char[strlen(buff) + 1];
		strcpy(my_string, buff);
	}
	buff = NULL;
	delete[]buff;
}

void String::Show()
{
	cout << my_string << endl;
}

String::~String()
{
	delete[]my_string;
}

void main_21_2()
{
	String str("Heppy Birthday!!!");
	str.Show();
	str.GetStr();
	str.Show();
}