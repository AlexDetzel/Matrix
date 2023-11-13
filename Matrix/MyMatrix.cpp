#include "MyMatrix.h"


MyMatrix::MyMatrix()
{
	double** arrPointer = 0;
	int rows = 0;
	int cols = 0;
}

MyMatrix::MyMatrix(int rows, int cols)
{
	//cout << "k" << "\n";
	this->rows = rows;
	this->cols = cols;
	this->arrPointer = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		arrPointer[i] = new double[cols];
	}
}

MyMatrix::MyMatrix(string path)
{
	int rowsNew = 0, colsNew = 0;

	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		//cout << "Error IN";
	}
	else
	{
		//cout << "file opened";
		char ch;
		while (fin.get(ch))
		{
			if (ch == '\n') rowsNew += 1;
			if (ch == ',') colsNew += 1;
		}
		colsNew = (colsNew + rowsNew) / rowsNew;
		fin.close();
	}
	this->rows = rowsNew;
	this->cols = colsNew;
	this->arrPointer = new double* [this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		this->arrPointer[i] = new double[this->cols];
	}

	fin.open(path);
	if (!fin.is_open())
	{
		//cout << "Error IN";
	}
	else
	{
		//cout << "file opened";
		char ch;
		int i = 0;
		int j = 0;
		string strNumb = "";
		while (fin.get(ch))
		{
			if (ch == '\n')
			{
				this->arrPointer[i][j] = stod(strNumb);
				strNumb = "";
				i += 1;
				j = 0;
				continue;
			}
			if (ch == ',')
			{
				this->arrPointer[i][j] = stod(strNumb);
				strNumb = "";
				j += 1;
				continue;
			}
			if (ch == ' ')
			{
				continue;
			}
			if ((ch != '\n') & (ch != ',') & (ch != ' '))
			{
				strNumb += ch;
			}
		}
		fin.close();
	}

}

MyMatrix::~MyMatrix()
{
	//cout << "d" << "\n";
	for (int i = 0; i < rows; i++)
	{
		delete[] arrPointer[i];
	}
	delete[] arrPointer;
}

MyMatrix::MyMatrix(const MyMatrix& other)
{
	//cout << "kop" << "\n";
	this->rows = other.rows;
	this->cols = other.cols;
	this->arrPointer = new double* [this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		this->arrPointer[i] = new double[this->cols];
	}

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			this->arrPointer[i][j] = other.arrPointer[i][j];
		}
	}
}


MyMatrix MyMatrix::operator*(const double mult)
{
	MyMatrix newMatrix(*this);// Why not MyMatrix* newMatrixx = new MyMatrix(*this);
	for (int i = 0; i < newMatrix.rows; i++)
	{
		for (int j = 0; j < newMatrix.cols; j++)
		{
			newMatrix.arrPointer[i][j] *= mult;
		}
	}
	return newMatrix;
	
}

MyMatrix& MyMatrix::operator=(const MyMatrix other)
{
	if (arrPointer != 0)
	{
		for (int i = 0; i < this->rows; i++)
		{
			delete[] this->arrPointer[i];
		}
		delete[] arrPointer;
	}

	this->rows = other.rows;
	this->cols = other.cols;

	this->arrPointer = new double* [this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		this->arrPointer[i] = new double[this->cols];
	}

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			this->arrPointer[i][j] = other.arrPointer[i][j];
		}
	}

	return *this;
}



MyMatrix MyMatrix::getTransposedMatrix()
{
	MyMatrix newMatrix(this->cols, this->rows);
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			newMatrix.arrPointer[j][i] = this->arrPointer[i][j];
		}
	}
	return newMatrix;
}

MyMatrix MyMatrix::getReverseMatrix()
{
	double det = (*this).det();
	if (this->cols != this->rows)
	{
		cout << "Matrix should be square!!!" << "\n";
		return *this; //What i should return?
	}
	else if (det == 0)
	{
		cout << "This Matrix doesnt have ReverseMatrix!!!" << "\n";
		return *this; //What i should return?
	}
	else
	{
		int mult = 1;
		MyMatrix transposedMatrix = (*this).getTransposedMatrix();
		MyMatrix confactorMatrix(transposedMatrix.getRows(), transposedMatrix.getCols());
		MyMatrix reverseMatrix(transposedMatrix.getRows(), transposedMatrix.getCols());

		for (int i = 0; i < transposedMatrix.rows; i++)
		{
			for (int j = 0; j < transposedMatrix.cols; j++)
			{
				confactorMatrix.arrPointer[i][j] = mult * transposedMatrix.CutRowAndCol(i, j).det();
				mult *= (-1);
			}
		}
		reverseMatrix = confactorMatrix * (1 / det);
		return reverseMatrix;
	}
}

void MyMatrix::fillRand()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arrPointer[i][j] = rand() % 23;
		}
	}
}

void MyMatrix::fillOneValue(int row, int col, int value)
{
	if (row < this->rows && col < this->cols)
	{
		this->arrPointer[row][col] = value;
	} else cout << "Element of Matrix doesnt exist";
}

double MyMatrix::getOneValue(int row, int col)
{
	return this->arrPointer[row][col];
}


double MyMatrix::det()
{
	if (this->cols != this->rows)
	{
		cout << "MatrixIsn'tSquare";
		return -1;
	}
	if (this->rows <= 2)
	{
		return this->arrPointer[0][0] * this->arrPointer[1][1] - this->arrPointer[1][0] * this->arrPointer[0][1];
	}
	else
	{
		double det = 0;
		int mult = 1;
		for (int i = 0; i < this->cols; i++)
		{
			det += mult * this->arrPointer[0][i] * (*this).CutRowAndCol(0, i).det();
			mult *= -1;
		}
		return det;
	}

}



void MyMatrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std:cout << arrPointer[i][j] << "\t";
		}
		std::cout << "\n\n";
	}
}

int MyMatrix::getRows()
{
	return this->rows;
}

void MyMatrix::setRowsAndCols(int rows, int cols)
{
	MyMatrix* newMatrix = new MyMatrix(rows, cols);
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i < this->rows && j < this->rows)
				(*newMatrix).arrPointer[i][j] = this->arrPointer[i][i];
			else 
				(*newMatrix).arrPointer[i][j] = 0;
		}
	}
	for (int i = 0; i < this->rows; i++)
	{
		delete[] this->arrPointer[i];
	}
	delete[] this->arrPointer;
	this->arrPointer = (*newMatrix).arrPointer;
	this->rows = rows;
	this->cols = cols;
}

int MyMatrix::getCols()
{
	return this->cols;
}

void MyMatrix::safeInCSV(string fileName)
{
	ofstream fout;
	fout.open(fileName);
	if (!fout.is_open())
	{
		cout << "error in fout";
	}
	else
	{
		cout << "all good in fout";
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (j == cols - 1)
				{
					fout << this->arrPointer[i][j] << '\n';
				}
				else
				{
					fout << this->arrPointer[i][j] << ',';
				}
			}

		}
		fout.close();
	}
}



MyMatrix MyMatrix::CutRowAndCol(int cutRow, int cutCol)
{
	MyMatrix newMatrix(this->rows - 1, this->cols - 1);
	int thisi = 0, thisj = 0, newi = 0, newj = 0;
	while (newi < newMatrix.rows)
	{
		if (thisi == cutRow) thisi++;
		while (newj < newMatrix.cols)
		{
			if (thisj == cutCol) thisj++;
			newMatrix.arrPointer[newi][newj] = this->arrPointer[thisi][thisj];
			thisj++;
			newj++;
		}
		thisi++;
		newi++;
		thisj = 0;
		newj = 0;
	}
	return newMatrix;
}
