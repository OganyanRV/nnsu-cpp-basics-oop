#include<iostream>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include<vector>
#include<algorithm>
#include<stdexcept>
using namespace std;
vector < vector<int> > g; // граф
vector<bool> used;

void dfs(int v) {
	cout << v + 1 << " ";
	used[v] = true;
	for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); i++) //*i должен переходить на строки, но он на столбцах
		if (!used[*i] && g[v][*i] != 0)
			dfs(*i);
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n; // число вершин
	cout << "Введите количество вершин: ";
	cin >> n;
	cout << "Введите матрицу смежности: " << endl;
	for (int i = 0; i < n; i++) {
		vector <int> temp;
		used.push_back(false);
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			temp.push_back(a);
		}
		g.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Введите вершину с которой начинается обход: ";
	int v;
	cin >> v;
	cout << "Порядок обхода вершин: ";
	dfs(v - 1);
	system("pause");
}

/*
#include <iostream>
using namespace std;
const int n = 5;
int i, j;
bool *visited = new bool[n];
//матрица смежности графа
int graph[n][n] =
{
{0, 1, 0, 0, 1},
{1, 0, 1, 1, 0},
{0, 1, 0, 0, 1},
{0, 1, 0, 0, 1},
{1, 0, 1, 1, 0}
};
//поиск в глубину
void DFS(int st)
{
	int r;
	cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r <= n; r++)
		if ((graph[st][r] != 0) && (!visited[r]))
			DFS(r);
}
//главная функция
void main()
{
	setlocale(LC_ALL, "Rus");
	int start;
	cout << "Матрица смежности графа: " << endl;
	for (i = 0; i < n; i++)
	{
		visited[i] = false;
		for (j = 0; j < n; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}
	cout << "Стартовая вершина >> ";
	cin >> start;
	//массив посещенных вершин
	bool *vis = new bool[n];
	cout << "Порядок обхода: ";
	DFS(start - 1);// индекс на 1 меньше
	delete[]visited;
	system("pause>>void");
}
*/