#pragma once
using namespace std;
typedef double(*Ftype) (double);
class Tabulator {
private:
	double begin;
	double end;
	int n;
	double* xarray;
	double* yarray;
	Ftype fun;
public:
	Tabulator();// Конструктор
	Tabulator(double, double, int);//Конструктор
	~Tabulator();// Деструктор
	// Сеттеры
	void SetBegin(double); // установить начало
	void SetEnd(double); // установить конец
	void SetPointNumper(int); // установить количество точек табулирования
	// Геттеры
	double GetBegin(); // получить начало
	double GetEnd(); // получить конец
	int GetPointNumber(); // получить количество точек табулирования

	Tabulator(const Tabulator& _Tab); // конструктор копирования
	Tabulator& operator= (const Tabulator& _Tab); // перегрузка присваивания
	void FunValue(Ftype); // метод, считающий значение функции в точках
	void Screenout(); // метод, выводящий информацию на экран
	friend istream& operator>>(istream & stream, Tabulator & _Tab); // перегрузка потока ввода
	friend ostream& operator<<(ostream & stream, const Tabulator & _Tab); // перегрузка потока вывода
};
double fun1(double);
double fun2(double);
double fun3(double);
