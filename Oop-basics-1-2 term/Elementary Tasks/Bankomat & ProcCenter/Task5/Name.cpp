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
Name::Name() {
	i = "<unknown>";
	f = "<unknown>";
	o = "<unknown>";
}
Name::Name(string _i, string _f, string _o) {
	i = _i;
	f = _f;
	o = _o;
}
Name::~Name() {
	i = "<unknown>";
	f = "<unknown>";
	o = "<unknown>";
}
istream & operator >> (istream & stream, Name &_name) {
	stream >> _name.f >> _name.i >> _name.o;
	return stream;
}
ostream & operator << (ostream & stream, const Name &_name) {
	stream << _name.f << " " << _name.i << " " << _name.o << endl;
	return stream;
}
string Name::GetName() {
	return i;
}
string Name::GetSurname() {
	return f;
}
string Name::GetFatherName() {
	return o;
}