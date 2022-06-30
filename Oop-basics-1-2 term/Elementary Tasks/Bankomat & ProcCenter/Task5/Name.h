#pragma once
using namespace std;
class Name { // класс ФИО.
private:
	string i;
	string f;
	string o;
public:
	// Конструкторы и деструктор
	Name();
	Name(string, string, string);
	~Name();
	//Геттеры
	string GetName();
	string GetSurname();
	string GetFatherName();
	// Перегрузки потока
	friend ostream & operator << (ostream & stream, const Name &_name);
	friend istream & operator >> (istream & stream, Name &_name);
};