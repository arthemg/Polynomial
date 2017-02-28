/**
 * CLion was used to compile
 * Artsem Holdvekht
 * CSC 340
 * Assignment 4
 * 10 October 2016
 */

#include "polynomial.h"
#include <stdlib.h>
#include <iostream>
//init default constructor
Polynomial::Polynomial()
{
    degree = 0;
    for (int i = 0; i <= MAX_DEGREE ; i++)
    {
        coefficient[i] = 0.0;
    }
}

Polynomial::Polynomial(int size):degree(size)
{
    degree = size;

    for (int i = 0; i <= MAX_DEGREE ; i++)
    {
        coefficient[i] = 0.0;
    }

}

/*
 * Getter for the highest degree of the polynomial
 */
int Polynomial::getDegree() const
{
    return degree;
}
/*
 * Set the max Degree of the polynomial
 */
void Polynomial::setDegree(int power)
{
    degree = power;
}

/*
 * Get coefficient with certain degree
 */
double Polynomial::getCoeff(int power) const
{
    return coefficient[power];
}

void Polynomial::setCoeff(int power, double newCoefficient)
{
    coefficient[power] = newCoefficient;
}

/**
 * Prompts user to specifie the highest degree of the polynomial and enter all the coefficients associated with
 * certain degrees. And returns polynomial
 * @return polynomial with set coefficients and degrees
 */
Polynomial Polynomial::setUpPoly()
{
    int maxDegree;
    double coeff;

    cout << "Please enter the highest term of your Polynomial: ";
    cin >> maxDegree;

    Polynomial poly(maxDegree+1);

    for (int i = maxDegree; i >= 0 ; i--)
    {
        cout << "Please enter the coefficient for the x to the power of " << i << ":";
        cin >> coeff;
        poly.setCoeff(i, coeff);

    }
    return poly;
}
/**
 * Overloading the division operator to divide the coefficients by a scalar type of double.
 * @param scalar double divisor
 * @return returns polynomial that was divided by scalar
 */
Polynomial Polynomial::operator/(double scalar) const
{
    Polynomial result;
    double coeff;
    double divCoeff;
    int degree = (*this).getDegree();
    result.setDegree(degree);

    for (int i = 0; i <= degree ; i++)
    {
         coeff = (*this).getCoeff(i);
         divCoeff = coeff/scalar;
         result.setCoeff(i, divCoeff);
    }
    return result;
}

/**
 * Overloading  negative(-) operator in order to negate the signs of coefficients
 * @return returns negated polynomial
 */
Polynomial Polynomial::operator-() const
{
    Polynomial negated;
    double inverseSign;
    int degree = (*this).getDegree();
    negated.setDegree(degree);

    for (int i = 0; i <= degree ; i++)
    {
        if((*this).getCoeff(i) >= 0.0)
        {
            inverseSign = (*this).getCoeff(i) * -1;
            negated.setCoeff(i, inverseSign);
        }
        else
        {
            inverseSign = (*this).getCoeff(i) * -1;
            negated.setCoeff(i, inverseSign);
        }
    }
    return negated;

}

/**
 * Overloading addin(+) operator to add 2 polynomials together
 * @param rhs the seconf polinomial to be added
 * @return returns sum of 2 polynomials
 */
Polynomial Polynomial::operator+(const Polynomial &rhs )
{
    Polynomial polySum;
    double sum;
    int degree;
    int lhsDegree = (*this).getDegree();
    int rhsDegree = rhs.getDegree();

    if(lhsDegree >= rhsDegree)
    {
        degree = lhsDegree;
    }
    else
    {
        degree = rhsDegree;
    }

    polySum.setDegree(degree);

    for (int i = degree; i >= 0 ; i--)
    {
        sum = (*this).getCoeff(i) + rhs.getCoeff(i);
        polySum.setCoeff(i, sum);
    }

    return polySum;
}

/**
 * Overloading cout<< operator in ordet o outpu polynomial in a readable formta
 * @param outS outstream
 * @param rhs Polynomial to be printed
 * @return returns a polynomial in a user friendly format
 */
ostream& operator<<(ostream &out, const Polynomial& rhs)
{


    if((rhs.getCoeff(0) > 0.0) || (rhs.getCoeff(0 < 0.0)))
    {
        out<<rhs.getCoeff(0);
    }

    for(int i = 1; i < rhs.getDegree(); i++)
    {

       if(rhs.getCoeff(i) == 0.0)
        {
            continue;
        }
        else if(rhs.getCoeff(i) < 0)
        {
            out<<rhs.getCoeff(i)<<"*x^"<<i;
        }
        else
        {
            out<<"+"<<rhs.getCoeff(i)<<"*x^"<<i;
        }

    }
    return out;
}