/*3. —оздать битовое поле дл€ хранени€ времени (часы,
минуты, секунды, миллисекунды). Ќаписать функции
дл€ установки и получени€ времени в(из) битовое(-го)
поле(-€).*/

#include <iostream>
using namespace std;

struct Time
{
	unsigned hour : 5;
	unsigned min : 6;
	unsigned sec : 6;
	unsigned mlsec : 10;
	unsigned long hhmmssmls : 27;
}time;

void set_time(Time &time);
void get_time(Time &time);

void main_17()
{
	set_time(time);
	get_time(time);
}


void set_time(Time & time)
{
	int temp;
	cout << "Input hours 0-23:";
	cin >> temp;
	if (temp < 0 || temp > 23)
	{
		cout << "Error input" << endl;
		return set_time(time);
	}
	else
	{
		time.hour = temp;
		time.hhmmssmls += temp;
	}
	
	cout << "Input minuts 0-59:";
	cin >> temp;
	if (temp < 0 || temp > 59)
	{
		cout << "Error input " << endl;
		return set_time(time);
	}
	else
	{
		time.min = temp;
		time.hhmmssmls = time.hhmmssmls << 6;
		time.hhmmssmls += temp;
	}
	
	cout << "Input seconds 0-59:";
	cin >> temp;
	if (temp < 0 || temp > 59)
	{
		cout << "Error input" << endl;
		return set_time(time);
	}
	else
	{
		time.sec = temp;
		time.hhmmssmls = time.hhmmssmls << 6;
		time.hhmmssmls += temp;
	}

	cout << "Input milliseconds 0-999:";
	cin >> temp;
	if (temp < 0 || temp > 999)
	{
		cout << "Error input" << endl;
		return set_time(time);
	}
	else
	{
		time.mlsec = temp;
		time.hhmmssmls = time.hhmmssmls << 10;
		time.hhmmssmls += temp;
	}

}

void get_time(Time & time)
{
	cout << time.hour << ":" << time.min << ":" << time.sec << ":" << time.mlsec << endl;
	cout << (time.hhmmssmls >> 22) << ":" << (time.hhmmssmls >> 16 & 63) << ":";
	cout << (time.hhmmssmls >> 10 & 63) << ":" << (time.hhmmssmls & 1023) << endl;
}
