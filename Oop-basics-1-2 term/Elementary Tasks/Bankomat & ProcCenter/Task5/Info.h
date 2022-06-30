#pragma once
using namespace std;
class Info {
private:
	int numbercard;
	Name name;
	int cash;
	int pin;
	int blocked;
public:
	// Конструкторы и деструктор
	Info();
	Info(int, Name, int, int, int);
	~Info();
	//Getters
	int Getnumbercard();
	string Getname();
	int Getcash();
	int Getpin();
	int Getblocked();
	//Setters
	void Setnumbercard(int);
	void Setcash(int);
	void Setblocked(int);
	friend ostream & operator << (ostream & stream, const Info &_date);
	friend istream & operator >> (istream & stream, Info &_date);
};

