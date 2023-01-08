//Класс СТАДИОН. (Вариант 7)
//Данные: адрес, футбольный клуб, количество секторов, вместимость, посещаемость.
//Создать 2 стадиона в куче и один в стеке.Установить данные первых двух с помощью
//сеттеров, данные третьего установить в конструкторе с параметрами.В главной
//функции проимитировать четыре матча – случайным образом сформировать
//количество пришедших посетителей и просчитать процент заполнения каждого
//стадиона.Вывести информацию о стадионах, отсортировав их в порядке убывания
//среднего процента заполнения за четыре матча.

#include "Stadion.h" // подключения хэдера - нашего класса
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>



void imitateGameAndReturnPercent(Stadion* stadionArr, size_t N) { // функция имитации игр
	srand(unsigned(time(0)));
	for (size_t i = 0; i < N; i++)
	{
		double attendance = 0;
		for (size_t j = 0; j < N; j++)
		{
			attendance += rand() % stadionArr[j].getCapacity() + 300; // псевдорандом :)
		}
		stadionArr[i].setAttendance((int)attendance / N);

	}
}

void sortByAveragePercent(Stadion* stadionArr, size_t N) { // функция сортировки по среднему проценту (убывание)
	Stadion temp;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (stadionArr[j].getAttendance() / stadionArr[j].getCapacity() <
				stadionArr[j + 1].getAttendance() / stadionArr[j + 1].getCapacity()) {
				temp = stadionArr[j];
				stadionArr[j] = stadionArr[j + 1];
				stadionArr[j + 1] = temp;
			}
		}
	}
}

int main() {
	remove("games.txt"); // удаление файла сохранения для последующей его перезаписи
	Stadion* stadionArr = new Stadion[3]; // создание массива стадионов

	//1 стадион - в куче (с сеттерами)
	stadionArr[0].setName("Stadion1");
	stadionArr[0].setClub("Club1");
	stadionArr[0].setCapacity(4000);
	stadionArr[0].setSectorsCount(5);

	//2 стадион - в куче (с сеттерами)
	stadionArr[1].setName("Stadion2");
	stadionArr[1].setClub("Club2");
	stadionArr[1].setCapacity(5000);
	stadionArr[1].setSectorsCount(6);

	//3 стадион - в стеке (по параметрам)
	Stadion s3 = Stadion((std::string)"stadion3", (std::string)"club3", 7, 3500, 0);
	stadionArr[2] = s3;

	imitateGameAndReturnPercent(stadionArr, 3);
	sortByAveragePercent(stadionArr, 3);

	for (size_t i = 0; i < 3; i++) { // вывод и запись в файл трех игр и информации о них
		stadionArr[i].printInfo();
		stadionArr[i].serialize();
	}

	return 0;
}
