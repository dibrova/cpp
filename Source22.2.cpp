/*22.2. Добавить   в   строковый   класс   функцию,   которая   создает   строку, 
содержащую пересечение двух строк, то есть общие символы для двух строк. 
Например,   результатом   пересечения   строк   "sdqcg"   "rgfas34"   будет   строка
"sg".  Для реализации функции перегрузить оператор * (бинарное умножение). */

#include <iostream>
#include <stdio.h>
using namespace std;

class String
{
public:
	
	String();
	String(int size);
	String(char *n_string);
	void Set(char *n_string);
	void SetStr();
	void Show();
	char* operator*(String &obj);
	~String();
private:
	char * my_string;
	int size;
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

void String::SetStr()
{
	char *buff = new char;
	gets_s(buff, 100);
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

char* String::operator*(String & obj)
{
	char buff[100] = {};
	char * newstr = new char;
	int count = 0, c = 0;
	for (int i = 0; i < strlen(my_string); i++)
	{
		count = 0;
		for (int j= 0; j < strlen(obj.my_string); j++)
		{
			if (my_string[i]==obj.my_string[j])
			{
				count++;
			}
		}
		if (count)
		{
			buff[c] = my_string[i];
			c++;
		}
	}
	//cout << buff;
	strcpy(newstr, buff);
	return newstr;
}

String::~String()
{
	delete[]my_string;
}

void main()
{
	String str1("Heppy Birthday!!!");
	str1.Show();
	String str2("Heppy New Year!!!");
	str2.Show();
	
	cout << str1 * str2 << endl;
}