/*22.1. Создайте класс Date, который будет содержать информацию о дате (день,
месяц, год). С помощью механизма перегрузки операторов, определите
операцию разности двух дат (результат в виде количества дней между
датами), а также операцию увеличения даты на определенное количество дней.
*/

#include <iostream>
#include <ctime>
using namespace std;

class Date
{
public:
	Date();
	Date(int Day, int Month, int Year);
	void SetDate(int Day, int Month, int Year);
	void ShowDate();
	int  GetDays();
	int operator - (Date &obj);
	void operator + (int Days);
	~Date();

private:
	time_t rawtime;
	struct tm *timeinfo = new struct tm();
	
};

Date::Date()
{
	
}

Date::Date(int Day, int Month, int Year)
{
	timeinfo->tm_mday = Day;
	timeinfo->tm_mon = Month - 1;
	timeinfo->tm_year = Year - 1900;
}

void Date::SetDate(int Day, int Month, int Year)
{
	timeinfo->tm_mday = Day;
	timeinfo->tm_mon = Month - 1;
	timeinfo->tm_year = Year - 1900;
}

void Date::ShowDate()
{
	cout << asctime(timeinfo);
}

int Date::GetDays()
{
	return mktime(timeinfo) / 60 / 60 / 24;
}

int Date::operator-(Date & obj)
{
	return GetDays() - obj.GetDays();
}

void Date::operator+(int Days)
{
	rawtime = (GetDays() + Days + 1) * 24 * 60 * 60 ;
	timeinfo = gmtime(&rawtime);
}

Date::~Date()
{
	timeinfo = NULL;
	delete timeinfo;
}

void main_()
{
	Date obj1(10, 11, 2016);
	
	Date obj2(01, 12, 2016);
	
	obj2.ShowDate();
	cout << "-\n";
	obj1.ShowDate();

	cout << "= " << obj2 - obj1 << endl;

	obj1.ShowDate();
	cout << " + 7 day = \n";
	obj1 + 7;
	obj1.ShowDate();
	cout << " + 13 day = \n";
	obj1 + 13;
	obj1.ShowDate();
	cout << " + 5 day = \n";
	obj1 + 5;
	obj1.ShowDate();

	cout << "-\n";
	obj2.ShowDate();
	
	cout << "= " << obj1 - obj2 << endl;


}
