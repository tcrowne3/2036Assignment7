#include "TheMatrix.h"
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
using namespace std;


// Default constructor
Matrix::Matrix() 
{
	sizeMat = 1;
	data.push_back(zero);
}

// Secondary Constructors
Matrix::Matrix(const unsigned int size)
{
	sizeMat = size;
	data.assign((size * size), zero);
}

Matrix::Matrix(const unsigned int size, const vector<ComplexNumber> fillVals) 
{
	sizeMat = size;
	int times = 1;
	for (int i = 0; i < sizeMat; i++) 
	{
		for (int j = 0; j < sizeMat; j++)
		{
			data.push_back(fillVals[(j * sizeMat) + i]);
		}
	}
}

// Get size
unsigned int Matrix::size() const 
{
	return sizeMat;
}


// Set Size
void Matrix::size(const unsigned int newSize) 
{
	vector<ComplexNumber> temp((newSize * newSize), zero);
	for (unsigned int i = 0; i < newSize; i++) 
	{
		for (unsigned int j = 0; j < newSize; j++) 
		{
			if ((j < sizeMat) && (i < sizeMat))
			{
				temp[(i * newSize) + j] = data[(i * sizeMat) + j];
			}
		}
	}
	data = temp;
	sizeMat = newSize;
}

// Overloaded ()
ComplexNumber& Matrix::operator()(const unsigned int x, const unsigned int y)
{
	int index = (y - 1) * sizeMat + (x - 1);
	return data[index];
}

ComplexNumber Matrix::operator[](unsigned int a) const
{
	if (a >= (sizeMat)) 
	{
		throw std::out_of_range("index exceeds matrix size");
	}
	int num = a;
	int r = num / (sizeMat / 2);
	int c = num%(sizeMat / 2);
	return matrix[r][c];
}

// Overloaded ==
bool Matrix::operator==(const Matrix &mat)
{
	bool equal = false;
	for (int i = 0; i < (sizeMat * sizeMat); i++)
	{
		if (data[i] == mat.data[i])
		{
			equal = true;
		}
	}
	return equal;
}

// Overloaded ~
Matrix operator~(Matrix &mat)
{
	Matrix newMat(mat.size());
	for (int i = 0; i < (mat.size() * mat.size()); i++)
	{
		newMat.data[i] = ~mat.data[i];
	}
	return newMat;
}

// Overloaded +
Matrix Matrix::operator+(const Matrix &mat) 
{
	Matrix newMat(sizeMat);
	for (int i = 0; i < (sizeMat * sizeMat); i++) 
	{
		newMat.data[i] = data[i] + mat.data[i];
	}
	return newMat;
}

// Overloaded +=
Matrix& Matrix::operator+=(const Matrix &mat)
{
	for (int i = 0; i < (sizeMat * sizeMat); i++)
	{
		data[i] += mat.data[i];
	}
	return *this;
}

//overloaded =
Matrix& Matrix::operator=(const Matrix &mat) 
{
	sizeMat = mat.sizeMat;
	for (int i = 0; i < (sizeMat * sizeMat); i++) 
	{
		data[i] = mat.data[i];
	}
	return Matrix(mat);
}

// Overloaded -
Matrix operator-(Matrix &mat) 
{
	Matrix newMatrix(mat.size());
	for (int i = 0; i < (mat.size() * mat.size()); i++)
	{
		newMatrix.data[i] = -mat.data[i];
	}
	return newMatrix;
}

// Overloaded -
Matrix Matrix::operator-(const Matrix &mat) 
{
	Matrix newMatrix(sizeMat);
	Matrix newMat2(sizeMat);
	newMat2 = mat;
	newMatrix = *this + (-newMat2);
	return newMatrix;
}


// Overloaded *
Matrix Matrix::operator*(const ComplexNumber &a) 
{
	Matrix newMat(sizeMat);
	for (int i = 0; i < (sizeMat * sizeMat); i++) {
		newMat.data[i] = data[i] * a;
	}
	return newMat;
}
// Overloaded *
Matrix Matrix::operator*(const Matrix &a)
{
	return(0);
}
// Overloaded * 
Matrix operator*(const ComplexNumber &a, const Matrix &b) 
{
	Matrix newMat(b.size());
	Matrix temp(b.size());
	temp = b;
	newMat = temp * a;
	return newMat;
}

// Overloaded *
Matrix Matrix::operator*(const double a)
{
	Matrix newMat(sizeMat);
	ComplexNumber temp(a, 0);
	newMat = *this * temp;
	return newMat;
}


// Overloaded * 
Matrix operator*(const double a, const Matrix &b) {
	Matrix newMat(b.size());
	Matrix temp(b.size());
	ComplexNumber c(a, 0);
	temp = b;
	newMat = temp * c;
	return newMat;
}

// Overloaded /
Matrix Matrix::operator/(const ComplexNumber &a) {
	Matrix newMat(sizeMat);
	newMat = *this * (1 / a);
	return newMat;
}


// Overloaded /
Matrix Matrix::operator/(const double num) 
{
	Matrix newMat(sizeMat);
	ComplexNumber temp(num, 0);
	newMat = *this / temp;
	return newMat;
}


// Overloaded <<
ostream& operator<<(ostream &output, const Matrix &mat)
{
	for (unsigned int i = 0; i < mat.size(); i++) 
	{
		for (unsigned int j = 0; j < mat.size(); j++) 
		{
			output << mat.data[i * mat.size() + j] << " | ";
		}
		output << endl;
	}
	return output;
}

std::istream &operator>>(std::istream &input, Matrix &a)
{
	int ssize = a.size()*a.size() - 1;
	ComplexNumber temp;
	for (int i = 0; i <= ssize; ++i) {
		input >> temp;
		a[ i ] = temp;
	}
	return input;
}

