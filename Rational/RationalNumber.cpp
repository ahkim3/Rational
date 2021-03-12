#include "RationalNumber.h"

using namespace std;


RationalNumber::RationalNumber(int numerator, int denominator)
{
	// Prevents division by 0
	if (denominator == 0)
		throw invalid_argument("Denominator cannot be 0");

}


RationalNumber::~RationalNumber()
{
}
