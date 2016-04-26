// THOMAS CROWNE
// 4/18/2016

#define Complex_h
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

class ComplexNumber {
	
public :
	// Constructor
	ComplexNumber();
	ComplexNumber(double real, double complex);
	/////////////////////////////////////////////////
	friend ComplexNumber operator~(const ComplexNumber &);
	friend std::istream &operator>>(std::istream &, ComplexNumber &); //Czech syntax in book.
	friend std::ostream &operator<<(std::ostream &, const ComplexNumber &);
	// Check syntax in book
	//Arithmetic opetations
	friend ComplexNumber operator+(const double, const ComplexNumber &);
	friend ComplexNumber operator-(const double, const ComplexNumber &);
	friend ComplexNumber operator*(const double, const ComplexNumber &);
	friend ComplexNumber operator/(const double, const ComplexNumber &);
	ComplexNumber operator+(const ComplexNumber &);
	ComplexNumber operator+(const double);
	ComplexNumber operator+=(const ComplexNumber &);
	ComplexNumber operator+=(const double);
	ComplexNumber operator-(const ComplexNumber &);
	ComplexNumber operator-(const double);
	ComplexNumber operator-();
	ComplexNumber operator*(const ComplexNumber &);
	ComplexNumber operator*(const double);
	ComplexNumber operator/(const ComplexNumber &);
	ComplexNumber operator/(const double);
	bool operator==(const ComplexNumber &);
	void operator=(const ComplexNumber &);
	// Get/Set/print functions
	double getreal();
	double getcomplex();
	void setreal(double real);
	void setcomplex(double complex);
	double magnitude2();
	

private:
	//void init(double real, double complex);
	double real;
	double complex;
};

