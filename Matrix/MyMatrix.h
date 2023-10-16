#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class MyMatrix
{
public:
	MyMatrix(int rows);
	MyMatrix(int rows, int cols);
	MyMatrix(string path);

	~MyMatrix();

	MyMatrix(const MyMatrix& other);

	MyMatrix operator* (const double mult);
	MyMatrix& operator= (const MyMatrix other);


	void fillRand();
	void fillFromCsv(string path);
	double det();
	void print();
	int getRows();
	int getCols();
	void safeInCSV(string fileName);
	void fillWithHands();


private:
	double** arrPointer = 0;
	int rows = 0;
	int cols = 0;
	string path;

	MyMatrix CutRowAndCol(int cutRow, int cutCols);
};

