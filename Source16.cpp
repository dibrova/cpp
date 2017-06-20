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

#include <iostream>
#include <conio.h>
using namespace std;

struct FILM {
	char *name;
	char *director;
	char *genre;
	int rating;
	int price;
};

struct VIDEOSHOP {
	FILM *film;
};

int SizeShop = 0;

FILM *AddFilm(FILM *film,int &SizeShop)
{
	SizeShop++;
	film = (FILM*) realloc (film, SizeShop * sizeof(FILM));
	
	for (int i = SizeShop - 1; i < SizeShop; i++) 
		{
			film[i].name = new char[100];
			film[i].director = new char[50];
			film[i].genre = new char[50];
		}

	cout << "Films name: ";
	gets_s(film[SizeShop - 1].name, 100);
	cout << "Film ganre: ";
	gets_s(film[SizeShop - 1].genre, 50);
	cout << "Film director: ";
	gets_s(film[SizeShop - 1].director, 50);
	cout << "Rating: ";
	cin >> film[SizeShop - 1].rating;
	cout << "Price: ";
	cin >> film[SizeShop - 1].price;
	return film;
}

void ShowFilm(FILM *film, int &SizeShop)
{
	for (int i = SizeShop - 1; i < SizeShop; i++)
	{
		cout << film[i].name << " ";
		cout << film[i].director << " ";
		cout << film[i].genre << " ";
		cout << film[i].rating << " ";
		cout << film[i].price << " ";
		cout << endl;
	}
}

void ShowFilmS(FILM *film, int &SizeShop)
{
	for (int i = 0; i < SizeShop; i++)
	{
		cout << film[i].name << " ";
		cout << film[i].director << " ";
		cout << film[i].genre << " ";
		cout << film[i].rating << " ";
		cout << film[i].price << " ";
		cout << endl;
	}
}

void main_16()
{

	VIDEOSHOP MyShop;
	MyShop.film = 0;



	cout << "Hello! add films to DB\n";

	
	for (int i = 0; i < 3; i++)	
	{
		MyShop.film = AddFilm(MyShop.film, SizeShop);
	}
	




	cout << endl;
//	ShowFilm(MyShop.film, SizeShop);
//	MyShop.film = AddFilm(MyShop.film, SizeShop);
	cout << endl;
	
	ShowFilmS(MyShop.film, SizeShop);

}

