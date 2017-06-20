/*16.11. Создать структуру ВИДЕОМАГАЗИН со следующими полями:
- Название фильма
- Режиссер
- Жанр
- Рейтинг популярности
- Цена диска
Реализовать следующие возможности:
- Поиск по названию
- Поиск по жанру
- Поиск по режиссеру
- Самый популярный фильм в жанре
- Показ всех записей и добавление*/

#include <stdlib.h>
#include <iostream>
#include <conio.h>
using namespace std;

struct video_film {
	char *name;
	char *director;
	char *genre;
	double rating;
	double price;
};

int base_size = 0;

void add_new_film(video_film *arr);
void show_base(video_film *arr);

void search_name(video_film *arr);
void search_genre(video_film *arr);
void search_director(video_film *arr);
void search_pop(video_film *arr);
void show_one(video_film *arr, int i);

void main_()
{

	video_film *video_base = new video_film[100];
	//video_base = NULL;
	char key;

	video_base[0] = { "The Girl on the Train", "Tate Taylor", "Mystery", 6.7, 5 };
	video_base[1] = { "Deepwater Horizon", "Peter Berg", "Action", 7.6, 5 };
	video_base[2] = { "The Magnificent Seven", "Antoine Fuqua", "Action", 7.1, 5 };
	video_base[3] = { "Snowden", "Oliver Stone", "Drama", 7.4, 5 };
	video_base[4] = { "Sully", "Clint Eastwood", "Drama", 7.9, 5 };
	video_base[5] = { "Don't Breathe", "Fede Alvarez", "Horror", 7.5, 5 };
	video_base[6] = { "The Shallows", "Anthony Jaswinski", "Horror", 7.4, 5 };
	video_base[7] = { "Lights Out", "David F. Sandberg", "Horror", 7.4, 5 };
	video_base[8] = { "Suicide Squad", "David Ayer", "Action", 6.6, 5 };

	base_size = 9;
	
	
	do
	{
		cout << endl;
		cout << "Menu video shop :\n";
		cout << "1 Search Name\n";
		cout << "2 Search Genre\n";
		cout << "3 Search Director\n";
		cout << "4 Search POP in Ganre\n";
		cout << "5 Show Base\n";
		cout << "6 Add new Film\n";
		cout << "7 cls\n";
		cout << "8 Exit\n";
		key = _getch();
		cout << endl;

		switch (key) 
		{
		case '1':
			search_name(video_base);
			break;
		case '2':
			search_genre(video_base);
			break;
		case '3':
			search_director(video_base);
			break;
		case '4':
			search_pop(video_base);
			break;
		case '5':
			show_base(video_base);
			break;
		case '6':
			add_new_film(video_base);
			break;
		case '7':
			system("cls");
			break;
		case '8':
			key = 0;
			break;
		default:
			cout << "Error chose!\n";
			break;
		}

	} while (key);
	
	delete[]video_base;
	video_base = nullptr;

}

void add_new_film(video_film * arr)
{
	

	int i = base_size;
	base_size++;
	arr[i].name = new char[100];
	arr[i].director = new char[50];
	arr[i].genre = new char[50];
	cout << "Film name: ";
	gets_s(arr[i].name, 99);
	//cin.get(arr[i].name, 100);
	cout << "Film ganre: ";
	gets_s(arr[i].genre, 49);
	//cin.get(arr[i].genre, 50);

	cout << "Film director: ";
	gets_s(arr[i].director, 49);
	//cin.get(arr[i].director, 50);

	cout << "Rating: ";
	cin >> arr[i].rating;
	
	cout << "Price: ";
	cin >> arr[i].price;
	
	cin.clear();
	cin.sync();
}

void show_base(video_film * arr)
{
	for (int i = 0; i < base_size; i++)
	{
		show_one(arr, i);
	}
}

void show_one(video_film * arr, int i)
{
	cout << "Name: " << arr[i].name << "\n";
	cout << "Director: " << arr[i].director << "\n";
	cout << "Ganre: " << arr[i].genre << "\n";
	cout << "Rate: " << arr[i].rating << "\n";
	cout << "Prise: " << arr[i].price << "\n\n";
}
void search_name(video_film *arr)
{
	char temp[100];
	bool err = 0;
	cout << "Input name film for search: ";
	gets_s(temp, 99);
	for (int i = 0; i < base_size; i++)
	{
		if (_stricmp(temp, arr[i].name) == 0) {
			show_one(arr, i);
			err = 1;
		}
	}
	if (!err)
	{
		cout << "Sorry, film not found...\n\n";
	}
}

void search_genre(video_film * arr)
{
	char temp[50];
	bool err = 0;
	cout << "Input ganre film for search: ";
	gets_s(temp, 49);
	for (int i = 0; i < base_size; i++)
	{
		if (_stricmp(temp, arr[i].genre) == 0) 
		{
			show_one(arr, i);
			err = 1;
		}
	}
	if (!err)
	{
		cout << "Sorry, ganre not found...\n\n";
	}
}

void search_director(video_film * arr)
{
	char temp[50];
	bool err = 0;
	cout << "Input director film for search: ";
	gets_s(temp, 49);
	for (int i = 0; i < base_size; i++)
	{
		if (_stricmp(temp, arr[i].director) == 0) 
		{
			show_one(arr, i);
			err = 1;
		}
	}
	if (!err)
	{
		cout << "Sorry, director not found...\n\n";
	}
}

void search_pop(video_film * arr)
{
	char temp[50];
	double pop = 0;
	cout << "Input ganre film for search pop: ";
	gets_s(temp, 49);
	for (int i = 0; i < base_size; i++)	{
		if (_stricmp(temp, arr[i].genre) == 0) 
		{
			if (pop < arr[i].rating) 
			{
				pop = arr[i].rating;
			}
		}
		
	}

	if (!pop)
	{
		cout << "Sorry, ganre not found...\n\n";
	}
	else
	{
		for (int i = 0; i < base_size; i++)	
		{
			if (pop == arr[i].rating)
			{
				show_one(arr, i);
			}
		}
	}
}
