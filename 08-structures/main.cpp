//#include "stdafx.h"
//#include "pch.h"
#include <iostream>
#include <string> // подключаем строки

using namespace std; // используем стандартное пространство имен

struct MARSH // структура
{
	string nachPunkt, konechPunkt; // название начального пункта и пункта конца
	int number; // номер маршрута
};

int main()
{
	MARSH listMarsh[8]; // массив маршрутов
	for (int i = 0; i < 8; i++) { // далее заполнение маршрута
		cout << "vvedite nachPunkt dla stancii #" << i + 1 << "\n";
		cin >> listMarsh[i].nachPunkt;
		cout << "vvedite konechPunkt dla stancii #" << i + 1 << "\n";
		cin >> listMarsh[i].konechPunkt;
		cout << "vvedite number dla stancii #" << i + 1 << "\n";
		cin >> listMarsh[i].number;
	}
	for (int i = 0; i < 8; i++) { // сортировка маршрутов по номеру
		for (int j = 1; j < 8 - i; j++) {
			if (listMarsh[j - 1].number > listMarsh[j].number) {
				MARSH marshCup;
				marshCup = listMarsh[j - 1];
				listMarsh[j - 1] = listMarsh[j];
				listMarsh[j] = marshCup;
			}
		}
	}
	for (int i = 0; i < 8; i++) { // вывод маршрутов на экран
		cout << i + 1 << ")nachPunkt = " << listMarsh[i].nachPunkt;
		cout << " ; konechPunkt = " << listMarsh[i].konechPunkt;
		cout << " ; number = " << listMarsh[i].number << "\n";
	}
	cout << "Vvedite nomer marshruta" << "\n";
	int number; // введённый номер
	cin >> number;
	bool naiden = false; // переменная отвечающая за нахождение маршрута
	for (int i = 0; i < 8; i++) {
		if (number == listMarsh[i].number) {
			naiden = true; // значение Правда если маршрут найден и вводим его на экран
			cout << i + 1 << ")nachPunkt = " << listMarsh[i].nachPunkt;
			cout << " ; konechPunkt = " << listMarsh[i].konechPunkt;
			cout << " ; number = " << listMarsh[i].number << "\n";
		}
	}
	if (!naiden) // если маршрут не найден выводится сообщение
		cout << "Marshrut ne naiden \n";
}
