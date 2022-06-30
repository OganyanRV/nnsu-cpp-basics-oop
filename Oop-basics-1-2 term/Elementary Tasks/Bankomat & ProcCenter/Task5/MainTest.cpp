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
void main() {
	setlocale(LC_ALL, "Russian");
	Bankomat b1;
	int moneyIn, moneyOut;
	int choise3;
	bool f, flag;
loop1:
	cout << "Вставьте карту и введите PIN" << endl;
	int Pin, Num;
	cin >> Num >> Pin;
	// Найти такую карту в базе. 
	if (b1.InsertCard(Num) == true) { // если такая карта существует
		if (b1.CheckPin(Pin) == false) {// если пароль введен 3 раза неверно или карта уже заблокированна
			goto loop1; // возвращаемся обратно
		}
		else do {
			cout << "Выберите действие" << endl;
			cout << " 1. Распечатать состояние счета" << endl;
			cout << "2. Снять наличные" << endl;
			cout << "3. Принять наличныее" << endl;
			cout << "4. Вернуть карту" << endl;
			cout << "5. Выйти из программы" << endl;
			cin >> choise3;
			switch (choise3) {
			case 1:
				b1.ScreenOutClientInfo();
				break;
			case 2:
				do {
					f = true;
					do {
						f = true;
						cout << "Введите сумму, которую хотите снять (которая делится на 100) : " << endl;
						cin >> moneyOut;
						if (moneyOut % 100 != 0) f = false;
					} while (f == false);
					flag = false;
					if (moneyOut <= b1.Getuser()->Getcash()) { // Если введенная не больше, чем есть на карте
						flag = b1.WithdrawHELP(b1.Withdraw(moneyOut), moneyOut);
						if (flag == true) cout << " Успешно снято " << moneyOut << endl;
						else {
							cout << "В автомате недостаточно купюр " << endl;
							flag = false;
						}
					}
					else {
						cout << "Запрошенная сумма больше той, которая есть на карте" << endl;
						flag = false;
					}
				} while (flag == false);
				break;
			case 3:
				f = true;
				int a, b, c, d, e, ed;
				do {
					flag = true;
					cout << "Введите количество купюр номиналом 5000" << endl;
					cin >> a;
					cout << "Введите количество купюр номиналом 2000" << endl;
					cin >> b;
					cout << "Введите количество купюр номиналом 1000" << endl;
					cin >> c;
					cout << "Введите количество купюр номиналом 500" << endl;
					cin >> d;
					cout << "Введите количество купюр номиналом 200" << endl;
					cin >> e;
					cout << "Введите количество купюр номиналом 100" << endl;
					cin >> ed;
					if (a + b + c + d + e + ed <= 40) { // Если купюр меньше 40
						int sum = 5000 * a + 2000 * b + 1000 * c + 500 * d
							+ 200 * e + 100 * ed;
						flag = b1.DepositHELP(b1.Deposit(a, b, c, d, e, ed), sum);
						if (flag == true) {
							cout << "Успешно зачисленно " << sum << endl;
							flag = true;
						}
						else {
							cout << "В банкомате перебор купюр. Введите другую сумму" << endl;
							flag = false;
						}
					}
					else {
						cout << "Банкомат не рабатет с более чем 40 купюрами за раз" << endl;
						flag = false;
					}
				} while (flag == false);
				break;
			case 4:
				b1.ReturnCard();
				goto loop1;
				break;
			default:
				break;
			}

		} while (choise3 != 5);
	}
	else goto loop1;
}
