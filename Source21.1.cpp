/*21.1. Разработать класс Person, который содержит соответствующие члены для хранения:
имени, возраста, пола и телефонного номера. 
Напишите функции-члены, которые смогут изменять эти члены данных 
индивидуально. Напишите функцию-член Person::Print(), которая выводит 
отформатированные данные о человеке.*/


#include <iostream>
using namespace std;

class Person
{
public:
	char *name;
	int age;
	char *sex;
	char *tnumber;
	Person();
	void SetName(char *n_name);
	void SetAge(int n_age);
	void SetSex(char *n_sex);
	void SetTel(char *n_tnumber);
	void Print();
	~Person();

private:

};

Person::Person()
{
	name = new char[20];
	strcpy(name, "defName");
	age = 0;
	sex = new char[20];
	strcpy(sex, "defSex");
	tnumber = new char[20];
	strcpy(tnumber, "+123456789000");
}

void Person::SetName(char *n_name)
{
	strcpy(name, n_name);
}

void Person::SetAge(int n_age)
{
	age = n_age;
}

void Person::SetSex(char * n_sex)
{
	strcpy(sex, n_sex);
}

void Person::SetTel(char * n_tnumber)
{
	strcpy(tnumber, n_tnumber);
}

void Person::Print()
{
	system("cls");
	cout << "Name:\t" << name << endl;
	cout << "Age :\t" << age << endl;
	cout << "Sex :\t" << sex << endl;
	cout << "TNum:\t" << tnumber << endl;
}

Person::~Person()
{
	delete[]name;
	delete[]sex;
	delete[]tnumber;
}

void main_21_1()
{
	Person obj;
	char *buff = new char[20];
	int temp;
	obj.Print();
	cout << "Corect default Name:";
	cin >> buff;
	obj.SetName(buff);
	cout << "Corect default Age:";
	cin >> temp;
	obj.SetAge(temp);
	cout << "Corect default Sex:";
	cin >> buff;
	obj.SetSex(buff);
	cout << "Corect default Tel. Number:";
	cin >> buff;
	obj.SetTel(buff);
	obj.Print();
	delete[]buff;
}