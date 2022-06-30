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
bool Bankomat::Deposit(int pyatK, int dvaK, int K, int pyatsot, int dvesot, int odinsot) { //если кассеты не переполнятся
	if (pyatK + money[0] <= 2000 && dvaK + money[1] <= 2000 && K + money[2] <= 2000 && pyatsot
		+ money[3] <= 2000 && dvesot + money[4] <= 2000 && odinsot + money[5] <= 2000) {
		money[0] += pyatK;
		money[1] += dvaK;
		money[2] += K;
		money[3] += pyatsot;
		money[4] += dvesot;
		return true;
	}
	return false;
}
bool Bankomat::Withdraw(int _m) {
	int value[6] = { 5000, 2000, 1000, 500, 200, 100 };
	bool f = true;
	int tmp = 0;
	int count = 0;
	if (_m <= 200000) { //Т.к банкомат работает максимум с 40 купюрами, то максимум зачисления денег - 200к
		for (int i = 0; i < 6; i++) {
			if (_m > 0) {
				tmp = _m / value[i];
				if (money[0] - tmp >= 0) {
					_m -= tmp * value[i];
					count += tmp;
				}
				money[i] -= tmp;
			}
			else break;
		}
	}
	if (_m == 0) return true;
	return false;
	delete[] value;
}
Bankomat::~Bankomat() {
	user = nullptr;
	file = nullptr;
	delete[] money;
}
bool Bankomat::InsertCard(int _num) {
	Info* ans = file->SearchClient(_num); // есть ли такая карта в базе. 
	if (ans != nullptr) {
		user = ans; // Банкомат хранит ссылку на этого клиента в базе
		return true;
	}
	return false;
}
Bankomat::Bankomat() {
	ifstream in;
	in.open(file->Getfname());
	in >> *file;
	in.close();
}
bool Bankomat::DepositHELP(bool b, int sum) { // Если в кассетах есть место,  зачислить деньги
	if (b == false) return false;
	user->Setcash(user->Getcash() + sum);
	return true;
}
bool Bankomat::WithdrawHELP(bool b, int sum) {
	if (b == false) return false;
	user->Setcash(user->Getcash() - sum);
	return true;
}
bool Bankomat::CheckPin(int _pin) {
	int a;
	if (user->Getblocked() == true) {
		cout << "Карта уже заблокирована из-за превышения неправильных попыток ввода пароля" << endl;
		return false;
	}
	if (user->Getpin() == _pin) return true;
	else {
		cout << "Неправильный PIN. Осталось попыток: 2" << endl;
		cin >> a;
		if (user->Getpin() == a) return true;
		else {
			cout << "Неправильный PIN. Осталось попыток: 1" << endl;
			cin >> a;
			if (user->Getpin() == a) return true;
			else {
				cout << "Карта заблокированна после 3 неудачных попыток" << endl;
				user->Setblocked(1); // блокирует карту
				return false;
			}
		}
	}
}
void Bankomat::ScreenOutClientInfo() {
	cout << "Состояние счета клиента" << endl;
	cout << "ФИО: " << user->Getname() << endl;
	cout << "Номер карты: " << user->Getnumbercard() << endl;
	cout << "Счет: " << user->Getcash() << endl;
	// Свойство заблокированна ли карта нет смысла показывать
}
Info* Bankomat::Getuser() {
	return user;
}
void Bankomat::ReturnCard() {
	user = nullptr;
}