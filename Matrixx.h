#pragma once
class Matrixx
{
private:
	int rows;
	int cols;
	double **matrix=nullptr;
	void Copy(const Matrixx& a);
	void Erase();
public:
	Matrixx(int rows, int cols);
	Matrixx(int rows);
	Matrixx(const Matrixx& matrix);
	Matrixx& operator=(const Matrixx& matrix);
	int getRows();
	int getCols();
	double getElement(int x, int y);
	void setElement(int x,int y,double value);
	//functionations
	//it's pointless to have 4 functions because matrixes could be multipled by scalar or summed with scalar
	//evry other function is result of adding and multypling so its better OOP principe to have only 2 functions :)
	//other like Matrix*Matrix, Matrix+Matrix,determinant or matrix^-1 could be done out of matrix class :)
	void addScalar(double scalar);
	void multyScalar(double scalar);
	void transpon();
	void transponright();

	~Matrixx();
};
//Dani lection :D
//abstract class = class with only virtual functions
// we use them for ierarchies