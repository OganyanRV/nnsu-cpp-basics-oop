#include <iostream>
#include <algorithm>
#include <locale.h>
#include "Decimal.h"
using namespace std;
void main()
{
	setlocale(LC_ALL, "Rus");
	int s1, s2;
	cout << "Number 1 size = ";
	cin >> s1;
	Decimal d1(s1);
	cout << "What Number 1 is? : ";
	cin >> d1;
	cout << "Number 2 size = ";
	cin >> s2;
	Decimal d2(s2);
	cout << "What Number 2 is? : ";
	cin >> d2;
	int maxx = max(s1, s2); /* The lentgh of addiction`s array and substraction`s array is equal
							to the maximum length of one of the Numbers */
	Decimal d3(maxx);
	Decimal d4(maxx);
	d3 = d1 + d2;
	cout << "Number 1 + Number 2 = " << d3 << endl;
	d4 = d1 - d2;
	cout << "Number 1 - Number 2 = " << d4 << endl;
	cout << " What is the sign between Number 1 and Number 2?" << endl; /* Comparison of two numbers
																		implemented using three flags*/
	bool f1 = false, f2 = false, f3 = false;
	if (d1 == d2) f1 = true;
	if (d1 > d2) f2 = true;
	if (d1 < d2) f3 = true;
	if ((f1 == true) && (f2 == false) && (f3 == false))
		cout << "Number 1 = Number 2" << endl;
	else if (f1 && f2 && !f3)
		cout << "Number 1 >= Number 2" << endl;
	else if (!f1 && f2 && !f3)
		cout << "Number 1 > Number 2" << endl;
	else if (f1 && !f2 && f3)
		cout << "Number 1 =< Number 2" << endl;
	else if (!f1 && !f2 && f3)
		cout << "Number 1 < Number 2" << endl;
}