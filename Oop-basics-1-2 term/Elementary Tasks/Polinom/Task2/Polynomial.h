#pragma once
using namespace std;
class Polynomial {
private:
	int size;
	double* coeff;
public:
	Polynomial(); // Конструктор
	Polynomial(int _size); // Конструктор
	~Polynomial(); // Деструктор
	Polynomial(const Polynomial& _Poly); // Конструктор копирования
	Polynomial& operator= (const Polynomial& _Poly); // перегрузка присваивания
	Polynomial operator+ (const Polynomial& _Poly) const; // перегрузка суммирования
	friend istream& operator>>(istream & stream, Polynomial & _Poly); // перегрузка потока ввода
	friend ostream& operator<<(ostream & stream, const Polynomial & _Poly);// перегрузка потока вывода
	double& operator[] (int); // перегрузка индексикации с контролем выхода за предел массива. Узнать коэффицент монома
	const double& operator[] (int) const; // перегрузка индексикации с контролем выхода за предел массива
	int GetPolydegree(); // Узнать степениь полинома
	double Polyfunvalue(double); // Посчитать значение в точке
	Polynomial Polydifferential(); // Производная  полинома
	void screenoutout(); //Вывод на экран полином в текстовой форме
};