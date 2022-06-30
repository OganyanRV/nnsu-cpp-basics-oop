#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
Ќужно поделить отрезок на подотрезки, сумма членов которых нечетна.
≈сли количество нечетных меньше, чем количество подотрезков -> Ќельз€.
≈сли количество нужных отрезков четно, то и количество нечетных чисел четно, иначе нельз€.

*/
int main() {

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		int cntodd = 0;
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			cntodd += a[j] % 2;
		}
		if (cntodd < k || cntodd % 2 != k % 2) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int j = 0; j < n; ++j) {
			if (k == 1) break;
			if (a[j] % 2 == 1) {
				cout << j + 1 << " ";
				--k;
			}
		}
		cout << n << endl;
	}
	return 0;
}