#pragma once
#include "Matrixx.h"
class DenseMatrix :
	public Matrixx
{
public:
	DenseMatrix(int rows);//save matrix in 1D array
	DenseMatrix(int rows,int cols);//save matrix in 2D array
	//its not nessery do do it in 2 different clases :)
	DenseMatrix(int rows, int cols, int**elements);
	~DenseMatrix();
};

