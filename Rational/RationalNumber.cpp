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
		throw invalid_argument("Denominator must be positive.");
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
		greatestCommonDivisor = findGreatestCommonDivisor(abs(numerator), 
			denominator);
		numerator = numerator / greatestCommonDivisor;
		denominator = denominator / greatestCommonDivisor;
	}
}


// Overloaded stream insertion operator
ostream& operator<<(ostream& output, const RationalNumber& fraction)
{
	// Display just numerator if "fraction" is a whole number
	if (fraction.numerator == 0 || fraction.numerator == fraction.denominator)
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


// Adds fractions
RationalNumber& RationalNumber::operator+(RationalNumber& secondFrac)
{
	unsigned int greatestCommonDivisor = 
		findGreatestCommonDivisor(denominator, secondFrac.denominator);
	unsigned int leastCommonMultiple =
		(denominator * secondFrac.denominator) / greatestCommonDivisor;

	// Find multipliers to get common demoninator
	unsigned int firstMultiplier = leastCommonMultiple / denominator;
	unsigned int secondMultiplier = leastCommonMultiple / 
		secondFrac.denominator;

	// Create fraction containing sum
	RationalNumber sum((numerator * firstMultiplier) + 
		(secondFrac.numerator * secondMultiplier), leastCommonMultiple);

	return sum;
}


// Subtracts fractions
RationalNumber& RationalNumber::operator-(RationalNumber& secondFrac)
{
	int greatestCommonDivisor =
		findGreatestCommonDivisor(denominator, secondFrac.denominator);
	int leastCommonMultiple =
		(denominator * secondFrac.denominator) / greatestCommonDivisor;

	// Find multipliers to get common demoninator
	unsigned int firstMultiplier = leastCommonMultiple / denominator;
	unsigned int secondMultiplier = leastCommonMultiple /
		secondFrac.denominator;

	// Create fraction containing sum
	RationalNumber difference((numerator * firstMultiplier) - 
		(secondFrac.numerator *	secondMultiplier), leastCommonMultiple);

	return difference;
}


// Multiplies fractions
RationalNumber& RationalNumber::operator*(RationalNumber& secondFrac)
{
	// Create fraction containing product
	RationalNumber product((numerator * secondFrac.numerator),
		(denominator * secondFrac.denominator));

	return product;
}


// Divides fractions
RationalNumber& RationalNumber::operator/(RationalNumber& secondFrac)
{
	if (secondFrac.numerator != 0) // Checks to see if divisor is not 0
	{
		// Create fraction containing product
		RationalNumber quotient((numerator * secondFrac.denominator),
			(denominator * secondFrac.numerator));

		return quotient;
	}
	else
		throw invalid_argument("Divisor cannot be 0.");
}


// Checks if this fraction is less than second fraction
bool RationalNumber::operator<(RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator) 
		< ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Checks if this fraction is more than second fraction
bool RationalNumber::operator>(RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator)
		> ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Checks if this fraction is less than second fraction
bool RationalNumber::operator<=(RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator)
		<= ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Checks if this fraction is less than second fraction
bool RationalNumber::operator>=(RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator)
		>= ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Checks if this fraction is equal to the second fraction
bool RationalNumber::operator==(RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator)
		== ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Checks if this fraction is not equal to the second fraction
bool RationalNumber::operator!=(RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator)
		!= ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}
