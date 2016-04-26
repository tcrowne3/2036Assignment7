//Main.cpp
//THOMAS CROWNE//////////////////
//Please feel free to copy, i really dont care//////////////////////
#include "Complex.h"
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "string.h"
#include <stdexcept>
#include "stdlib.h"

using namespace std;

//Constructors
ComplexNumber::ComplexNumber()
{
	real = 0;
	complex = 0;
}

ComplexNumber::ComplexNumber(double r, double i)
{
	real = r;
	complex = i;
}
// Addition
ComplexNumber ComplexNumber::operator+(const ComplexNumber &a)
{
	ComplexNumber temp;
	temp.real = real + a.real;
	temp.complex = complex + a.complex;
	return ComplexNumber(temp.real, temp.complex);
}
ComplexNumber ComplexNumber::operator+(const double a)
{
	ComplexNumber temp;
	temp.real = real + a;
	temp.complex = complex;
	return ComplexNumber(temp.real, temp.complex);
}

ComplexNumber operator+(const double a, const ComplexNumber &b)
{
	ComplexNumber temp;
	temp.real = a + b.real;
	temp.complex = b.complex;
	return ComplexNumber(temp.real, temp.complex);
}
// Referance Addition
ComplexNumber ComplexNumber::operator+=(const ComplexNumber &a)
{
	real = real + a.real;
	complex = complex + a.complex;
	return *this;
}

ComplexNumber ComplexNumber::operator+=(const double a)
{
	real = real + a;
	return *this;
}
// Subtraction Operator
ComplexNumber ComplexNumber::operator-(const ComplexNumber &a)
{
	return ComplexNumber(real-a.real, complex-a.complex);
}

ComplexNumber ComplexNumber::operator-(const double a)
{
	return ComplexNumber(real - a, complex);
}

ComplexNumber operator-(const double a, const ComplexNumber &b)
{
	return ComplexNumber(a-b.real, (-1)*b.complex);
}
ComplexNumber ComplexNumber::operator-()
{
	return ComplexNumber(real*(-1), complex*(-1));
}

//Multiplication operator
ComplexNumber ComplexNumber::operator*(const ComplexNumber &a)
{
	ComplexNumber temp;
	temp.real = (real*a.real - complex*a.complex);
	temp.complex = (complex*a.real + real*a.complex);
	return ComplexNumber(temp.real, temp.complex);
}

ComplexNumber ComplexNumber::operator*(const double a)
{
	ComplexNumber temp;
	temp.real = (a*real);
	temp.complex = (a*complex);
	return ComplexNumber(temp.real, temp.complex);
}

ComplexNumber operator*(const double a, const ComplexNumber &b)
{
	ComplexNumber temp;
	temp.real = (a*b.real);
	temp.complex = (a*b.complex);
	return ComplexNumber(temp.real, temp.complex);
}

// Division operator
ComplexNumber ComplexNumber::operator/(const ComplexNumber &a)
{
	ComplexNumber temp;
	
	temp.real = (((complex * a.real) + (complex*a.complex)) / (a.real*a.real + a.complex* a.complex));
	temp.complex = ((complex*a.real - real*a.complex) / (a.real*a.real + a.complex *a.complex));
	return ComplexNumber(temp.real, temp.complex);
}

ComplexNumber ComplexNumber::operator/(const double a)
{
	ComplexNumber temp;
	temp.real = real / a;
	temp.complex = complex / a;
	return ComplexNumber(temp.real, temp.complex);
}

ComplexNumber operator/(const double a, const ComplexNumber &b)
{
	ComplexNumber temp;
	temp.real = (a*b.real / (b.real*b.real + b.complex*b.complex));
	temp.complex = ((a*b.complex*(-1) / (b.real*b.real + b.complex*b.complex)));

	return ComplexNumber(temp.real, temp.complex);
}

// Conjugate operator
ComplexNumber operator~(const ComplexNumber &a)
{
	ComplexNumber temp;
	temp.real = a.real;
	temp.complex = a.complex*(double(-1));
	return ComplexNumber(temp.real, temp.complex);
}
// Equality Operator
bool ComplexNumber::operator==(const ComplexNumber &a)
{
	if (a.real == real && a.complex == complex)
		return true;
	else
		return false;
}

void ComplexNumber::operator=(const ComplexNumber &a)
{
	real = a.real;
	complex = a.complex;
}

//Stream Operators ---ASK----///////////////
std::ostream &operator<<(std::ostream &output, const ComplexNumber &a)
{
	if (a.complex < 0)

		output << a.real << "-" << fabs(a.complex) << "i" << endl;

	else
	{
		output << a.real << "+" << a.complex << "i" << endl;
	}
	return output;
}


// ASK ABOUT ISTREAM
std::istream &operator>>(std::istream &input, ComplexNumber &a)
{
	char ch;
	double r, i;
	input >> ch >> r;
	input >> ch;
	if (ch != ',')
	{
		input.putback(ch);
		i = 0;
	}
	else
		input >> i;
	a.real = r;
	a.complex = i;
	return input;
}	

 // Get functions
double ComplexNumber::getreal()
{
	return(real);
}
double ComplexNumber::getcomplex()
{
	return(complex);
}
// Set functions
void ComplexNumber::setreal(double r)
{
	real = r;
}
void ComplexNumber::setcomplex(double i)
{
	complex = i;
}
double ComplexNumber::magnitude2()
{
	double mag1 = (real*real) + (complex*complex);
	double mag2 = sqrt(mag1);
	return mag2;
}