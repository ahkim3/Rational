#include "RationalNumber.h"

using namespace std;


// Default constructor; 
RationalNumber::RationalNumber(int numeratorInput, int denominatorInput)
{
	int greatestCommonDivisor;

	// Prevents division by 0 and negative denominators
	if (denominator <= 0)
		throw invalid_argument("Denominator must be positive");

	// Reduces fractions to its simplified form
	cout << findGreatestCommonDivisor(68, 51);

}


RationalNumber::~RationalNumber()
{
}


// Returns greatest common divisor of two ints
int RationalNumber::findGreatestCommonDivisor(const unsigned int first, 
	const unsigned int second)
{
	if (second == 0)
		return first;
	return findGreatestCommonDivisor(second, first % second);
}



