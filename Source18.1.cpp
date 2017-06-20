/*18.Записная книжка: имя,фамилия,телефон,адрес,возраст. Поиск по имени, телефону
с маской (???*). Загузка и выгрузка книжки в файл.*/

#include <fstream>
#include  <iostream>
using namespace std;

struct record
{
	char f_name[20];
	char s_name[20];
	char t_number[20];
	char address[20];
	char age[10];
};


void show_one(record ** arr, int i);
void show_all(record ** arr, int & rec_count);
void search_f_name(record **arr, int & rec_count);
void search_t_number(record **arr, int & rec_count);
void addRecord(record ** &arr, int & size, int & rec_count);
void delRecord(record ** &arr, int & rec_count);
void edtRecord(record ** arr);
void wrFile(record ** arr, int & rec_count);
void rdFile(record ** &arr, int & size, int & rec_count);


void main()
{
	int size = 5;
	int rec_count = 0;
	//record *NoteBook = new record[size];
	record **arr_ptr = new record*[size];


	char key;
	do
	{
		cout << endl;
		cout << "Menu NoteBook :\n";
		cout << "1 Search Name\n";
		cout << "2 Search Phone\n";
		cout << "3 Add Record\n";
		cout << "4 Edit Record\n";
		cout << "5 Delete Record\n";
		cout << "6 Read from file\n";
		cout << "7 Write to file\n";
		cout << "8 cls\n";
		cout << "9 Exit\n";
		cin >> key;
		cout << endl;

		switch (key)
		{
		case '1':
			search_f_name(arr_ptr, rec_count);
			break;
		case '2':
			search_t_number(arr_ptr, rec_count);
			break;
		case '3':
			addRecord(arr_ptr, size, rec_count);
			break;
		case '4':
			edtRecord(arr_ptr);
			break;
		case '5':
			delRecord(arr_ptr, rec_count);
			break;
		case '6':
			rdFile(arr_ptr, size, rec_count);
			break;
		case '7':
			wrFile(arr_ptr, rec_count);
			break;
		case '8':
			system("cls");
			show_all(arr_ptr, rec_count);
			break;
		case '9':
			key = 0;
			break;
		default:
			cout << "Error chose!\n";
			break;
		}

	} while (key);

	//delete[]NoteBook;
	delete[]arr_ptr;
}

void addRecord(record ** &arr, int & size, int & rec_count)
{
	if (size == rec_count)
	{
		//*arr = (record*)realloc(*arr, (size + 5) * sizeof(record));
		record **temp = new record*[size + 5];
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
		size += 5;
	}

	cout << "New record: ";
	arr[rec_count] = new record;
	cin >> arr[rec_count]->f_name;
	cin >> arr[rec_count]->s_name;
	cin >> arr[rec_count]->t_number;
	cin >> arr[rec_count]->address;
	cin >> arr[rec_count]->age;
	show_one(arr, rec_count);
	rec_count++;
}

void show_one(record ** arr, int i)
{
	cout << arr[i]->f_name << " " << arr[i]->s_name << " " << arr[i]->t_number << " " << arr[i]->address << " " << arr[i]->age << endl;
}

void show_all(record ** arr, int & rec_count)
{
	for (int j = 0; j < rec_count; j++)
	{
		show_one(arr, j);
	}
}

void search_f_name(record ** arr, int & rec_count)
{
	char temp[20];
	bool err = 0;
	cout << "Input name for search: ";
	cin >> temp;

	for (int i = 0; i < rec_count; i++)
	{
		for (unsigned int j = 0; j < strlen(temp); j++)
		{
			if (temp[j] == arr[i]->f_name[j] || toupper(temp[j]) == arr[i]->f_name[j])
			{
				if (temp[j + 1] == '\0' && arr[i]->f_name[j + 1] == '\0')
				{
					show_one(arr, i);
					err = 1;
					break;
				}
				continue;
			}
			else if (temp[j] == '?')
			{
				if (temp[j + 1] == '\0')
				{
					show_one(arr, i);
					err = 1;
					break;
				}
				continue;
			}
			else if (temp[j] == '*')
			{
				show_one(arr, i);
				err = 1;
				break;
			}
			else
			{
				break;
			}
		}
	}
	if (!err)
	{
		cout << "Sorry, name not found...\n\n";
	}
}

void search_t_number(record ** arr, int & rec_count)
{
	char temp[20];
	bool err = 0;
	cout << "Input name for search: ";
	cin >> temp;
	for (int i = 0; i < rec_count; i++)
	{
		for (unsigned int j = 0; j < strlen(temp); j++)
		{
			if (temp[j] == arr[i]->t_number[j] || toupper(temp[j]) == arr[i]->t_number[j])
			{
				if (temp[j + 1] == '\0' && arr[i]->t_number[j + 1] == '\0')
				{
					show_one(arr, i);
					err = 1;
					break;
				}
				continue;
			}
			else if (temp[j] == '?')
			{
				if (temp[j + 1] == '\0')
				{
					show_one(arr, i);
					err = 1;
					break;
				}
				continue;
			}
			else if (temp[j] == '*')
			{
				show_one(arr, i);
				err = 1;
				break;
			}
			else
			{
				break;
			}
		}
	}
	if (!err)
	{
		cout << "Sorry, name not found...\n\n";
	}
}

void delRecord(record ** &arr, int & rec_count)
{
	int i;
	cout << "Input index deleted record: ";
	cin >> i;
	for (i; i < rec_count; i++)
	{
		arr[i] = arr[i + 1];
	}
	rec_count--;
	cout << "Delete complete..." << endl;
}

void edtRecord(record ** arr)
{
	int i;
	cout << "Enter index of record for editing: ";
	cin >> i;
	show_one(arr, i);
	cout << "Input new data:\n";
	cin >> arr[i]->f_name;
	cin >> arr[i]->s_name;
	cin >> arr[i]->t_number;
	cin >> arr[i]->address;
	cin >> arr[i]->age;

}

void wrFile(record ** arr, int & rec_count)
{
	ofstream fout("cppstudio1.txt");
	for (int i = 0; i < rec_count; i++)
	{
		fout << arr[i]->f_name << " " << arr[i]->s_name << " " << arr[i]->t_number << " " << arr[i]->address << " " << arr[i]->age << endl;
	}
	fout.close();
	cout << "Write to file complete..." << endl;
}

void rdFile(record ** &arr, int & size, int & rec_count)
{
	ifstream fin("cppstudio.txt");

	for (int j = 0; j <= size; j++)
	{
		if (size == rec_count)
		{
			//*arr = (record*)realloc(*arr, (size + 5) * sizeof(record));
			record **temp = new record*[size + 5];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = temp;
			size += 5;
		}
		if (fin.eof())
		{
			break;
		}
		arr[rec_count] = new record;
		fin >> arr[rec_count]->f_name;
		fin >> arr[rec_count]->s_name;
		fin >> arr[rec_count]->t_number;
		fin >> arr[rec_count]->address;
		fin >> arr[rec_count]->age;
		rec_count++;
	}
	fin.close();
	cout << "Reading from file complete..." << endl;
}