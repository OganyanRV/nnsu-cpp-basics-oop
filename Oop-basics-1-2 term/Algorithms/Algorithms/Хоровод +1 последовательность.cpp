#include <iostream>
#include <vector>
using namespace std;

int main() {
// на вход подается количество запросов q и последовательность из n человек.
// Могут ли они станцевать хоровод по кругу? 5-1-2-3-4 например

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<int> a(n);
		int pos = -1;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			if (a[j] == 1) pos = j;
		}
		bool okl = true, okr = true;
		for (int j = 1; j < n; ++j) {
			// &= логическое И.
			okl &= (a[(pos - j + n) % n] == j + 1); // смотрим чела сзади. +n чтобы в минус не ушли
			okr &= (a[(pos + j + n) % n] == j + 1); // смотрим чела спереди. %n т.к мы даем круг
		}
		if (okl || okr) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}