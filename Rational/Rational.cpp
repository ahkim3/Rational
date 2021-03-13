/*
Name: Andrew Kim
Date: March 12, 2021
Program: Rational

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
    RationalNumber firstFraction, secondFraction, sum, difference, product, 
        quotient;
    bool lessThan, greaterThan, lessThanOrEqualTo, greaterThanOrEqualTo, 
        equalTo, notEqualTo;

    // Prompt user to enter fractions
    do
    {
        cout << "Please enter a fraction (in form a/b): ";
        cin >> firstFraction;
        cout << endl << endl;
    } while (!firstFraction.isValid());

    do
    {
        cout << "Please enter a second fraction (in form a/b): ";
        cin >> secondFraction;
        cout << endl << endl;
    } while (!secondFraction.isValid());

    // Display simplified fractions
    cout << "First fraction (simplified): " << firstFraction << endl;
    cout << "Second fraction (simplified): " << secondFraction << endl << endl;

    // Calculate first three arithmetic operations
    sum = firstFraction + secondFraction;
    difference = firstFraction - secondFraction;
    product = firstFraction * secondFraction;

    // Display arithmetic operations
    cout << firstFraction << " + " << secondFraction << " = " << sum << endl;
    cout << firstFraction << " - " << secondFraction << " = " << difference 
        << endl;
    cout << firstFraction << " * " << secondFraction << " = " << product 
        << endl;

    // Handle division operation and display results
    cout << firstFraction << " / " << secondFraction << " = ";
    quotient = firstFraction / secondFraction;
    if (!firstFraction.isDividedByZero())
        cout << quotient;
    cout << endl << endl;

    // Calculate comparisons
    lessThan = firstFraction < secondFraction;
    greaterThan = firstFraction > secondFraction;
    lessThanOrEqualTo = firstFraction <= secondFraction;
    greaterThanOrEqualTo = firstFraction >= secondFraction;
    equalTo = firstFraction == secondFraction;
    notEqualTo = firstFraction != secondFraction;

    // Display comparisons
    if (lessThan) // <
        cout << firstFraction << " is less than " << secondFraction;
    else
        cout << firstFraction << " is not less than " << secondFraction;
    cout << endl;

    if (greaterThan) // >
        cout << firstFraction << " is greater than " << secondFraction;
    else
        cout << firstFraction << " is not greater than " << secondFraction;
    cout << endl;

    if (lessThanOrEqualTo) // <=
        cout << firstFraction << " is less than or equal to " 
        << secondFraction;
    else
        cout << firstFraction << " is not less than or equal to " 
        << secondFraction;
    cout << endl;

    if (greaterThanOrEqualTo) // >=
        cout << firstFraction << " is greater than or equal to " 
        << secondFraction;
    else
        cout << firstFraction << " is not greater than or equal to " 
        << secondFraction;
    cout << endl;

    if (equalTo) // ==
        cout << firstFraction << " is equal-to " << secondFraction;
    else
        cout << firstFraction << " is not equal-to " << secondFraction;
    cout << endl;

    if (notEqualTo) // !=
        cout << firstFraction << " is not-equal-to " << secondFraction;
    else
        cout << firstFraction << " is not not-equal-to " << secondFraction;
    cout << endl << endl;

    system("pause");
    return 0;
}
