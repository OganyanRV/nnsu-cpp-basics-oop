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
vector < vector<int> > g; // ����
vector<bool> used;

void dfs(int v) {
	cout << v + 1 << " ";
	used[v] = true;
	for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); i++) //*i ������ ���������� �� ������, �� �� �� ��������
		if (!used[*i] && g[v][*i] != 0)
			dfs(*i);
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n; // ����� ������
	cout << "������� ���������� ������: ";
	cin >> n;
	cout << "������� ������� ���������: " << endl;
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

	cout << "������� ������� � ������� ���������� �����: ";
	int v;
	cin >> v;
	cout << "������� ������ ������: ";
	dfs(v - 1);
	system("pause");
}

/*
#include <iostream>
using namespace std;
const int n = 5;
int i, j;
bool *visited = new bool[n];
//������� ��������� �����
int graph[n][n] =
{
{0, 1, 0, 0, 1},
{1, 0, 1, 1, 0},
{0, 1, 0, 0, 1},
{0, 1, 0, 0, 1},
{1, 0, 1, 1, 0}
};
//����� � �������
void DFS(int st)
{
	int r;
	cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r <= n; r++)
		if ((graph[st][r] != 0) && (!visited[r]))
			DFS(r);
}
//������� �������
void main()
{
	setlocale(LC_ALL, "Rus");
	int start;
	cout << "������� ��������� �����: " << endl;
	for (i = 0; i < n; i++)
	{
		visited[i] = false;
		for (j = 0; j < n; j++)
			cout << " " << graph[i][j];
		cout << endl;
	}
	cout << "��������� ������� >> ";
	cin >> start;
	//������ ���������� ������
	bool *vis = new bool[n];
	cout << "������� ������: ";
	DFS(start - 1);// ������ �� 1 ������
	delete[]visited;
	system("pause>>void");
}
*/