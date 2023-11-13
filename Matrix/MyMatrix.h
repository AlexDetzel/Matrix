#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class MyMatrix
{
public:
	MyMatrix();
	MyMatrix(int rows, int cols);
	MyMatrix(string path);

	~MyMatrix();

	MyMatrix(const MyMatrix& other);

	MyMatrix operator* (const double mult);
	MyMatrix& operator= (const MyMatrix other);

	MyMatrix getTransposedMatrix();
	MyMatrix getReverseMatrix();

	void fillRand();
	void fillOneValue(int row, int col, int value);
	double getOneValue(int row, int col);
	double det();
	void print();
	int getRows();
	void setRowsAndCols(int rows, int cols);
	int getCols();
	void safeInCSV(string fileName);


private:
	double** arrPointer = 0;
	int rows = 0;
	int cols = 0;
	string path;

	MyMatrix CutRowAndCol(int cutRow, int cutCols);
};

