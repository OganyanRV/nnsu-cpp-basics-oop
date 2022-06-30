#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Date.h"
#include "Thermometer.h"

using namespace std;
Date::Date() {
	day = month = year = hour = degree = 0;
}
Date::Date(int _day, int _month, int _year, int _hour, int _degree) {
	day = _day;
	month = _month;
	year = _year;
	hour = _hour;
	degree = _degree;
}
Date::~Date() {
	day = month = year = hour = degree = 0;
}
int Date::GetDay() {
	return day;
}
int Date::GetMonth() {
	return month;
}
int Date::GetYear() {
	return year;
}
bool Date::TemperatureInfo(Date _date)
{
	if (day == _date.day && month == _date.month && year == _date.year && hour == _date.hour)
		return true;
	return false;
}
int Date::GetTemperatureInfo() {
	return degree;
}
int Date::GetSeniorHours() {
	return hour;
}
bool Date::DateDayinfo(int _day, int _month, int _year) {
	if (day == _day && month == _month && year == _year)
		return true;
	return false;
}
bool Date::TemperatureDateInfo(Date _date)
{
	if (day == _date.day && month == _date.month && year == _date.year)
		return true;
	return false;
}
bool Date::MonthInfo(int _month) {
	if (_month == month) return true;
	return false;
}
istream & operator >> (istream & stream, Date &_date) {
	stream >> _date.day >> _date.month >> _date.year >> _date.hour >> _date.degree;
	return stream;
}
ostream & operator << (ostream & stream, const Date &_date) {
	stream << " " << _date.day << " " << _date.month << " " << _date.year << " " << _date.hour << " " << _date.degree;
	return stream;
}
