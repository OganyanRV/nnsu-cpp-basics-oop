#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Date.h"
#include "Thermometer.h"

using namespace std;
void main() {
	setlocale(LC_ALL, "Russian");
	int a, b, c, dd;
	Thermometer t1;
	cout << "Введите количество наблюдений и заполните календарь наблюдений" << endl;
	cin >> t1;
	//1
	cout << "Начальная дата и время наблюдений: ";
	cout << t1.GetStartInfo() << endl;
	//2
	cout << "Добавим наблюдение:" << endl;
	cout << "Введите это наблюдение: ";
	Date d1;
	cin >> d1;
	t1.Push_Back(d1);
	//3
	cout << "Введите дату и время, чтобы узнать температуру: ";
	cin >> a >> b >> c >> dd;
	Date d2(a, b, c, dd, 0);
	cout << t1.GetTemperature(d2) << endl;
	//4
	cout << "Введите дату для серии наблюдения: " << endl;
	cin >> a >> b >> c;
	Date d3(a, b, c, 0, 0);
	t1.Screenoutfordate(d3);
	//5.1
	cout << "Введите дату для расчета средней температуры: " << endl;
	cin >> a >> b >> c;
	Date d4(a, b, c, 0, 0);
	cout << t1.AverageTempbyDate(d4) << endl;
	//5.2
	cout << "Введите месяц для расчета средней температуры: " << endl;
	cin >> a;
	cout << t1.AverageTempbyMonth(a) << endl;
	//5.3	
	cout << "Среднаяя температура за все время: " << t1.Tempall() << endl;
	//6.1
	cout << "Введите месяц для расчета средней дневной температуры: " << endl;
	cin >> a;
	cout << t1.AverageNoonTemp(a) << endl;
	//6.2
	cout << "Введите месяц для расчета средней ночной температуры: " << endl;
	cin >> a;
	cout << t1.AverageNightTemp(a) << endl;
	// Запись и чтение из файла
	// запись нашего термометра в output.txt
	ofstream out;
	out.open("output.txt");
	out << t1;
	out.close();
	// чтение из файла 
	Thermometer test;
	ifstream in;
	in.open("input.txt");
	in >> test;
	in.close();
	cout << " Считано из файла 'input.txt': " << test << endl;

}