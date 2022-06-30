#include <iostream>
#include <vector>

using namespace std;
int __gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return __gcd(b, a % b);
}
/*

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int gcd(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
*/
int main() {

	// �������� ������������������ �����. ����� ���������� �� ����� ���������.
	int n;
	cin >> n;
	long long g = 0;
	// ���������� 2 ������ ��������� �����. ������� �� ��� � ����� �������� ��� � �����. ����� �� ��� � ��������� ����� � �.�
	for (int i = 0; i < n; ++i) {
		long long x;
		cin >> x;
		g = __gcd(g, x);
	}
	// �������� ���������� ��������� ����� �� �(������ �� �����)
	int ans = 0;
	for (int i = 1; i * 1ll * i <= g; ++i) {
		if (g % i == 0) {
			++ans;
			if (i != g / i) {
				++ans;
			}
		}
	}

	cout << ans << endl;

	return 0;
}