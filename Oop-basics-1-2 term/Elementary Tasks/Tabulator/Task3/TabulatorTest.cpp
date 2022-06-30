#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Tabulator.h"
using namespace std;
void main() {
	setlocale(LC_ALL, "Russian");
	Tabulator taby;
	double a, b;
	int point;
	cout << "Введите промежуток табуляции: ";
	cin >> a >> b;
	taby.SetBegin(a); // Установим начало
	taby.SetEnd(b); // Установим конец
	do { /* Так как минимальное кол-во точек табулирования 2 ( левая и правая граница),
		 то сделаем проверку на ввод количества точек. Если введен невозможный случай, то ввод повторяется*/
		cout << "Введите количество точек табуляции (point>=2): ";
		cin >> point;
		taby.SetPointNumper(point);
	} while (point < 2);
	Ftype function;
	int choice;
	cout << "Выберите функцию, к которой хотите выполнить табулирование: " << endl;
	do { // Меню выбора функции для табуляции. Если введена неверная позиция, то ввод идет заново.
		cout << "1) sin(x) * cos(x)" << endl;
		cout << "2) Sqrt(x)" << endl;
		cout << "3) exp ^ x" << endl;
		cin >> choice;
	} while (choice < 1 || choice > 3);
	switch (choice) {
	case 1:
		function = fun1;
		taby.FunValue(function); // Табулирование функции
		cout << "Функция: sin(x) * cos(x)" << endl;
		// Вывод информации с помощью геттеров
		cout << "Промежуток для табулирования: " << "[" << taby.GetBegin() << ";" << taby.GetEnd() << "]" << endl;
		cout << "Количество точек табуляции: " << taby.GetPointNumber() << endl;
		taby.Screenout(); //Вывод результата на экран с помощью специального метода Screenout
		break;
	case 2:
		function = fun2;
		taby.FunValue(function);
		cout << "Функция: Sqrt(x)" << endl;
		cout << "Промежуток для табулирования: " << "[" << taby.GetBegin() << ";" << taby.GetEnd() << "]" << endl;
		cout << "Количество точек табуляции: " << taby.GetPointNumber() << endl;
		taby.Screenout();
		break;
	case 3:
		function = fun3;
		taby.FunValue(function);
		cout << "Функция: exp ^ x" << endl;
		cout << "Промежуток для табулирования: " << "[" << taby.GetBegin() << ";" << taby.GetEnd() << "]" << endl;
		cout << "Количество точек табуляции: " << taby.GetPointNumber() << endl;
		taby.Screenout();
		break;
	default:
		break;
	}
	// Запись и чтение из файла
	// запись в файл texttabyout
	Tabulator texttabyout(-5.0, 5.0, 11);
	texttabyout.FunValue(fun1);
	ofstream out;
	out.open("output.txt");
	out << texttabyout;
	out.close();
	// чтение из файла в texttabyin
	Tabulator texttabyin;
	ifstream in;
	in.open("input.txt");
	in >> texttabyin;
	in.close();
	cout << " Считано из файла 'input.txt': " << texttabyin << endl;
	/* Как выглядит вывод программы:
	Введите промежуток табуляции: 2 6
	Введите количество точек табуляции (point>=2): 3
	Выберите Функцию, к которой хотите выполнить табулирование:
	1)	sin(x) * cos(x)
	2)	Sqrt(x)
	3)	exp ^ x
	2
	Функция: Sqrt(x)
	Промежуток для табулирования: [2;б]
	Количество точек табуляции: 3
	Результат табуляции:
	X:	2 4 6
	f(x): 1.41421 2 2.44949
	Считано из Файла 'input.txt': О 1 2 О 1 1 2.71828
	Как выглядит "output.txt": -5 5 11 -5 -4 -3 -2 -1 0 1 2 3 4 5 0.272011 -0.494679 0.139708 0.378401 -0.454649 0 0.454649 -0.378401 -0.139708 0.494679 -0.272011
	*/
}