/*20.2. Написать класс, описывающий группу студентов. 
Студент также реализуется с помощью соответствующего класса. */

#include  <iostream>
using namespace std;

class StudClass
{
public:
	char *f_name;
	char *s_name;
	StudClass()
	{
		f_name = new char[20];
		s_name = new char[20];
		cout << "Construct Student\n";
	}
	~StudClass()
	{
		delete[]f_name;
		delete[]s_name;
		cout << "Destruct user\n";
	}
};

class GroupClass
{
public:
	char *g_name;
	int g_size;
	StudClass *g_stud;

	GroupClass(char *name, int size)
	{
		g_name = new char[10];
		g_size = size;
		g_stud = new StudClass[g_size];
		strcpy(g_name, name);
		cout << "Consrtuct Goup\n";
		
	}
	
	~GroupClass()
	{
		delete[]g_stud;
		delete[]g_name;
		cout << "Destruct Group\n";
	}
};



void main_20_2()
{
	GroupClass groupe("GROUP",10);
}