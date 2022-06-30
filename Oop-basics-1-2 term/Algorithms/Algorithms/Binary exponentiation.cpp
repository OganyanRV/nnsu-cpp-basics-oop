#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int binpowrec(int a, int n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpowrec(a, n - 1) * a;
	else {
		int b = binpowrec(a, n / 2);
		return b * b;
	}
}
/*int binpow(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
} */
int main() {
	double a;
	int n;
	cin >> a>>n;
	cout << binpowrec(a, n);
	getchar();
	getchar();
}