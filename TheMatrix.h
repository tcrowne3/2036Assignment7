#include <vector>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include "string.h"
#include <stdexcept>
#include "stdlib.h"
#include "Complex.h"

using namespace std;
class Matrix
{
		friend Matrix operator-(Matrix &);
		friend Matrix operator*(const ComplexNumber &, const Matrix &);
		friend Matrix operator*(const double, const Matrix &);
		friend Matrix operator~(Matrix &);
		friend ostream& operator<<(ostream &, const Matrix &);
		friend std::istream &operator>>(std::istream &, Matrix &);

	public:
		Matrix();
		Matrix(const unsigned int);
		Matrix(const unsigned int, const vector<ComplexNumber>);

		unsigned int size() const;
		ComplexNumber operator[](unsigned int) const;
		void size(const unsigned int);
		ComplexNumber& operator()(const unsigned int, const unsigned int);
		Matrix operator+(const Matrix &);
		Matrix& operator+=(const Matrix &);
		Matrix operator-(const Matrix &);
		Matrix operator*( const Matrix & );
		Matrix operator*(const ComplexNumber &);
		Matrix operator*(const double);
		Matrix operator/(const ComplexNumber &);
		Matrix operator/(const double);

		Matrix& operator=(const Matrix &);
		bool operator==(const Matrix &);


	private:
		vector<ComplexNumber> data;
		const ComplexNumber zero;
		unsigned int sizeMat;
		ComplexNumber** matrix;
		
	};