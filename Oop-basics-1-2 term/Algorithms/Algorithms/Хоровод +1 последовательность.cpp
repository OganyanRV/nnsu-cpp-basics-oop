#include <iostream>
#include <vector>
using namespace std;

int main() {
// �� ���� �������� ���������� �������� q � ������������������ �� n �������.
// ����� �� ��� ���������� ������� �� �����? 5-1-2-3-4 ��������

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
			// &= ���������� �.
			okl &= (a[(pos - j + n) % n] == j + 1); // ������� ���� �����. +n ����� � ����� �� ����
			okr &= (a[(pos + j + n) % n] == j + 1); // ������� ���� �������. %n �.� �� ���� ����
		}
		if (okl || okr) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}