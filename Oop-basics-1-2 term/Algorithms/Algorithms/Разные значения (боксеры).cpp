#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// на вход подаются веса боксеров, каждый вес можно +-1 или 0. Максимальное количество различных весов?

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend()); // сортировка по убыванию
	int lst = a[0] + 2;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cur = -1;
		for (int dx = 1; dx >= -1; --dx) {
			if (a[i] + dx > 0 && a[i] + dx < lst) {
				cur = a[i] + dx;
				break;
			}
		}
		if (cur == -1) continue;
		++ans;
		lst = cur;
	}
	cout << ans << endl;
}