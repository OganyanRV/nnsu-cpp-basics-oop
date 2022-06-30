#pragma once
using namespace std;
class Decimal {

	unsigned size;
	unsigned char* value;
public:
	Decimal(unsigned _size); //constructor
	~Decimal(); //destructor
				// It`s enough to use 2-3 methods to compare 2 numbers. Their prototype below:
	bool operator > (const Decimal& _num);
	bool operator < (const Decimal& _num);
	bool operator == (const Decimal& _num);
	friend ostream& operator<<(ostream& stream, const Decimal& _num); //Output to stream
	friend istream& operator >> (istream& stream, Decimal& _num); //Input to stream
	Decimal operator+ (const Decimal& _num); // Unsigned addition
	Decimal operator- (const Decimal& _num); // Unsigned subtraction
	Decimal& operator= (const Decimal& _num); // Assignment overload
};
