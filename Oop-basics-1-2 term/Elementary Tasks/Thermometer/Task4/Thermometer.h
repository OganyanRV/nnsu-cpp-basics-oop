#pragma once
using namespace std;
class Thermometer {
private:
	int size;// Текущая длина массива
	int buf;// Максимальная длина массива
	const int zapas = 10;	// Число, на которое увеличивается массив при нехватке места
	Date* arr;
public:
	//Конструкторы и деструктор
	Thermometer();
	Thermometer(Date, int);
	~Thermometer();
	//Начальная информация
	Date GetStartInfo();
	//Узнать температуру в наблюдении, выбранном по дате и времени
	int GetTemperature(Date);
	//Выдать серию наблюдений для выбранной дат
	void Screenoutfordate(Date);
	// Средняя температура за день
	int AverageTempbyDate(Date);
	//Средняя температура за месяц
	int AverageTempbyMonth(int);
	// Средняя температура за все время
	int Tempall();
	// Средняя дневная температура за месяц
	int AverageNoonTemp(int);
	// Средняя ночная температура за месяц
	int AverageNightTemp(int);
	// Добавить замер
	void Push_Back(Date);
	// Геттер размера
	int GetSize();
	//Перегрузка потока
	friend ostream & operator << (ostream & stream, Thermometer const &_T);
	friend istream & operator >> (istream & stream, Thermometer &_T);
};
