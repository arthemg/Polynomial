/**
 * CLion was used to compile
 * Artsem Holdvekht
 * CSC 340
 * Assignment 4
 * 10 October 2016
 */

#include <iostream>
#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_


#include <vector>
#include <stdlib.h>
using namespace std;

const int MAX_DEGREE = 100;

class Polynomial
{
    private:

        double coefficient[MAX_DEGREE + 1];
        unsigned int degree;

    public:

        //default constructor
        Polynomial();

        //constructor with the max Degree allowed
        explicit Polynomial(int size);

        //getter for the degree
        int getDegree() const;

        //getter for coefficient of certain degree
        double getCoeff(int power) const;

        //setter to the change the degree
        void setDegree(int power);

        //setter for the coefficient of certain degree
        void setCoeff(int power, double newCoefficient);

        //fucntion to get user input to set polynomial
        Polynomial setUpPoly();
        // overloading the division (/) operator
        Polynomial operator/(double scalar) const ;

        //overloading negative (-) to negate the signs if the coefficients
        Polynomial operator-() const;
        //overloading + operator to add 2 polynomials
        Polynomial operator+(const Polynomial &rhs );

        //overloading ostream & operator<<(ostream & out, const Polynomial &rhs);
        friend ostream& operator<<(ostream& out, const Polynomial& rhs);
};

#endif