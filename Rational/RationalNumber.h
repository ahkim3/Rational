#pragma once
#include <iostream>

using namespace std;


class RationalNumber
{
	//friend ostream& operator<<(ostream&, const RationalNumber&);
	//friend istream& operator>>(istream&, RationalNumber&);
	
	/*
	overload:
	+
	-
	*
	/

	<
	>
	<=
	>=
	==
	!=

	<<
	>>

	not required but can do:
	+=
	-=
	*/

public:
	RationalNumber(int, int); // Numerator and denominator
	/*RationalNumber& operator+();
	RationalNumber& operator-();
	RationalNumber& operator*();
	RationalNumber& operator/();
	RationalNumber& operator<();
	RationalNumber& operator>();
	RationalNumber& operator<=();
	RationalNumber& operator>=();
	RationalNumber& operator==();
	RationalNumber& operator!=();*/


	~RationalNumber();

private:
	unsigned int numerator;
	unsigned int denominator;

	int findGreatestCommonDivisor(const unsigned int, const unsigned int);
};

