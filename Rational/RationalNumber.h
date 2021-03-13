#pragma once
#include <iostream>

using namespace std;


class RationalNumber
{
	friend ostream& operator<<(ostream&, const RationalNumber&);
	friend istream& operator>>(istream&, RationalNumber&);

public:
	RationalNumber(); // Default constructor
	RationalNumber(const int, const int); // Numerator and denominator

	~RationalNumber();

	RationalNumber& operator+(const RationalNumber&);
	RationalNumber& operator-(const RationalNumber&);
	RationalNumber& operator*(const RationalNumber&);
	RationalNumber& operator/(const RationalNumber&);
	
	bool operator<(const RationalNumber&);
	bool operator>(const RationalNumber&);
	bool operator<=(const RationalNumber&);
	bool operator>=(const RationalNumber&);
	bool operator==(const RationalNumber&);
	bool operator!=(const RationalNumber&);

	bool isValid();
	bool isDividedByZero();

private:
	int numerator, denominator;
	bool valid, divideByZeroError;

	int findGreatestCommonDivisor(const unsigned int, const unsigned int);
	void checkValidity();
	void simplify();
};

