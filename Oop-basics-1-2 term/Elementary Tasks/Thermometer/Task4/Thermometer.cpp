#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Date.h"
#include "Thermometer.h"
using namespace std;

Thermometer::Thermometer()
{
	arr = nullptr;
	size = 0;
	buf = 0;
}			
Thermometer::Thermometer(Date _date, int _size)
{
	size = _size;
	buf = _size + zapas;
	arr = new Date[buf];
}
Thermometer::~Thermometer() {
	size = 0;
	buf = 0;
	delete[] arr;
	arr = nullptr;
}
Date Thermometer::GetStartInfo() { //1)
	return arr[0];
}
int Thermometer::GetTemperature(Date _date) { //3
	bool f = true;
	int i = 0;
	int tmp;
	while (f && i < size) {
		if (arr[i].TemperatureInfo(_date) == true) {
			f = false;
			tmp = arr[i].GetTemperatureInfo();
		}
		else i++;
	}
	if (!f) return tmp;
	return NULL;
}
void Thermometer::Screenoutfordate(Date _date) { //4
	bool f = true;
	int i = 0;
	int tmp;
	cout << "Серия наблюдений для " << _date.GetDay() << "." << _date.GetMonth() << "." << _date.GetYear() << endl;
	while (i < size) {
		if (arr[i].TemperatureDateInfo(_date) == true) {
			f = false;
			cout << "Часы: " << arr[i].GetSeniorHours() << ". Температура: " << arr[i].GetTemperatureInfo() << endl;
		}
		i++;
	}
	if (f == false) return;
	else cout << " Не существует" << endl;


}
int Thermometer::AverageTempbyDate(Date _day) { //5.1
	bool f = true;
	int i = 0;
	int k = 0;
	double tmp = 0;
	while (i < size) {
		if (arr[i].DateDayinfo(_day.GetDay(), _day.GetMonth(), _day.GetYear()) == true) {
			tmp += arr[i].GetTemperatureInfo();
			k++;
			f = false;
		}
		i++;
	}
	if (!f) return tmp / k;
	return NULL;
}
int Thermometer::AverageTempbyMonth(int _month) { //5.2
	bool f = true;
	int i = 0;
	double tmp = 0;
	int k = 0;
	while (i < size) {
		if (arr[i].MonthInfo(_month) == true) {
			tmp += arr[i].GetTemperatureInfo();
			f = false;
			k++;
		}
		i++;
	}
	if (!f) return tmp / k;
	return NULL;
}
int Thermometer::Tempall() {
	double tmp = 0;
	int kol = 0;
	for (int i = 0; i < size; i++) {
		tmp += arr[i].GetTemperatureInfo();
		kol++;
	}
	return tmp / kol;
}
int Thermometer::AverageNoonTemp(int _month) {
	bool f = true;
	int i = 0;
	double tmp = 0;
	int kol = 0;
	while (i < size) {
		if (arr[i].MonthInfo(_month) == true && arr[i].GetSeniorHours() >= 6 && arr[i].GetSeniorHours() < 18) {
			tmp += arr[i].GetTemperatureInfo();
			kol++;
			f = false;
		}
		i++;
	}
	if (!f) return tmp / kol;
	return NULL;
}
int Thermometer::AverageNightTemp(int _month) {
	bool f = true;
	int i = 0;
	double tmp = 0;
	int kol = 0;
	while (i < size) {
		if (arr[i].MonthInfo(_month) == true && (arr[i].GetSeniorHours() < 6 || arr[i].GetSeniorHours() >= 18)) {
			tmp += arr[i].GetTemperatureInfo();
			kol++;
			f = false;
		}
		i++;
	}
	if (!f) return tmp / kol;
	return NULL;

}
void Thermometer::Push_Back(Date _value) { //2
	if (size < buf) {
		arr[size] = _value;
		size++;
	}
	else {
		buf += zapas;
		Date* newarr;
		newarr = new Date[buf];
		for (int i = 0; i < size; i++) {
			newarr[i] = arr[i];
		}
		newarr[size] = _value;
		delete[] arr;
		arr = nullptr;
		arr = new Date[buf];
		size++;
		for (int i = 0; i < size; i++) {
			arr[i] = newarr[i];
		}
		delete[] newarr;
		newarr = nullptr;
	}
}
int Thermometer::GetSize() {
	return size;
}
istream & operator >> (istream & stream, Thermometer &_T) {
	stream >> _T.size;
	if (_T.size >= _T.buf) {
		delete[] _T.arr;
		_T.arr = nullptr;
		_T.buf += _T.zapas;
		_T.arr = new Date[_T.size];
	}
	for (int i = 0; i < _T.size; i++) {
		stream >> _T.arr[i];
	}
	return stream;
}
ostream & operator << (ostream & stream, Thermometer const &_T) {
	stream << _T.size << endl;
	for (int i = 0; i < _T.size; i++) {
		stream << _T.arr[i] << " ";
	}
	return stream;
}