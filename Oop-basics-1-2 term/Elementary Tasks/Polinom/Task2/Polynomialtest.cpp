#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>
#include <clocale>
#include <fstream>
#include "Polynomial.h"
#include <algorithm>
using namespace std;
void main() {
	setlocale(LC_ALL, "Rus");
	int n1;
	Polynomial Poly;
	cout << "Введите степень полинома и введите коэффиценты (от меньшего к большему):" << endl;
	cin >> Poly;
	cout << "Ваш полином: " << endl;
	Poly.screenoutout();
	cout << "Введите индекс коэффицента, значение которого хотите узнать: " << endl;
	int index2;
	cin >> index2;
	cout << "Значения коэффицента с индексом " << index2 << " равно: " << Poly[index2] << endl;
	cout << "Степень полинома: " << Poly.GetPolydegree() << endl;
	cout << "Введите точку, в которой хотите найти значение полинома" << endl;
	int x;
	cin >> x;
	cout << "Значение полинома в заданной точке x = " << x << " равно " << Poly.Polyfunvalue(x) << endl;
	cout << "Производная полинома: " << endl;
	Poly.Polydifferential().screenoutout(); /*Poly.Polydifferential() возвращает полином производной.
											Его и выводидим на экран с помощью screenoutout() */
											//Ввод в файл и вывод из файла
											//Вывод нашего полинома Poly в файл
	ofstream out;
	out.open("output.txt");
	out << Poly;
	out.close();
	// Ввод полинома из файла
	Polynomial text1file(2);
	ifstream in;
	in.open("input.txt");
	in >> text1file;
	in.close();
	cout << " Считано из файла 'input.txt': " << text1file << endl;
	Polynomial sum;
	sum = Poly + text1file;
	cout << "Результат сложения введенного полинома и полинома,\nсчитанного из файла: " << endl;
	sum.screenoutout();
	//Выведем результат сложения (sum) в файл
	out.open("outputSUM.txt");
	out << sum;
	out.close();
	/*
	Вывод программы выглядит следующим образом:
	Введите степень полинома и введите коэффиценты (от меньшего к большему):
	4
	5 4 3 0 2
	Ваш полином:
	2*х^4+3*х^2+4*х^1+5
	Введите индекс коэффицента, значение которого хотите узнать
	2
	Значения коэффицента с индексом 2 равно: 3
	Степень полинома: 4
	Введите точку, в которой хотите найти значение полинома
	-1
	Значение попинона в заданной точке х = -1 равно 6
	Производная полинома:
	8*х^3+6*х^1+4
	Считано из файла 'input.txt': 2 3 3 1
	Результат сложения введенного полинома и полинома,
	считанного из файла: 2*x^4+4*x^2+7*x^1+8
	Как выглядит input.txt : 2 3 3 1
	Как выглядит output.txt : 4 5 4 3 0 2
	Как выглядит outputSUM.txt : 4 8 7 4 0 2
	*/

}