#include "stdafx.h"
#include "Matrixx.h"
#include <iostream>
using namespace std;


void Matrixx::Copy(const Matrixx & a)
{
	rows = a.rows;
	cols = a.cols;
	matrix = new double*[rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new double[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = a.matrix[i][j];
		}
	}
}

void Matrixx::Erase()
{
	for (int i = 0; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

Matrixx::Matrixx(int rows,int cols)
{
	this->rows = rows;
	this->cols = cols;
	this-> matrix = new double*[rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new double[cols];
	}
}

Matrixx::Matrixx(int rows)
{
	this->rows = 1;
	this->cols = rows;
	this->matrix = new double*[rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new double[cols];
	}
}

Matrixx::Matrixx(const Matrixx & matrix)
{
	Copy(matrix);
}

Matrixx & Matrixx::operator=(const Matrixx & matrix)
{
	if (this != &matrix) {
		Erase();
		Copy(matrix);
	}
	return *this;
}

int Matrixx::getRows()
{
	return rows;
}

int Matrixx::getCols()
{
	return cols;
}

double Matrixx::getElement(int x,int y)
{
	if (x<rows&&y<cols)
	{
		return matrix[x][y];
	}
}

void Matrixx::setElement(int x, int y,double value)
{
	if (x<rows&&y<cols)
	{
		matrix[x][y]=value;
	}
}

void Matrixx::addScalar(double scalar)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)	
		{
			matrix[i][j] += scalar;
		}
	}
}

void Matrixx::multyScalar(double scalar)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] *= scalar;
		}
	}
}
/*
double Matrixx::determinant()
{
	if (rows==cols)
	{
		double **temp;
		temp = new double*[rows];
		for (int i = 0; i < rows; ++i) {
			matrix[i] = new double[cols];
		}
		if (rows==1)
		{
			return matrix[0][0];
		}
		for (int i = 0; i < rows; i++)
		{

		}
	}
	maybe not now XD
}*/


Matrixx::~Matrixx()
{
	Erase();
}
