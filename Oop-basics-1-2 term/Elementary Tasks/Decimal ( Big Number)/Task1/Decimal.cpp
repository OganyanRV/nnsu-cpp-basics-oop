#include <iostream>
#include <algorithm>
#include <locale.h>
#include "Decimal.h"
using namespace std;
Decimal::Decimal(unsigned _size) {
	size = _size;
	value = new unsigned char[size];
}
Decimal::~Decimal() {
	size = 0;
	value = nullptr;
}
bool Decimal::operator>(const Decimal& _num) {
	if (size == _num.size)
	{
		int i;
		for (i = size-1; i >= 0; i--)
		{
			if (value[i] < _num.value[i])
				return false;
			}
		return true;
	}
	else if (size < _num.size)
		return false;
	else if (size > _num.size)
		return true;
}
bool Decimal::operator<(const Decimal& _num) {
	if (size == _num.size)
	{
		int i;
		for (i = size-1; i >= 0; i--)
		{
		 if (value[i] > _num.value[i])
				return false;
		}
		return true;

	}
	else if (size < _num.size)
		return true;
	else if (size > _num.size)
		return false;
}
bool Decimal::operator==(const Decimal& _num) {
	int i;
	if (size == _num.size) {
		for (i = size - 1; i >= 0; i--)
		{
			if (value[i] != _num.value[i])
				return false;
		}
		return true;
	}
	else return false;
}
ostream& operator<<(ostream& stream, const Decimal&_num)

{
	int i;
	for (i = _num.size - 1; i >= 0; i--) {
		stream << (unsigned)_num.value[i];
	}

	return stream;

}
istream& operator >> (istream& stream, Decimal& _num)
{
	int i;
	int cinsize = _num.size + 1;
	char* num = new  char[cinsize]; /*When I started writting the programm, I didn`t know that 
									i could use string,	so I used array of chars */
	getchar();
	stream.getline(num, cinsize);
	for (i = 0; i < _num.size; i++) {
		_num.value[_num.size - i - 1] = num[i] - '0'; /*atoi(&num[i]) spoils the elements 
													  of the array for some reason */
	}	return stream;

}
Decimal Decimal::operator+(const Decimal& _num) {
	int size1;
	int tmp = 0;
	int i;
	if (size == _num.size)
		size1 = size;
	else size1 = max(size, _num.size);
	Decimal Sum(size1);
	for (i = 0; i < min(size, _num.size); i++) { /* At first we need to add up the part, which both
												 of numbers have. ( From 0 to minimum length)  */
		Sum.value[i] = (value[i] + _num.value[i] + tmp) % 10;
		tmp = (value[i] + _num.value[i] + tmp) / 10;
	}
	if (size != _num.size) // Else we dont have to do anything
	{
		for (i = min(size, _num.size); i < max(size, _num.size); i++)
		{
			// Now rewrite the remaining digits of the number, considering possible additional digital
			if (size > _num.size)
			{
				Sum.value[i] = (value[i] + tmp) % 10;
				tmp = (value[i] + tmp) / 10;
			}
			else if (size < _num.size)
			{
				Sum.value[i] = (_num.value[i] + tmp) % 10;
				tmp = (_num.value[i] + tmp) / 10;
			}

		}

	}
	return Sum;
}
Decimal Decimal::operator-(const Decimal& _num) {
	int size1 = max(size, _num.size);
	Decimal Dif(size1);
	int i, tmp = 0;
	for (int i = 0; i < min(size, _num.size); i++) /* At first we need to  subtract the part, which
												   both of numres have. ( From 0 to minimum length)	 */
	{
		if (value[i] - _num.value[i] >= tmp)
		{
			Dif.value[i] = value[i] - _num.value[i] - tmp;
			tmp = 0;

		}
		else
		{
			Dif.value[i] = value[i] - _num.value[i] + 10 - tmp;
			tmp = 1;
		}
	}
	if (size != _num.size) //Else we dont have to do anything
	{
		if (size > _num.size)
			/* Now rewrite the remaining digits of the number, considering the opportunity
			we can occupy digits*/
		{
			for (int i = min(size, _num.size); i < max(size, _num.size); i++)
			{
				if (value[i] - tmp < 0) //If we occupy digit, then rewrite considering occupied digit
				{
					Dif.value[i] = value[i] - tmp + 10;
					tmp = 1;
				}
				else //Else rewrite the number with the longest lenthg.
				{
					Dif.value[i] = value[i] - tmp;
					tmp = 0;
				}
			}
		}
		else
		{
			for (int i = min(size, _num.size); i < max(size, _num.size); i++) /* similarly for the
																			  opposite case */
			{
				if (_num.value[i] + tmp > 0)
				{
					Dif.value[i] = -tmp + 10 - _num.value[i];
					tmp = 1;
				}
				else
				{
					Dif.value[i] = _num.value[i] - tmp;
					tmp = 0;
				}
			}
		}
	}
	return Dif;
}
Decimal& Decimal::operator= (const Decimal& _num)
{
	int i;
	for (i = 0; i < size; i++) {
		value[i] = _num.value[i];
	}
	return *this;
}

