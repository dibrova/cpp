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

	cout << "Äîáðî ïîæàëîâàòü â áàçó ôèëüìîâ âèäåîìàãàçèíà \"VLAD'S MOVIE\"!!!" << endl << endl;

	int check = -1;

	int amount_of_menu = 6;
	char** MENU = new char*[amount_of_menu];

	for (int i = 0; i<amount_of_menu; i++) {
		MENU[i] = new char[50];
	}

	MENU[0] = "Äîáàâèòü ôèëüì";
	MENU[1] = "Îòîáðàçèòü âñå ôèëüìû";
	MENU[2] = "Ïîèñê ïî íàçâàíèþ";
	MENU[3] = "Ïîèñê ïî æàíðó";
	MENU[4] = "Ïîèñê ïî ðåæèññåðó";
	MENU[5] = "10 ñàìûõ ïîïóëÿðíûõ ôèëüìîâ";

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

	cout << "Ââåäèòå íàçâàíèå ôèëüìà: ";
	gets_s(film[SizeOfBase - 1].name, 100);
	OemToAnsi(film[SizeOfBase - 1].name, film[SizeOfBase - 1].name);
	cout << "Ââåäèòå æàíð ôèëüìà: ";
	gets_s(film[SizeOfBase - 1].genre, 50);
	OemToAnsi(film[SizeOfBase - 1].genre, film[SizeOfBase - 1].genre);
	cout << "Ââåäèòå Ô.È.Î. ðåæèññåðà ôèëüìà: ";
	gets_s(film[SizeOfBase - 1].director, 50);
	OemToAnsi(film[SizeOfBase - 1].director, film[SizeOfBase - 1].director);
	cout << "Ââåäèòå ðåéòèíã ôèëüìà: ";
	cin >> film[SizeOfBase - 1].rating;

	if (cin.fail()) {
		cerr << "Ââåäåí íåïðàâèëüíûé òèï äàííûõ! Îïåðàöèÿ ââîäà ïðåðâàíà... (íàæìèòå ëþáóþ êëàâèøó)" << endl;
		cin.clear();
		cin.sync();
		getch();
		incfilm(film, SizeOfBase, check);
	}

	cout << "Ââåäèòå öåíó äèñêà ñ ôèëüìîì: ";
	cin >> film[SizeOfBase - 1].price;

	if (cin.fail()) {
		cerr << "Ââåäåí íåïðàâèëüíûé òèï äàííûõ! Îïåðàöèÿ ââîäà ïðåðâàíà... (íàæìèòå ëþáóþ êëàâèøó)" << endl;
		cin.clear();
		cin.sync();
		getch();
		incfilm(film, SizeOfBase, check);
	}

	check = -1;
	cout << "Íàæìèòå ëþáóþ êëàâèøó äëÿ âîçâðàòà â ìåíþ...";
	getch();

	return film;
}

void show_all(FILM* film, int &SizeOfBase, int &check) {
	system("cls");
	for (int i = 0; i<SizeOfBase; i++) {
		cout << "Íàçâàíèå ôèëüìà: ";
		puts(film[i].name);
		cout << "\t" << "Æàíð ôèëüìà: ";
		puts(film[i].genre);
		cout << "\t" << "Ðåæèññåð ôèëüìà: ";
		puts(film[i].director);
		cout << "\t" << "Ðåéòèíã ôèëüìà - " << film[i].rating << endl;
		cout << "\t" << "Öåíà äèñêà ñ ôèëüìîì - " << film[i].price << endl;
		cout << endl;
	}

	check = -1;
	cout << "Íàæìèòå ëþáóþ êëàâèøó äëÿ âîçâðàòà â ìåíþ...";
	getch();
}

void show_some(FILM* film, int position) {
	cout << endl;
	cout << "Íàçâàíèå ôèëüìà: ";
	puts(film[position].name);
	cout << "\t" << "Æàíð ôèëüìà: ";
	puts(film[position].genre);
	cout << "\t" << "Ðåæèññåð ôèëüìà: ";
	puts(film[position].director);
	cout << "\t" << "Ðåéòèíã ôèëüìà - " << film[position].rating << endl;
	cout << "\t" << "Öåíà äèñêà ñ ôèëüìîì - " << film[position].price << endl;
}

void name_search(FILM* film, int SizeOfBase, int &check) {
	system("cls");
	char * text = new char[100];
	cout << "Ââåäèòå èìÿ ôèëüìà äëÿ ïîèñêà: ";

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
		cout << "Ïî çàïðîñó íè÷åãî íå íàéäåíî" << endl;
	}

	cout << endl;

	delete[] text;
	text = NULL;

	check = -1;
	cout << "Íàæìèòå ëþáóþ êëàâèøó äëÿ âîçâðàòà â ìåíþ...";
	getch();
}

void genre_search(FILM* film, int SizeOfBase, int &check) {
	system("cls");
	char * text = new char[100];
	cout << "Ââåäèòå æàíð ôèëüìà äëÿ ïîèñêà: ";

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
		cout << "Ïî çàïðîñó íè÷åãî íå íàéäåíî" << endl;
	}

	cout << endl;

	delete[] text;
	text = NULL;

	check = -1;
	cout << "Íàæìèòå ëþáóþ êëàâèøó äëÿ âîçâðàòà â ìåíþ...";
	getch();
}

void director_search(FILM* film, int SizeOfBase, int &check) {
	system("cls");
	char * text = new char[100];
	cout << "Ââåäèòå ðåæèññåðà ôèëüìà äëÿ ïîèñêà: ";

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
		cout << "Ïî çàïðîñó íè÷åãî íå íàéäåíî" << endl;
	}

	cout << endl;

	delete[] text;
	text = NULL;

	check = -1;
	cout << "Íàæìèòå ëþáóþ êëàâèøó äëÿ âîçâðàòà â ìåíþ...";
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
	cout << "Íàæìèòå ëþáóþ êëàâèøó äëÿ âîçâðàòà â ìåíþ...";
	getch();

}
