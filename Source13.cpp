#include <conio.h>  

#include <stdio.h>  
//#include <windows.h>

#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;


void main_TL()
{
	char key;
	time_t seconds = time(NULL);
	ofstream fout("log_state.txt");
	fout << "STARTED\t\t" << ctime(&seconds) << endl;
		
	do
	{
		while (!_kbhit())
		{
			seconds = time(NULL);
			fout << "Red on\t\t" << ctime(&seconds) << endl;
						
			system("color C");
			_cputs("*****\n*Red*\n*****\n");
			_sleep(2000);

			seconds = time(NULL);
			fout << "Red off\t\t" << ctime(&seconds) << endl;
			
			system("cls");
			system("color E");

			seconds = time(NULL);
			fout << "Yellow on\t" << ctime(&seconds) << endl;

			_cputs("\t******\n\tYellow\n\t******\n");
			_sleep(800);
			system("cls");
			_cputs(" \n");
			_sleep(800);
			system("cls");
			_cputs("\t******\n\tYellow\n\t******\n");
			_sleep(800);
			system("cls");
			_cputs(" \n");
			_sleep(800);
			system("cls");
			_cputs("\t******\n\tYellow\n\t******\n");
			_sleep(800);

			seconds = time(NULL);
			fout << "Yellow off\t" << ctime(&seconds) << endl;

			system("cls");
			system("color A");

			seconds = time(NULL);
			fout << "Green on\t" << ctime(&seconds) << endl;

			_cputs("\t\t*****\n\t\tGreen\n\t\t*****\n");
			_sleep(4000);

			seconds = time(NULL);
			fout << "Green off\t" << ctime(&seconds) << endl;

			system("cls");
		}
		key = _getch();
		if (key == 'p' && key == 'P')
		{
			system("color E");

			seconds = time(NULL);
			fout << "PAUSE on\t" << ctime(&seconds) << endl;
					
			_cputs("\t******\n\tYellow\n\t******\n");
			_cputs("Pause, input s or e key: ");
			
			do
			{
				key = _getch();
				cout << key;
			} while (key != 's' && key != 'e');

			system("cls");

			seconds = time(NULL);
			fout << "PAUSE off\t" << ctime(&seconds) << endl;
		}
		
	} while (key != 'e'&& key != 'E');

	seconds = time(NULL);
	fout << "STOPED\t\t" << ctime(&seconds) << endl;
	fout.close();

}