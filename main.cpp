#include <iostream>
#include "head.h"
#include<xmmintrin.h>
using namespace std;
Matrix::Matrix(int row,int col) {
	this->rows = row;
	this->cols = col;
	con = new float* [rows];
	for (int i = 0; i < rows; i++)
	{
		con[i] = new float[cols];
	}
	//cout << row << " " << col << endl;
	//cout << rows << " " << cols << endl;
}
Matrix::Matrix(int row, int column, float** data)
{
	
	this->rows = row;
	this->cols = column;
	this->con = new float* [row];// (float**)malloc(column * sizeof(float*));
	float** pbr = data,  * pb, * endb,
		** par = this->con, ** endar = this->con + this->rows, * pa, * enda;//endbr = data + column,
	do
	{
		pa = *(par++) = new float[column];// (float*)malloc(this->rows * sizeof(float));
		enda = pa + this->cols;
		pb = *(pbr++);
		endb = pb + this->cols;
		do
		{
			*(pa++) = *(pb++);
		} while (pa != enda);
	} while (par != endar);
	//cout << row<<" "<<column << endl;
	//cout << rows << " " << cols << endl;
}
Matrix::Matrix(const Matrix& m)
{
	this->rows = m.rows;
	this->cols = m.cols;
	con = new float* [rows];// (float**)malloc(cols * sizeof(float*));
	float** pbr = m.con, * pb, * endb,
		** par = this->con, ** endar = this->con + this->rows, * pa, * enda;//** endbr = m.con + cols, 
	do
	{
		pa = *(par++) = new float[cols];// (float*)malloc(this->rows * sizeof(float));
		enda = pa + this->cols;
		pb = *(pbr++);
		endb = pb + this->cols;
		do
		{
			*(pa++) = *(pb++);
		} while (pa != enda);
	} while (par != endar);

}

Matrix::~Matrix() {
	//for (int i = 0; i < rows; ++i) {
	//	delete[] con[i];
	//}
	//delete[] con;
}


Matrix Matrix::operator = (const Matrix& m) {
	this->rows = m.rows;
	this->cols = m.cols;
	con = new float* [rows];// (float**)malloc(cols * sizeof(float*));
	float** pbr = m.con, * pb, * endb,
		** par = this->con, ** endar = this->con + this->rows, * pa, * enda;//** endbr = m.con + cols, 
	do
	{
		pa = *(par++) = new float[cols];// (float*)malloc(this->rows * sizeof(float));
		enda = pa + this->cols;
		pb = *(pbr++);
		endb = pb + this->cols;
		do
		{
			*(pa++) = *(pb++);
		} while (pa != enda);
		} while (par != endar);

	return *this;
}
Matrix& Matrix::operator *(Matrix m) {
	Matrix buff(this->rows, m.cols);

	return buff;
}
void ComputeArraySSE(float* pArray1, float* pArray2, float* pResult, int nSize) {
	int nLoop;
	int i = 0;
	int j = 0;
	__m128 m1, m2, m3;
	float* p1;
	float* p2;
	float* pr;
	p1 = pArray1;
	p2 = pArray2;
	pr = pResult;
	nLoop = nSize / 4;
	for (i = 0; i < nLoop && pr != NULL; i++) {
		m1 = _mm_loadu_ps(p1);
		m2 = _mm_loadu_ps(p2);
		m3 = _mm_mul_ps(m1, m2);
		_mm_storeu_ps(pr, m3);
		p1 += 4;
		p2 += 4;
		pr += 4;
	}
	j = nSize % 4;
	if (j != 0) {
		printf("The SSE request array size of times of 4.\n");
	}
}

Matrix& operator *(float k,Matrix in) {
	Matrix m(in);
	for (int  i = 0; i < m.rows; i++)
	{
		for (int j = 0; j < m.cols; j++)
		{
			m.con[i][j] *= k;
		}
	}
	return m;
}


istream& operator>>(istream& is, Matrix &m) {
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			is >> m.con[i][j];
		}
	}
	return is;
}
std::ostream& operator <<(std::ostream& os, Matrix& m) {
	for (int i = 0; i < m.rows; i++) {
		for (int j = 0; j < m.cols; j++) {
			os << m.con[i][j] << " ";
		}
		os << endl;
	}
	//os << m.rows << " " << m.cols << endl;

	return os;
}


