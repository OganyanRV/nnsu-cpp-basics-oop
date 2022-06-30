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
Procenter::Procenter() {
	base = nullptr;
	size = 0;
	fname = "";
}
Procenter::~Procenter() {
	size = 0;
	delete[] base;
	base = nullptr;
	fname = "";
}
Info* Procenter::SearchClient(int _num) { // Если находит эту карту в базе, то возвращает ссылку на ячейку
	int ans, i;
	for (i = 0; i < size; i++) {
		if (_num == base[i].Getnumbercard()) {
			return &base[i];
		}
	}
	return nullptr;
}
Procenter::Procenter(string _fname) { // констуктор, принимающий имя файла
	fname = _fname;
}
Info* Procenter::Getbase() {
	return base;
}
int Procenter::Getsize() {
	return size;
}
string Procenter::Getfname() {
	return fname;
}
ostream & operator << (ostream & stream, const Procenter &_P) {
	stream.clear();
	stream << _P.size << endl;
	for (int i = 0; i < _P.size; i++) {
		stream << _P.base[i] << " ";
	}
	return stream;
}
istream & operator >> (istream & stream, Procenter &_P) {
	stream >> _P.size;
	if (_P.base != nullptr) delete[] _P.base;
	_P.base = new Info[_P.size];
	for (int i = 0; i < _P.size; i++) {
		stream >> _P.base[i];
	}
	return stream;
}