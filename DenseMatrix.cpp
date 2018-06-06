#include "stdafx.h"
#include "DenseMatrix.h"


DenseMatrix::DenseMatrix(int rows):Matrixx(rows)
{
	for (int i = 0; i < rows; i++)
	{
		Matrixx::setElement(i, 0, 0);
	}
}

DenseMatrix::DenseMatrix(int rows, int cols):Matrixx(rows,cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Matrixx::setElement(i, j, 0);
		}
	}
}

DenseMatrix::DenseMatrix(int rows, int cols, int ** elements) :Matrixx(rows, cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Matrixx::setElement(i, j, elements[i][j]);
		}
	}
}

DenseMatrix::~DenseMatrix()
{
}

