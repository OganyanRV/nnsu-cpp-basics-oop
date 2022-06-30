#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
long double firBinSearch(double a, int n, double R) {
	double L = 0;
	while (R - L > 1e-10) {
		double M = (L + R) / 2;
		if (pow(M, n) < a) {
			L = M;
		}
		else if (pow(M, n) > a) {
			R = M;
		}
		else return M;
	}
	return R;
}

int main() {
	int n;
	double a;
	cin >> a >> n;
	if (a >= 1) { // to get a number bigger than 1 u have to raise to some power  number smaller than "a"
		double res = firBinSearch(a, n, a);
		cout << fixed << res;
	}
	else {
		if (a < 1) { // to get a number smaller than 1 u have to raise to some power  number bigger than "a"
			double res = firBinSearch(a, n, 1);
			cout << fixed << res;
		}
	}
	getchar();
	getchar();
}