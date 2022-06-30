#pragma once
using namespace std;
class Procenter {
private:
	int size; // размер базы
	Info* base; // база клиентов
	string fname; // имя файла
public:
	// По умолчанию конструктор и деструктор
	Procenter();
	~Procenter();
	// констуктор, принимающий имя файла
	Procenter(string);
	// Геттеры
	int Getsize();
	Info* Getbase();
	string Getfname();
	Info* SearchClient(int); // Ищет клиента в базе, возвращает ссылку на ячейку
	friend ostream & operator << (ostream & stream, const Procenter &_P);
	friend istream & operator >> (istream & stream, Procenter &_P);
};
