#include "LogicMatrix.h"

std::ostream& operator<<(std::ostream& OurOut, LogicMatrix& OurLogicMatrix)
{
	setlocale(LC_ALL, "RUS");
	OurOut << "���� �������: \n";
	for (int i = 0; i < OurLogicMatrix.rows; i++) {
		for (int j = 0; j < OurLogicMatrix.colums; j++) {
			OurOut << OurLogicMatrix.OurLogicMatrix[i][j] << " ";
		}
		OurOut << std::endl;
	}
	return OurOut;
}

std::istream& operator>>(std::istream& OurIn, LogicMatrix& OurLogicMatrix)
{
	//���� �����������, ��� ������ ����� ������� � �������������������� �������
	try {
		if (OurLogicMatrix.OurLogicMatrix == NULL) throw "Exeption! OurMatrix is not initialized\n";
		for (int i = 0; i < OurLogicMatrix.rows; i++) {
			for (int j = 0; j < OurLogicMatrix.colums; j++) {
				OurIn >> OurLogicMatrix.OurLogicMatrix[i][j];
			}
		}
	}
	catch (const char& string) {
		std::cout << string;
	}
	return OurIn;
}

LogicMatrix& operator||(LogicMatrix& Left, LogicMatrix& Right)
{
	try
	{
		if (Left.OurLogicMatrix == nullptr || Right.OurLogicMatrix == nullptr) throw "Exception! Matrix isn't initilazed \n";
		static LogicMatrix Result(Right.colums, Right.rows);
		for (int i = 0; i < Left.rows; i++) {
			for (int j = 0; j < Left.colums; j++) {
				if (Left.OurLogicMatrix[i][j] || Right.OurLogicMatrix[i][j])
					Result.OurLogicMatrix[i][j] = true;
				else
					Result.OurLogicMatrix[i][j] = false;
			}
		}
		return Result;
	}
	catch (const char* ExceptionString)
	{
		std::cout << ExceptionString;
	}
}

LogicMatrix& operator&&(LogicMatrix& Left, LogicMatrix& Right)
{
	try
	{
		if (Left.OurLogicMatrix == nullptr || Right.OurLogicMatrix == nullptr) throw "Exception! Matrix isn't initilazed \n";
		static LogicMatrix Result(Right.colums, Right.rows);
		for (int i = 0; i < Left.rows; i++) {
			for (int j = 0; j < Left.colums; j++) {
				if (Left.OurLogicMatrix[i][j] && Right.OurLogicMatrix[i][j])
					Result.OurLogicMatrix[i][j] = true;
				else
					Result.OurLogicMatrix[i][j] = false;
			}
		}
		return Result;
	}
	catch (const char* ExceptionString)
	{
		std::cout << ExceptionString;
	}
}

LogicMatrix& operator!(LogicMatrix& Left)
{
	try
	{
		if (Left.OurLogicMatrix == nullptr) throw "Exception! Matrix isn't initilazed \n";
		static LogicMatrix Result(Left.colums, Left.rows);
		for (int i = 0; i < Left.rows; i++) {
			for (int j = 0; j < Left.colums; j++) {
				if (Left.OurLogicMatrix[i][j]) Result.OurLogicMatrix[i][j] = false;
				else Result.OurLogicMatrix[i][j] = true;
			}

		}
	}
	catch (const char * ExceptionString)
	{
		std::cout << ExceptionString;
	}

}



LogicMatrix::LogicMatrix()
{
	OurLogicMatrix = NULL;
}

LogicMatrix::LogicMatrix(int& col, int& rows, bool** MatrixPtr)
{
	this->colums = col;
	this->rows = rows;
	this->OurLogicMatrix = new bool* [this->rows];
	for (int i = 0; i < rows; i++) {
		this->OurLogicMatrix[i] = new bool[this->colums];
	}
	this->OurLogicMatrix = MatrixPtr;
}

LogicMatrix::LogicMatrix(int& col, int& rows)
{
	this->colums = col;
	this->rows = rows;
	this->OurLogicMatrix = new bool* [this->rows];
	for (int i = 0; i < rows; i++) {
		this->OurLogicMatrix[i] = new bool[this->colums];
	}
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->colums; j++) {
			this->OurLogicMatrix[i][j] = 0;
		}
	}
}

LogicMatrix::~LogicMatrix()
{
	if (this->OurLogicMatrix[0] != NULL) {
		for (int i = 0; i < this->rows; ++i) {
			delete this->OurLogicMatrix[i];
		}
		delete this->OurLogicMatrix;
		this->OurLogicMatrix[0] = NULL;
	}
	
}

bool** LogicMatrix::get_matrix()
{
	return this->OurLogicMatrix;
}

LogicMatrix& LogicMatrix::operator=(const LogicMatrix& OurMatrix)
{
	this->OurLogicMatrix = OurMatrix.OurLogicMatrix;
	this->rows = OurMatrix.rows;
	this->colums = OurMatrix.colums;
	return *this;
}

void LogicMatrix::set_matrix(int& col, int& rows)
{
	this->colums = col;
	this->rows = rows;
	this->OurLogicMatrix = new bool* [this->rows];
	for (int i = 0; i < rows; i++) {
		this->OurLogicMatrix[i] = new bool[this->colums];
	}
}

void LogicMatrix::random_matrix()
{
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->colums; ++j) {
			this->OurLogicMatrix[i][j] = rand() % 2;
		}
	}
}
