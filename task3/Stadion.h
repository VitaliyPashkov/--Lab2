#pragma once
#include <string>
class Stadion
{
public:
	Stadion(); // конструктор
	Stadion(std::string name_,
		std::string club_,
		int count_sectors_,
		int capacity_, double attendance); // конструктор с параметрами
	// сеттеры
	void setName(const std::string name); 
	void setClub(const std::string club); 
	void setSectorsCount(int sectors_count); 
	void setCapacity(int capacity); 
	void setAttendance(double attendance); 
	// геттеры
	int getCapacity() const;
	std::string getName() const;
	std::string getClub() const;
	int getSectorsCount() const;
	double getAttendance() const;
	// сериализация / десериализация:
	void serialize() const;
	void serialize(std::string filename);
	void deserialize(std::string filename);

	void printInfo() const; // вывод информации о себе
private:
	std::string name_{ "" }; // название стадиона
	std::string club_{ "" }; // название клуба
	int sectors_count_{ 0 }, capacity_{ 0 }; // количество секторов и вместимость
	double attendance_{ 0 }; // посещаемость
};
