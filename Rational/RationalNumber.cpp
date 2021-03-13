#include "RationalNumber.h"
#include <iomanip>

using namespace std;


// Default constructor
RationalNumber::RationalNumber()
{
	numerator = 1;
	denominator = 1;
	valid = true;
	divideByZeroError = false;
}


// Prevents 0 or negative in denominator and simplifies fraction
RationalNumber::RationalNumber(const int numeratorInput, 
	const int denominatorInput)
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
	valid = true;

	if (denominator == 0) // Error if denominator is 0
	{
		cout << "ERROR: Denominator must be non-zero.";
		valid = false;
	}
	else if (numerator < 0 && denominator < 0)
	{
		// Double negative simplifies to positive
		numerator = abs(numerator);
		denominator = abs(denominator);
	}
	else if (denominator < 0) // Move negative from denominator to numerator
	{
		numerator *= -1;
		denominator = abs(denominator);
	}
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
	if (fraction.numerator == 0 || fraction.numerator == fraction.denominator
		|| fraction.denominator == 1)
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
RationalNumber& RationalNumber::operator+(const RationalNumber& secondFrac)
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
	static RationalNumber sum((numerator * firstMultiplier) + 
		(secondFrac.numerator * secondMultiplier), leastCommonMultiple);
	 
	return sum;
}


// Subtracts fractions
RationalNumber& RationalNumber::operator-(const RationalNumber& secondFrac)
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
	static RationalNumber difference((numerator * firstMultiplier) - 
		(secondFrac.numerator *	secondMultiplier), leastCommonMultiple);

	return difference;
}


// Multiplies fractions
RationalNumber& RationalNumber::operator*(const RationalNumber& secondFrac)
{
	// Create fraction containing product
	static RationalNumber product((numerator * secondFrac.numerator),
		(denominator * secondFrac.denominator));

	return product;
}


// Divides fractions
RationalNumber& RationalNumber::operator/(const RationalNumber& secondFrac)
{
	if (secondFrac.numerator != 0) // Checks to see if divisor is not 0
	{
		// Create fraction containing product
		static RationalNumber quotient((numerator * secondFrac.denominator),
			(denominator * secondFrac.numerator));

		return quotient;
	}
	else // Divisor was 0
	{
		cout << "ERROR: Your divisor cannot be 0.";
		divideByZeroError = true;
	}
}


// Checks if this fraction is less than second fraction
bool RationalNumber::operator<(const RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator) 
		< ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Checks if this fraction is more than second fraction
bool RationalNumber::operator>(const RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator)
		> ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Checks if this fraction is less than second fraction
bool RationalNumber::operator<=(const RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator)
		<= ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Checks if this fraction is less than second fraction
bool RationalNumber::operator>=(const RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator)
		>= ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Checks if this fraction is equal to the second fraction
bool RationalNumber::operator==(const RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator)
		== ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Checks if this fraction is not equal to the second fraction
bool RationalNumber::operator!=(const RationalNumber& secondFrac)
{
	if (((double)numerator / (double)denominator)
		!= ((double)secondFrac.numerator / (double)secondFrac.denominator))
		return true;
	return false;
}


// Returns the validity of the fraction
bool RationalNumber::isValid()
{
	if (valid)
		return true;
	return false;
}


// Returns true if a divide by zero error is needed
bool RationalNumber::isDividedByZero()
{
	if (divideByZeroError)
		return true;
	return false;
}
