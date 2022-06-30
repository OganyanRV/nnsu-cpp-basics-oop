#pragma once
using namespace std;
class Date {
private:
	int day;
	int month;
	int year;
	int hour;
	int degree;
public:
	// Конструкторы и деструктор
	Date();
	Date(int, int, int, int, int);
	~Date();
	// Геттеры
	int GetDay();
	int GetMonth();
	int GetYear();
	int  GetTemperatureInfo();
	int GetSeniorHours();
	//Совпадает ли дата и время
	bool TemperatureInfo(Date);
	// Совпадает ли дата  ( оба метода делают одно и то же)
	bool TemperatureDateInfo(Date);
	bool DateDayinfo(int, int, int);
	// Совпадает ли месяц
	bool MonthInfo(int);
	// Перегрузка потока
	friend ostream & operator << (ostream & stream, const Date &_date);
	friend istream & operator >> (istream & stream, Date &_date);
};