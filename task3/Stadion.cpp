#pragma once
#include "Stadion.h"
#include <iostream>
#include <fstream>

Stadion::Stadion() {} // конструктор
Stadion::Stadion(std::string name, // конструктор с параметрами
	std::string club,
	int sectors_count,
	int capacity, double attendance) : name_(name), club_(club),
	sectors_count_(sectors_count), capacity_(capacity), attendance_(attendance)
{
}
void Stadion::setName(const std::string name) // ниже - реализация сеттеров
{
	name_ = name;
}
void Stadion::setClub(const std::string club)
{
	club_ = club;
}
void Stadion::setAttendance(double attendance)
{
	attendance_ = attendance;
}
void Stadion::setSectorsCount(int sectors_count)
{
	sectors_count_ = sectors_count;
}
void Stadion::setCapacity(int capacity)
{
	capacity_ = capacity;
}
int Stadion::getSectorsCount() const { // реализация геттеров
	return sectors_count_;
}
int Stadion::getCapacity() const {
	return capacity_;
}
std::string Stadion::getName() const {
	return name_;
}
std::string Stadion::getClub() const {
	return club_;
}
double Stadion::getAttendance() const {
	return attendance_;
}
void Stadion::printInfo() const // функция печати в консоль
{
	std::cout << "Name: " << name_ << std::endl;;
	std::cout << "Club: " << club_ << std::endl;
	std::cout << "Sectors count: " << sectors_count_ << std::endl;
	std::cout << "Attendance: " << attendance_ << std::endl;
	std::cout << "Capacity: " << capacity_ << std::endl;
	std::cout << "Average Percent: " << attendance_ / capacity_ * 100 << std::endl << std::endl;

}
void Stadion::serialize(std::string filename = "games.txt") // сериализация
{
	std::ofstream out;          // поток для записи
	out.open(filename, std::ios::app); // окрываем файл для записи
	if (out.is_open())
	{
		out << "name " << name_ << std::endl;;
		out << "club " << club_ << std::endl;
		out << "Sectors count: " << sectors_count_ << std::endl;
		out << "Capacity " << capacity_ << std::endl;
		out << "Attendance " << attendance_ << std::endl;
		out << "fill(%) " << attendance_ / capacity_ * 100 << std::endl << std::endl;

	}
	out.close(); // закрываем
}
void Stadion::serialize() const
{
	std::ofstream out;          
	out.open("games.txt", std::ios::app); 
	if (out.is_open())
	{
		out << "name " << name_ << std::endl;;
		out << "club " << club_ << std::endl;
		out << "Sectors count: " << sectors_count_ << std::endl;
		out << "Capacity " << capacity_ << std::endl;
		out << "Attendance " << attendance_ << std::endl;
		out << "fill(%) " << attendance_ / capacity_ * 100 << std::endl << std::endl;

	}
	out.close(); 
}
void Stadion::deserialize(std::string filename = "games.txt") // десериализация
{
	std::string serializedLine;

	std::ifstream in(filename);
	if (in.is_open())
	{
		while (getline(in, serializedLine))
		{
			std::cout << serializedLine << std::endl;
		}
	}
	in.close();
}
