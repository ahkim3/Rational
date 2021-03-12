#include "RationalNumber.h"
#include <iomanip>

using namespace std;


// Default constructor
RationalNumber::RationalNumber()
{
	numerator = 1;
	denominator = 1;
}


// Prevents 0 or negative in denominator and simplifies fraction
RationalNumber::RationalNumber(int numeratorInput, int denominatorInput)
{
	numerator = numeratorInput;
	denominator = denominatorInput;

	checkValidity();
	simplify();
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


// Prevents division by 0 and negative denominators
void RationalNumber::checkValidity()
{
	if (denominator <= 0)
		throw invalid_argument("Denominator must be positive");
}


// Reduces the fraction
void RationalNumber::simplify()
{
	int greatestCommonDivisor;

	if (numerator == 0) // Fraction is equivalent to 0
		denominator = 1;
	else
	{
		// Reduces fraction to its simplified form
		greatestCommonDivisor = findGreatestCommonDivisor(numerator, 
			denominator);
		numerator = numerator / greatestCommonDivisor;
		denominator = denominator / greatestCommonDivisor;
	}
}


// Overloaded stream insertion operator
ostream& operator<<(ostream& output, const RationalNumber& fraction)
{
	if (fraction.numerator == 0) // Fraction equivalent to zero
		output << fraction.numerator;
	else
		output << fraction.numerator << '/' << fraction.denominator;
	return output;
}


// Overloaded stream extraction operator
istream& operator>>(istream& input, RationalNumber& number)
{
	input >> number.numerator;
	input.ignore(); // Ignore the /
	input >> number.denominator;

	number.checkValidity();
	number.simplify();

	return input;
}
