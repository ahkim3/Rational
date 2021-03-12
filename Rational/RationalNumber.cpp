#include "RationalNumber.h"
#include <iomanip>

using namespace std;


// Default constructor; prevents 0 or negative in denominator and simplifies
RationalNumber::RationalNumber(int numeratorInput, int denominatorInput)
{
	int greatestCommonDivisor;

	// Prevents division by 0 and negative denominators
	if (denominator <= 0)
		throw invalid_argument("Denominator must be positive");

	if (numeratorInput == 0) // Fraction is equivalent to 0
	{
		zero = true;
		numerator = numeratorInput;
		denominator = denominatorInput;
	}
	else
	{
		zero = false;

		// Reduces fraction to its simplified form
		greatestCommonDivisor = findGreatestCommonDivisor(numeratorInput,
			denominatorInput);
		numerator = numeratorInput / greatestCommonDivisor;
		denominator = denominatorInput / greatestCommonDivisor;
	}
}


// Default destructor
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


// Overloaded output operator
ostream& operator<<(ostream& output, const RationalNumber& fraction)
{
	output << fraction.numerator << " / " << fraction.denominator;
	return output;
}
