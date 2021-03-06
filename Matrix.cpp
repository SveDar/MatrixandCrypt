// Matrix.cpp : Defines the entry point for the console application.
//Svetlo<<+>>daricos project;
//

#include "stdafx.h"
#include "Matrixx.h"
#include"DenseMatrix.h"
#include <iostream>

using namespace std;
// Next Version Better OOP extract crypt methods in own class :+
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
	DenseMatrix matrixes(3,3);
	int sizemat = matrixes.getCols()*matrixes.getRows();
	for (int i = 0; i < lenght/sizemat; i++)
	{
		int matrixpos = 0;
		for (int j = 0; j < matrixes.getCols(); j++)
		{
			for (int k = 0; k < matrixes.getRows(); k++)
			{
				int value = intmessage[i * sizemat + (matrixpos)];
				matrixes.setElement(j, k, value);
				matrixpos++;
			}
		}
		matrixes.addScalar((int)key);
		matrixes.transponright();
		matrixpos = 0;
		for (int j = 0; j < matrixes.getCols(); j++)
		{
			for (int k = 0; k < matrixes.getRows(); k++)
			{
					message[i * sizemat + (matrixpos)] = (char)matrixes.getElement(j, k);
					matrixpos++;
			}
		}
	}
	if (lenght % sizemat != 0)
	{
		for (int i = lenght-lenght%9; i < lenght; i++)
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
	DenseMatrix matrixes(3, 3);
	int sizemat = matrixes.getCols()*matrixes.getRows();
	for (int i = 0; i < lenght / sizemat; i++)
	{
		int matrixpos = 0;
		for (int j = 0; j < matrixes.getRows(); j++)
		{
			for (int k = 0; k < matrixes.getCols(); k++)
			{
				int value = intmessage[i * sizemat + (matrixpos)];
				matrixes.setElement(j, k, value);
				matrixpos++;
			}
		}
		matrixpos = 0;
		matrixes.addScalar(-(int)key);
		matrixes.transponright();
		for (int j = 0; j < matrixes.getCols(); j++)
		{
			for (int k = 0; k < matrixes.getRows(); k++)
			{
					message[i * sizemat + (matrixpos)] = (char)matrixes.getElement(j, k);
					matrixpos++;
			}
		}
	}
	if (lenght % sizemat != 0)
	{
		for (int i = lenght - lenght % sizemat; i < lenght; i++)
		{
			message[i] = (int(message[i]) - (int)key) ;
		}
	}
	return message;
}
char* cryptMessage2(char* message, char key) {
	cryptMessage1(message, key);
	for (int i = 1; i < strlen(message); i++)
	{
		message[i] = (int(message[i])) + (int)(key * i*i);
	}
	return message;
}
char* decryptMessage2(char* message, char key) {
	for (int i = 1; i < strlen(message); i++)
	{
		message[i] = (int(message[i])) - (key*i*i);
	}
	decryptMessage1(message, key);
	return message;
}
char* cryptMessage3(char* message, char* key) {

	for (int i = 0; i < strlen(key); i++)
	{
		cryptMessage2(message, key[i]);
	}
	return message;
}
char* decryptMessage3(char* message, char* key) {

	for (int i = strlen(key)-1; i>-1; i--)
	{
		decryptMessage2(message, key[i]);
	}
	return message;
}

int main()
{
	char stri[200];
	readMessage(stri);
	char key[10];
	readMessage(key);
	cryptMessage3(stri, key);
	cout << stri<<endl;
	decryptMessage3(stri, key);
	cout << stri << endl;
    return 0;
}

