#include <iostream>
#include <string> // подключаем строки
#include <fstream> // подключаем файлы
#include <regex> // подключаем маски

using namespace std; // используем стандартное пространство имен

int main()
{
	string buffer = ""; // сюда будем класть считанные строки
	string str = ""; // сюда будем класть найденные слова
	ifstream file("C:\\data.txt"); // файл из которого читаем (для линукс путь будет выглядеть по другому)
	std::regex reg("([A-Za-z]+)"); // маска для слова
	std::regex rx("([A-Z][a-z]*)"); // маска для слова с большой буквы
	std::cmatch res;
	while (getline(file, buffer)) { // пока не достигнут конец файла класть очередную строку в переменную
		while (true) {
			std::regex_search(buffer.c_str(), res, reg); // ищем слова
			if (res.size() != 0) { // если слово найдено
				str = res[1]; // копируем его в переменную
				buffer = res.suffix(); // остальной кусок возвращаем в буфер
				std::regex_match(str.c_str(), res, rx); // проверка на наличие большой буквы
				if (res.size() != 0) { // если формат соответствует маске
					std::cout << res[1] << "\n"; // выводим на экран
				}
			}
			else // если слово не найдено
				break; // заканчиваем работу с буфером (Выходим из цикла)
		}
	}
	system("PAUSE");
	file.close(); // обязательно закрываем файл что бы не повредить его
}
