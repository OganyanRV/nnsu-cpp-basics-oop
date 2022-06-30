#include <iostream>
#include <windows.h>
using namespace std;

struct position {
	int x, y;
};

class Fieldclass {
private:
	const int height=24;
	const int width=24; //размеры поля 24на24
	char ** field; 	// наше поле
public:
	Fieldclass();
	~Fieldclass();
	void print(); // нарисовать пустое поле
	void clear(); // очистить поле
	int get_width() const;
	int get_height() const;
	void draw(int, int, char); // рисовать змейку
};
class Foodclass {
	position pos;
	char symbol;
public:
	Foodclass();
	void set_pos(int, int);
	void RDMspawn(const Fieldclass & field);
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
};
class Snakeclass {
	enum { UP, DOWN, LEFT, RIGHT } direction;
	char body;
	char head1;
	position pos[400]; // массив позиций тела
	position* head; // позиция головы
	int size; // размер змейки
	int score; // ваш счет
public:
	Snakeclass(int, int); // конструктор змеи с координатами головы
	bool check_food(const Foodclass & food); // Есть  ли еда на этой клетке
	void button(const Fieldclass & field); // Проверяет какая кнопка нажата и змейка меняет направление
	void move(const Fieldclass & field); // Определяет направление  и проиграли вы или нет
	void draw(Fieldclass & field); //рисует змейку
	int get_x() const;
	int get_y() const;

};
int Snakeclass::get_x() const {
	return head->x;
}
int Snakeclass::get_y() const {
	return head->y;
}

Snakeclass::Snakeclass(int x, int y) {
	body = '=';
	head1 = '@';
	size = 5;
	score = 0;
	direction = LEFT;
	head = &pos[0];
	pos[0].x = x;
	pos[0].y = y;

}

bool Snakeclass::check_food(const Foodclass & food) { // Если голова стоит на еде
	if (food.get_x() == head->x && food.get_y() == head->y) {
		size++;
		return true;
	}
	return false;
}

void Snakeclass::button(const Fieldclass & field) {
	if (GetAsyncKeyState(VK_UP) && direction != DOWN) {
		direction = UP;
	}
	if (GetAsyncKeyState(VK_DOWN) && direction != UP) {
		direction = DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT) && direction != RIGHT) {
		direction = LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) && direction != LEFT) {
		direction = RIGHT;
	}
}

void Snakeclass::move(const Fieldclass & field) {
	position next = { 0, 0 };
	switch (direction) { // Вниз вправо это плюс
	case UP:
		next.y = -1;
		break;
	case DOWN:
		next.y = 1;
		break;
	case LEFT:
		next.x = -1;
		break;
	case RIGHT:
		next.x = 1;
		break;
	}
	for (int c = size - 1; c > 0; --c) { // при передвижении каждая координата тела перемещается на предыдущую( близшую к голове)
		pos[c] = pos[c - 1];
	}
	head->x += next.x;
	head->y += next.y;
	bool flagg = true;
	for (int f = size - 1; f > 0; f--) { // проверка не кушает ли змейка саму себя
		if (pos[f].x == head->x && pos[f].y == head->y) {
			flagg = false;
			break;
		}
	}
	if (head->x < 2 || head->y < 2 || head->x >= field.get_width() - 1 || head->y >= field.get_height() - 1 || flagg == false) {
		throw "Вы проиграли";
	}
}

void Snakeclass::draw(Fieldclass & field) { //рисует змейку
	field.draw(pos[0].y, pos[0].x, head1);		
	for (int c = 1; c < size; ++c)
		field.draw(pos[c].y, pos[c].x, body);
}
Foodclass::Foodclass() {
	symbol = 'X';
	pos.x = pos.y = -1;
}

void Foodclass::set_pos(int x, int y) {
	pos.x = x;
	pos.y = y;
}

void Foodclass::RDMspawn(const Fieldclass & field) {
	pos.x = 2 + rand() % (field.get_width() - 2);
	pos.y = 2 + rand() % (field.get_height() - 2);
}

int Foodclass::get_x() const {
	return pos.x;
}
int Foodclass::get_y() const {
	return pos.y;
}
char Foodclass::get_symbol() const {
	return symbol;
}
Fieldclass::Fieldclass() {
	field = new char*[height];
	for (int c = 0; c < height; ++c) {
		field[c] = new char[width];
	}
}
Fieldclass::~Fieldclass() { // удаление динамического массива
	for (int c = 0; c < height; ++c) {
		delete[] field[c];
	}
	delete[] field;
}
void Fieldclass::print() {
	for (int c = 1; c < height; c++) { // пустое место
		for (int r = 1; r < width; r++) {
			cout << field[c][r] << ' ';
		}
		cout << endl;
	}
	int i, j;
	for (i = 1, j = 1; j < height; j++) // границы поля
	{
		field[1][j] = '#';
		field[height - 1][j] = '#';

	}
	for (i = 0, j = 0; i < width; i++) // границы поля
	{
		field[i][1] = '#';
		field[i][width - 1] = '#';
	}
}

void Fieldclass::clear() {
	for (int c = 2; c < height - 1; ++c) {
		for (int r = 2; r < width - 1; ++r) {
			field[c][r] = ' ';
		}
	}

}
int Fieldclass::get_width() const
{
	return width;
}
int Fieldclass::get_height() const {
	return height;
}

void Fieldclass::draw(int y, int x, char what) {
	field[y][x] = what;
}
enum ConsoleColor {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
void main() {
	using namespace std;
	Fieldclass field;
	Foodclass food;
	Snakeclass snake(11, 11);
	setlocale(LC_ALL, "Russian");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // цвет текста и фона
	SetConsoleTextAttribute(hConsole, (WORD)((Yellow << 4) | Red));
	system("cls");
	int dif;
	int score = 0;
	cout << "Введите сложность: " << endl;
	cin >> dif;
	int rem = dif - score;
	int b = 3;
	system("cls");
	while (b > 0) {
		cout << "До начала игры: " << b;
		Sleep(1000); // частота перерисовки
		system("cls"); // очищает экран
		b--;
	}
	field.clear();
	food.set_pos(5, 5);
	while (rem > 0) {
		cout << "Ваш счет: " << score;
		rem = dif - score;
		cout << "\t Осталось до победы: " << rem << endl;
		field.clear();
		snake.button(field); // жмем на кнопку, программа определяет какую и что ей делать
		try { // Пробует повернуть туда
			snake.move(field);
		}
		catch (const char* lost) { // если вы ударились в стену или съели себя, то игра закончена
			// появится надпись "вы проиграли", а также ваш конечный счет
			field.clear();
			system("cls");
			cout << lost << endl;
			cout << "Ваш итоговый счет: " << score << endl;
			system("pause");
			return;
		}
		snake.draw(field);
		field.draw(food.get_y(), food.get_x(), food.get_symbol());
		if (snake.check_food(food)) { // Если мы съели еду, то появляется новая
			food.RDMspawn(field);
			score++;
		}

		field.print(); // все это рисуется
		Sleep(20); // частота перерисовки
		system("cls"); // очищает экран
	}
	cout << "Поздравляем, вы победили!" << endl;
	system("pause");
	return;
}