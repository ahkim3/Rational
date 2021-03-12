/*
Name: Andrew Kim
Date: March 9, 2021
Program: Even More A-Maze-ing

I hereby certify that this program represents my
work and that the design and logic was completed
without outside assistance.

Signature: Andrew Kim
*/

#include <iostream>
#include "RationalNumber.h"

using namespace std;


int main()
{
    RationalNumber fraction;

    //cout << "Please enter a fraction (in form a/b): ";
    //cin >> fraction;

    RationalNumber firstFraction(0, 5);
    RationalNumber secondFraction(-1, 5);

    RationalNumber sum = firstFraction + secondFraction;
    RationalNumber difference = firstFraction - secondFraction;
    RationalNumber product = firstFraction * secondFraction;
    RationalNumber quotient = firstFraction / secondFraction;
    
    bool lessThan = firstFraction < secondFraction;
    bool greaterThan = firstFraction > secondFraction;
    bool lessThanOrEqualTo = firstFraction <= secondFraction;
    bool greaterThanOrEqualTo = firstFraction >= secondFraction;
    bool equalTo = firstFraction == secondFraction;
    bool notEqualTo = firstFraction != secondFraction;

    // Simplified fractions
    cout << "First fraction (simplified): " << firstFraction << endl;
    cout << "Second fraction (simplified): " << secondFraction << endl << endl;

    // Arithmetic operations
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl << endl;

    // Comparisons
    if (lessThan)
        cout << firstFraction << " is less than " << secondFraction;
    else
        cout << firstFraction << " is not less than " << secondFraction;
    cout << endl;

    if (greaterThan)
        cout << firstFraction << " is greater than " << secondFraction;
    else
        cout << firstFraction << " is not greater than " << secondFraction;
    cout << endl;

    if (lessThanOrEqualTo)
        cout << firstFraction << " is less than or equal to " 
        << secondFraction;
    else
        cout << firstFraction << " is not less than or equal to " 
        << secondFraction;
    cout << endl;

    if (greaterThanOrEqualTo)
        cout << firstFraction << " is greater than or equal to " 
        << secondFraction;
    else
        cout << firstFraction << " is not greater than or equal to " 
        << secondFraction;
    cout << endl;

    if (equalTo)
        cout << firstFraction << " is equal-to " << secondFraction;
    else
        cout << firstFraction << " is not equal-to " << secondFraction;
    cout << endl;

    if (notEqualTo)
        cout << firstFraction << " is not-equal-to " << secondFraction;
    else
        cout << firstFraction << " is not not-equal-to " << secondFraction;
    cout << endl;
}

