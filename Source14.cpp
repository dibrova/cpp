#include <conio.h>  

#include <stdio.h>  
//#include <windows.h>

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;


class TrafficLight
{
public:
	char GetState(time_t FreshTime);
	void SetBaseTime(time_t baseTime);
private:
	int redTime = 2;
	int yellowTime = 4;
	int greenTime = 3;
	int timeLigt = redTime + yellowTime + greenTime;
	time_t BaseTime = time(NULL);
};

char TrafficLight::GetState(time_t FreshTime)
{
	int sec = (FreshTime - BaseTime) % timeLigt;
	if (0 <= sec && sec < redTime)
	{
		return 'r';
	}
	if (redTime <= sec && sec < (redTime + yellowTime))
	{
		if (sec % 2)
		{
			return 'w';
		}
		else
		{
			return 'y';
		}
	}
	if ((redTime + yellowTime) <= sec && sec < timeLigt)
	{
		return 'g';
	}

}

void TrafficLight::SetBaseTime(time_t baseTime)
{
	BaseTime = baseTime;
}

void main()
{
	char key;
	char state = 0;
	time_t nowTime;
	int refreshTime = 1000;
	
	ofstream fout("log_state.txt");

	nowTime = time(NULL);
	fout << "STARTED\t\t" << ctime(&nowTime) << endl;
	
	TrafficLight nTrafficLight;

	_cputs("Press key S to Start");
	do
	{
		key=_getch();
	} while (key != 's' && key != 'S');

	nowTime = time(NULL);
	nTrafficLight.SetBaseTime(nowTime);
	
	do
	{
		while (!_kbhit())
		{
			nowTime = time(NULL);
			system("cls");

			if (nTrafficLight.GetState(nowTime)=='r')
			{
				if (nTrafficLight.GetState(nowTime) != state)
				{
					nowTime = time(NULL);
					fout << "Red on\t\t" << ctime(&nowTime) << endl;
					state = nTrafficLight.GetState(nowTime);
				}
				system("color C");
				_cputs("*****\n*Red*\n*****\n");
			}
			if (nTrafficLight.GetState(nowTime) == 'y')
			{
				if (nTrafficLight.GetState(nowTime) != state)
				{
					nowTime = time(NULL);
					fout << "Yellow on\t" << ctime(&nowTime) << endl;
					state = nTrafficLight.GetState(nowTime);
				}
				system("color E");
				_cputs("\t******\n\tYellow\n\t******\n");
			}
			if (nTrafficLight.GetState(nowTime) == 'w')
			{
				_cputs("\n\n\n");
			}
			if (nTrafficLight.GetState(nowTime) == 'g')
			{
				if (nTrafficLight.GetState(nowTime) != state)
				{
					nowTime = time(NULL);
					fout << "Green on\t" << ctime(&nowTime) << endl;
					state = nTrafficLight.GetState(nowTime);
				}
				system("color A");
				_cputs("\t\t*****\n\t\tGreen\n\t\t*****\n");
			}
			_sleep(refreshTime);
			
		}
		key = _getch();

		if (key == 'p'|| key == 'P')
		{
			nowTime = time(NULL);
			fout << "PAUSE on\t" << ctime(&nowTime) << endl;
			_cputs("Pause, input S or E key: ");

			do
			{
				key = _getch();
				cout << key;
			} while (key != 's' && key != 'S' && key != 'e' && key != 'E');

			nowTime = time(NULL);
			fout << "PAUSE off\t" << ctime(&nowTime) << endl;
			//system("cls");
		}

	} while (key!='e'&&key!='E');


	nowTime = time(NULL);
	fout << "STOPED\t\t" << ctime(&nowTime) << endl;
	fout.close();
}