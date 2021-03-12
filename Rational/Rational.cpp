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

    RationalNumber firstFrac(-1, 2);
    RationalNumber secondFrac(1, 3);

    RationalNumber sum = firstFrac + secondFrac;
    //RationalNumber difference = fraction - firstAddFrac;
    RationalNumber product = firstFrac * secondFrac;

    cout << "Sum: " << sum << endl;
    //cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
}

