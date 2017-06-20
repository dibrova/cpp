/*20.1. Цифровой счетчик, это переменная с ограниченным диапазоном. Значение 
которой сбрасывается, когда ее целочисленное значение достигает 
определенного максимума (например, k принимает значения в диапазоне от 0..100). 
В качестве примера такого счетчика можно привести цифровые часы, счетчик километража. 
Опишите класс такого счетчика. Обеспечьте возможность установления максимального 
и минимального значений, увелечения счетчика на 1, возвращения текущего значения. */

#include  <iostream>
using namespace std;

class DigitCount
{
public:
	DigitCount();
	DigitCount(int n_min, int n_max);
	void set_min(int n_min);
	void set_max(int n_max);
	void up_k();
	void show_k();
	~DigitCount();


private:
	int min, max, k;
};

DigitCount::DigitCount()
{
	cout << "DefConstructor\n";
	min = 0;
	max = 10;
	k = 0;
	for (int i = 0; i < 14; i++)
	{
		cout << (char)177;
		_sleep(200);
	}
	cout << endl;
}

DigitCount::DigitCount(int n_min,int n_max)
{
	cout << "ParamConstructor\n";
	min = n_min;
	max = n_max;
	k = n_min;
}

void DigitCount::set_min(int n_min)
{
	min = n_min;
	k = n_min;
}

void DigitCount::set_max(int n_max)
{
	max = n_max;
}

void DigitCount::up_k()
{
	k++;
	if (k == max)
	{
		k = min;
	}
}

void DigitCount::show_k()
{
	cout << min << " << " << k << " << " << max << endl;
}

DigitCount::~DigitCount()
{
	cout << "Destructor\n";
	for (int i = 0; i < 14; i++)
	{
		cout << (char)177;
		_sleep(200);
	}
	cout << endl;
}

void main_20_1()
{
	int min, max;
	char key;
	DigitCount obj;
	cout << "Class Digit Count, input 7 to Help\n";
	do
	{
		cin >> key;
		switch (key)
		{
		case '1':
			cout << "Input min count value:";
			cin >> min;
			obj.set_min(min);
			break;
		case '2':
			cout << "Input max count value:";
			cin >> max;
			obj.set_max(max);
			break;
		case '3':
			obj.up_k();
			break;
		case '4':
			obj.show_k();
			break;
		case '5':
			system("cls");
			break;
		case '6':
			key = 0;
			break;
		case '7':
			cout << endl;
			cout << "1 Set min value\n";
			cout << "2 Set max value\n";
			cout << "3 Increment count\n";
			cout << "4 Show count\n";
			cout << "5 cls\n";
			cout << "6 Exit\n";
			cout << "7 Help\n";
			cout << endl;
			break;
		default:
			cout << "Error chose!\n";
			break;
		}
		
		

	} while (key);
	
}