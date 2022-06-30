#pragma once
using namespace std;
class Bankomat {
private:
	Info* user; // данные о текущем пользователе 
	Procenter *file = new Procenter("Input.txt");
	int money[6] = { 1600, 1600, 1600, 1600, 1600, 1600 }; //Количество купюр первоначально (5000, 2000, 1000, 500, 200, 100)
public:
	Bankomat(); // Конструктор, загружающий файл с базой клиентов
	~Bankomat(); //Деструктор
	Info* Getuser(); // Getter для данных о текущем пользователе
	bool InsertCard(int); // 1. Вставить карту и 2. Найти ее в базе
	bool CheckPin(int); // 3. Проверить сходится ли пинкод 3 раза и проверить была ли заблокированна карта
	void ScreenOutClientInfo(); // 4. Вывести информацию о клиенте
	bool Deposit(int, int, int, int, int, int); // 5. Положить деньги
	bool DepositHELP(bool, int); // 5. Вспомогательный метод для зачисление денег
	bool Withdraw(int); // 6. Снять деньги
	bool WithdrawHELP(bool, int); // 6. Вспомогательный метод для снятия денег
	void ReturnCard(); // 7. Вынуть карту
};
