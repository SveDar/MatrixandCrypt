// Matrix.cpp : Defines the entry point for the console application.
//Svet<<lodaricos project;
//

#include "stdafx.h"
#include "Matrixx.h"
#include"DenseMatrix.h"
#include <iostream>

using namespace std;
void printMatrix(DenseMatrix matrix) {
	int x = matrix.getRows();
	int y = matrix.getCols();
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout<<matrix.getElement(i, j)<<" ";
		}
		cout << endl;
	}
}
void printElement(Matrixx &a, int x, int y) {
	cout << a.getElement(x, y)<<endl;
}
void readMatrix(Matrixx &matrix) {
	
	int x = matrix.getRows();
	int y = matrix.getCols();
	double value;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> value;
			matrix.setElement(i, j, value);
		}
	}
}
void readMessage(char* message) {
	//cout << message << endl;
	cin.getline(message, 200);
}
char* cryptMessage1(char* message,char key) {
	int lenght = strlen(message);
	int intmessage[200];
	for (int i = 0; i < lenght; i++)
	{
		intmessage[i] = (int)message[i];
	}
	DenseMatrix matrixes(2,2);
	for (int i = 0; i < lenght/; i++)
	{
		int matrixpos = 0;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				int value = intmessage[i * 4 + (matrixpos)];
				matrixes.setElement(j, k, value);
				matrixpos++;
			}
		}
		matrixes.addScalar((int)key);
		matrixpos = 0;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
					message[i * 4 + (matrixpos)] = (char)matrixes.getElement(j, k);
					matrixpos++;
			}
		}
	}
	if (lenght % 4 != 0)
	{
		for (int i = lenght-lenght%4; i < lenght; i++)
		{
			message[i] = (int(message[i]) + (int)key);
		}
	}
	return message;
}
char* decryptMessage1(char* message, char key) {
	int lenght = strlen(message);
	int intmessage[200];
	for (int i = 0; i < lenght; i++)
	{
		intmessage[i] = (int)message[i];
	}
	DenseMatrix matrixes(2, 2);
	for (int i = 0; i < lenght / 4; i++)
	{
		int matrixpos = 0;
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				int value = intmessage[i * 2 + (matrixpos)];
				matrixes.setElement(j, k, value);
				matrixpos++;
			}
		}
		matrixpos = 0;
		matrixes.addScalar(-(int)key);
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
					message[i * 4 + (matrixpos)] = (char)matrixes.getElement(j, k);
					matrixpos++;
			}
		}
	}
	if (lenght % 4 != 0)
	{
		for (int i = lenght - lenght % 4; i < lenght; i++)
		{
			message[i] = (int(message[i]) - (int)key) ;
		}
	}
	return message;
}
int main()
{
	char stri[36];
	readMessage(stri);
	cryptMessage1(stri, 's');
	cout << stri<<endl;
	decryptMessage1(stri, 's');
	cout << stri << endl;;
    return 0;
}

