#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Из последовательности длиной 4n нужно определить, можно ли составить прямоугольники одинаковой длины
// нужно отсортировать и проверить 2i=2i-1, 4n-2i-1=4n-2i-2, 2i-1 = 4n-2i-2

int main() {


	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<int> a(4 * n);
		for (int j = 0; j < 4 * n; ++j) {
			cin >> a[j];
		}
		sort(a.begin(), a.end());
		int area = a[0] * a.back();
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			int lf = i * 2, rg = 4 * n - (i * 2) - 1;
			if (a[lf] != a[lf + 1] || a[rg] != a[rg - 1] || a[lf] * 1ll * a[rg] != area) {
				ok = false;
			}
		}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}