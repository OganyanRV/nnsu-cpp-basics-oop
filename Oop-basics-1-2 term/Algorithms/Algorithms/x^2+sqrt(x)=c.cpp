#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

long double check(long double x) {
	return pow(x, 2) + sqrt(x);
}
long double upperbound(long double x) {
	int a = sqrt(x);
	a = (a + 1) / 1;
	return a;
}

long double binSearch(double c) {
	double R = upperbound(c), L = 0, M;
	while (fabs(R - L) > 1e-10) {
		M = (L + R) / 2;
		if (check(M) - c < 0) {
			L = M;
		}
		else if (check(M) - c > 0) {
			R = M;
		}
		else return M;
	}
	return R;
}

int main() {
	double c;
	cin >> c;
	double result = binSearch(c);
	cout << fixed << setprecision(6) << result;
	getchar();
	getchar();
}