#pragma once
#include <iostream>

using namespace std;


class RationalNumber
{
	friend ostream& operator<<(ostream&, const RationalNumber&);
	friend istream& operator>>(istream&, RationalNumber&);

public:
	RationalNumber(); // Default constructor
	RationalNumber(int, int); // Numerator and denominator

	~RationalNumber();

	RationalNumber& operator+(RationalNumber&);
	RationalNumber& operator-(RationalNumber&);
	RationalNumber& operator*(RationalNumber&);
	RationalNumber& operator/(RationalNumber&);
	
	bool operator<(RationalNumber&);
	bool operator>(RationalNumber&);
	bool operator<=(RationalNumber&);
	bool operator>=(RationalNumber&);
	bool operator==(RationalNumber&);
	bool operator!=(RationalNumber&);

	bool isValid();
	bool isDividedByZero();

private:
	int numerator, denominator;
	bool valid, divideByZeroError;

	int findGreatestCommonDivisor(const unsigned int, const unsigned int);
	void checkValidity();
	void simplify();
};

