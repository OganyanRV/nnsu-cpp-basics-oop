#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Tabulator.h"
using namespace std;
enum SqrtExeption { ArgumentIsNegative };
Tabulator::Tabulator() {
	begin = end = 0.0;
	n = 0;
	xarray = nullptr;
	yarray = nullptr;
}
Tabulator::Tabulator(double _begin, double _end, int _n) {
	n = _n;
	begin = _begin;
	end = _end;
	xarray = new double[n];
	yarray = new double[n];
}
Tabulator::~Tabulator() {
	n = 0;
	end = 0.0;
	begin = 0.0;
	delete[] xarray;
	xarray = NULL;
	delete[] yarray;
	yarray = NULL;
}
void Tabulator::SetBegin(double _begin)
{
	begin = _begin;
}
void Tabulator::SetEnd(double _end)
{
	end = _end;
}
void Tabulator::SetPointNumper(int _n)
{
	n = _n;
	delete[] xarray;
	delete[] yarray;
	xarray = new double[n];
	yarray = new double[n];
}
double Tabulator::GetBegin()
{
	return begin;
}
double Tabulator::GetEnd()
{
	return end;
}
int Tabulator::GetPointNumber()
{
	return n;
}
Tabulator::Tabulator(const Tabulator& _Tab)
{
	int i;
	n = _Tab.n;
	xarray = new double[n];
	yarray = new double[n];
	for (i = 0; i < _Tab.n; i++)
	{
		xarray[i] = _Tab.xarray[i];
		yarray[i] = _Tab.yarray[i];
	}
	begin = _Tab.begin;
	end = _Tab.end;
}
Tabulator& Tabulator::operator= (const Tabulator& _Tab) {
	if (this != &_Tab) {
		if (n != _Tab.n)
		{
			delete[] xarray;
			delete[] yarray;
			n = _Tab.n;
			xarray = new double[n];
			yarray = new double[n];
		}
		for (int i = 0; i < n; i++)
		{
			xarray[i] = _Tab.xarray[i];
			yarray[i] = _Tab.yarray[i];
		}
	}
	return *this;
}
istream& operator>>(istream & stream, Tabulator & _Tab) {
	//Без этого чтение из файла не сработает
	_Tab.xarray = new double[_Tab.n];
	_Tab.yarray = new double[_Tab.n];
	stream >> _Tab.begin >> _Tab.end >> _Tab.n;
	for (int i = 0; i < _Tab.n; i++) {
		stream >> _Tab.xarray[i];
	}
	for (int i = 0; i < _Tab.n; i++) {
		stream >> _Tab.yarray[i];
	}
	return stream;
}
ostream& operator<<(ostream & stream, const Tabulator & _Tab) {
	stream << _Tab.begin << ' ' << _Tab.end << ' ' << _Tab.n << ' ';
	for (int i = 0; i < _Tab.n; i++) {
		stream << _Tab.xarray[i] << ' ';
	}
	for (int i = 0; i < _Tab.n; i++) {
		stream << _Tab.yarray[i] << ' ';
	}
	return stream;
}
void Tabulator::FunValue(Ftype _fun)
{
	fun = _fun;
	int i = 0;
	double interval = (end - begin) / (n - 1); //  интервал между точками
	for (double k = begin; k <= end; k += interval) // цикл табуляции
	{
		xarray[i] = k;
		yarray[i] = fun(k);
		i++;
	}
}
void Tabulator::Screenout()
{
	int i;
	cout << "Результат табуляции: " << endl;
	cout << "x: " << "   ";
	for (i = 0; i < n; i++)
		cout << xarray[i] << ' ';
	cout << "\nf(x): ";
	for (i = 0; i < n; i++)
		cout << yarray[i] << ' ';
	cout << endl;

}
double fun1(double _x) {
	return sin(_x) * cos(_x);
}
double fun2(double _x)
{
	if (_x < 0) { // корень из отрицательного числа брать нельзя
		SqrtExeption expt = ArgumentIsNegative;
		throw expt;
	}
	else return sqrt(_x);
}
double fun3(double _x) {
	return exp(_x);
}