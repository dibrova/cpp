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

#include<stdio.h>
#include <Windows.h>

struct FILM {
	char*name;
	char*director;
	char*genre;
	double rating;
	double price;
};

struct VIDEOSHOP {
	FILM *film;
};

FILM *incfilm(FILM* film, int &SizeOfBase);
void show_all(FILM* film, int &SizeOfBase, int &check);
void show_some(FILM* film, int position);
void name_search(FILM* film, int SizeOfBase, int &check);
void genre_search(FILM* film, int SizeOfBase, int &check);
void director_search(FILM* film, int SizeOfBase, int &check);
void draw(int &check, char**MENU, int amount_of_menu);
void menu(int &check, char**MENU, int amount_of_menu, VIDEOSHOP* VLD_MOVIE);
void top_rating(FILM* film, int SizeOfBase, int &check);

int SizeOfBase = 0;
HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
void main_16_1() {
	setlocale(0, "");

	system("mode con cols=100 lines=40");

	COORD XY;
	XY.X = 100;
	XY.Y = 300;

	SetConsoleScreenBufferSize(H, XY);

	VIDEOSHOP VLD_MOVIE;
	VLD_MOVIE.film = NULL;

	cout << "Добро пожаловать в базу фильмов видеомагазина \"VLAD'S MOVIE\"!!!" << endl << endl;

	int check = -1;

	int amount_of_menu = 6;
	char** MENU = new char*[amount_of_menu];

	for (int i = 0; i<amount_of_menu; i++) {
		MENU[i] = new char[50];
	}

	MENU[0] = "Добавить фильм";
	MENU[1] = "Отобразить все фильмы";
	MENU[2] = "Поиск по названию";
	MENU[3] = "Поиск по жанру";
	MENU[4] = "Поиск по режиссеру";
	MENU[5] = "10 самых популярных фильмов";

	do {
		menu(check, MENU, amount_of_menu, &VLD_MOVIE);
	} while (check != 0);
}

FILM * incfilm(FILM * film, int &SizeOfBase, int &check) {
	system("cls");

	cin.clear();
	cin.sync();

	SizeOfBase++;

	film = (FILM*)realloc(film, SizeOfBase * sizeof(FILM));

	for (int i = SizeOfBase - 1; i<SizeOfBase; i++) {
		film[i].name = new char[100];
		film[i].director = new char[50];
		film[i].genre = new char[50];
	}

	cout << "Введите название фильма: ";
	gets_s(film[SizeOfBase - 1].name, 100);
	OemToAnsi(film[SizeOfBase - 1].name, film[SizeOfBase - 1].name);
	cout << "Введите жанр фильма: ";
	gets_s(film[SizeOfBase - 1].genre, 50);
	OemToAnsi(film[SizeOfBase - 1].genre, film[SizeOfBase - 1].genre);
	cout << "Введите Ф.И.О. режиссера фильма: ";
	gets_s(film[SizeOfBase - 1].director, 50);
	OemToAnsi(film[SizeOfBase - 1].director, film[SizeOfBase - 1].director);
	cout << "Введите рейтинг фильма: ";
	cin >> film[SizeOfBase - 1].rating;

	if (cin.fail()) {
		cerr << "Введен неправильный тип данных! Операция ввода прервана... (нажмите любую клавишу)" << endl;
		cin.clear();
		cin.sync();
		getch();
		incfilm(film, SizeOfBase, check);
	}

	cout << "Введите цену диска с фильмом: ";
	cin >> film[SizeOfBase - 1].price;

	if (cin.fail()) {
		cerr << "Введен неправильный тип данных! Операция ввода прервана... (нажмите любую клавишу)" << endl;
		cin.clear();
		cin.sync();
		getch();
		incfilm(film, SizeOfBase, check);
	}

	check = -1;
	cout << "Нажмите любую клавишу для возврата в меню...";
	getch();

	return film;
}

void show_all(FILM* film, int &SizeOfBase, int &check) {
	system("cls");
	for (int i = 0; i<SizeOfBase; i++) {
		cout << "Название фильма: ";
		puts(film[i].name);
		cout << "\t" << "Жанр фильма: ";
		puts(film[i].genre);
		cout << "\t" << "Режиссер фильма: ";
		puts(film[i].director);
		cout << "\t" << "Рейтинг фильма - " << film[i].rating << endl;
		cout << "\t" << "Цена диска с фильмом - " << film[i].price << endl;
		cout << endl;
	}

	check = -1;
	cout << "Нажмите любую клавишу для возврата в меню...";
	getch();
}

void show_some(FILM* film, int position) {
	cout << endl;
	cout << "Название фильма: ";
	puts(film[position].name);
	cout << "\t" << "Жанр фильма: ";
	puts(film[position].genre);
	cout << "\t" << "Режиссер фильма: ";
	puts(film[position].director);
	cout << "\t" << "Рейтинг фильма - " << film[position].rating << endl;
	cout << "\t" << "Цена диска с фильмом - " << film[position].price << endl;
}

void name_search(FILM* film, int SizeOfBase, int &check) {
	system("cls");
	char * text = new char[100];
	cout << "Введите имя фильма для поиска: ";

	cin.clear();
	cin.sync();

	gets_s(text, 100);
	OemToAnsi(text, text);

	int kol = 0;

	for (int i = 0; i<SizeOfBase; i++) {
		if (stricmp(film[i].name, text) == 0) {
			show_some(film, i);
			kol += 1;
		}
	}

	if (kol == 0) {
		cout << "По запросу ничего не найдено" << endl;
	}

	cout << endl;

	delete[] text;
	text = NULL;

	check = -1;
	cout << "Нажмите любую клавишу для возврата в меню...";
	getch();
}

void genre_search(FILM* film, int SizeOfBase, int &check) {
	system("cls");
	char * text = new char[100];
	cout << "Введите жанр фильма для поиска: ";

	cin.clear();
	cin.sync();

	gets_s(text, 100);
	OemToAnsi(text, text);

	int kol = 0;

	for (int i = 0; i<SizeOfBase; i++) {
		if (stricmp(film[i].genre, text) == 0) {
			show_some(film, i);
			kol += 1;
		}
	}

	if (kol == 0) {
		cout << "По запросу ничего не найдено" << endl;
	}

	cout << endl;

	delete[] text;
	text = NULL;

	check = -1;
	cout << "Нажмите любую клавишу для возврата в меню...";
	getch();
}

void director_search(FILM* film, int SizeOfBase, int &check) {
	system("cls");
	char * text = new char[100];
	cout << "Введите режиссера фильма для поиска: ";

	cin.clear();
	cin.sync();

	gets_s(text, 100);
	OemToAnsi(text, text);

	int kol = 0;

	for (int i = 0; i<SizeOfBase; i++) {
		if (stricmp(film[i].director, text) == 0) {
			show_some(film, i);
			kol += 1;
		}
	}

	if (kol == 0) {
		cout << "По запросу ничего не найдено" << endl;
	}

	cout << endl;

	delete[] text;
	text = NULL;

	check = -1;
	cout << "Нажмите любую клавишу для возврата в меню...";
	getch();
}

void menu(int &check, char**MENU, int amount_of_menu, VIDEOSHOP* VLD_MOVIE) {
	if (check == -1) {
		check = 1;
		draw(check, MENU, amount_of_menu);
		return;
	}

	int symb;
	symb = getch();

	if (symb == 224) {
		symb = getch();

		if (symb == 72) {
			if (check == 1) {
				check = amount_of_menu;
			}
			else { check -= 1; }
			draw(check, MENU, amount_of_menu);
		}
		else if (symb == 80) {
			if (check == amount_of_menu) {
				check = 1;
			}
			else { check += 1; }
			draw(check, MENU, amount_of_menu);
		}
	}

	else if (symb == 13) {
		if (check == 1) {
			VLD_MOVIE->film = incfilm(VLD_MOVIE->film, SizeOfBase, check);
		}
		else if (check == 2) {
			show_all(VLD_MOVIE->film, SizeOfBase, check);
		}

		else if (check == 3) {
			name_search(VLD_MOVIE->film, SizeOfBase, check);
		}

		else if (check == 4) {
			genre_search(VLD_MOVIE->film, SizeOfBase, check);
		}

		else if (check == 5) {
			director_search(VLD_MOVIE->film, SizeOfBase, check);
		}

		else if (check == 6) {
			top_rating(VLD_MOVIE->film, SizeOfBase, check);
		}

	}
}

void draw(int &check, char** MENU, int amount_of_menu) {
	SetConsoleTextAttribute(H, 15);
	system("cls");

	COORD C;
	C.X = (100 / 2) - 10;
	C.Y = (40 / 2) - 3;

	for (int i = 0; i<amount_of_menu; i++) {
		C.Y += 1;
		SetConsoleCursorPosition(H, C);

		if (check - 1 == i) {
			SetConsoleTextAttribute(H, 207);
		}
		else if (check - 1 != i) {
			SetConsoleTextAttribute(H, 15);
		}

		puts(MENU[i]);
	}
}

void top_rating(FILM* film, int SizeOfBase, int &check) {
	SetConsoleTextAttribute(H, 15);
	system("cls");
	double **rating = new double *[2];

	for (int i = 0; i<2; i++) {
		rating[i] = new double[SizeOfBase];
	}

	for (int i = 0; i<SizeOfBase; i++) {
		rating[0][i] = i;
		rating[1][i] = film[i].rating;
	}

	double tmp;

	for (int i = 0; i<SizeOfBase; i++) {
		for (int j = SizeOfBase - 1; j>i; j--) {
			if (rating[1][j]>rating[1][j - 1]) {
				tmp = rating[1][j];
				rating[1][j] = rating[1][j - 1];
				rating[1][j - 1] = tmp;

				tmp = rating[0][j];
				rating[0][j] = rating[0][j - 1];
				rating[0][j - 1] = tmp;
			}
		}
	}

	for (int i = 0; i<SizeOfBase; i++) {
		show_some(film, rating[0][i]);
	}

	for (int i = 0; i<SizeOfBase; i++) {
		delete[] rating[i];
	}

	delete[] rating;
	rating = NULL;

	cout << endl;
	check = -1;
	cout << "Нажмите любую клавишу для возврата в меню...";
	getch();

}
