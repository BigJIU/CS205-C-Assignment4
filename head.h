#pragma once
#include <ostream>
using namespace std;
class Matrix {
private:
	int rows;
	int cols;
	float** con;
public:
	Matrix(int row,int col);
	~Matrix();
	friend std::ostream& operator <<(std::ostream& os, Matrix m);
	Matrix&  operator =( Matrix m);
	Matrix& operator *(Matrix m);
	Matrix& operator *(float k);
	friend float& operator *(Matrix m);
	void test();
};