#include <iostream>
#include <iomanip>
#include <cmath>
#include <clocale>
#include <fstream>
#include <string>
#include "Name.h"
#include "Info.h"
#include "Procenter.h"
#include "Bankomat.h"
using namespace std;
void Info::Setblocked(int _b) {
	blocked = _b;
	return;
}
void Info::Setnumbercard(int _number) {
	numbercard = _number;
	return;
}
Info::Info() {
	numbercard = cash = pin = blocked = 0;
	Name name("<unknown", "<unknown", "<unknown");
}
Info::Info(int _numbercard, Name _name, int _cash, int _pin, int _blocked) {
	numbercard = _numbercard;
	name = _name;
	cash = _cash;
	pin = _pin;
	blocked = _blocked;
}
Info::~Info() {
	numbercard = cash = pin = blocked = 0;
	Name name("<unknown", "<unknown", "<unknown");
}
int Info::Getcash() {
	return cash;
}
string Info::Getname() {
	string d = name.GetSurname() + " " + name.GetName() + " " + name.GetFatherName();
	return d;
}
int Info::Getnumbercard() {
	return numbercard;
}
int Info::Getpin() {
	return pin;
}
int Info::Getblocked() {
	return blocked;
}
void Info::Setcash(int t) {
	cash = t;
}

ostream & operator << (ostream & stream, const Info &_I) {
	stream << " " << _I.numbercard << " " << _I.name << " " << _I.cash << " " << _I.pin << " " << _I.blocked << endl;
	return stream;
}
istream & operator >> (istream & stream, Info &_I) {
	stream >> _I.numbercard >> _I.name >> _I.cash >> _I.pin >> _I.blocked;
	return stream;
}