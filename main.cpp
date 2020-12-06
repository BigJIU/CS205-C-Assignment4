#include <iostream>
#include "head.h"
Matrix::Matrix(int row,int col) {
	rows = row;
	cols = col;
	float** con = new float*[row];
	for (int i = 0; i < row; i++)
	{
		float* buffer = new float[cols];
		con[i] = buffer;
	}
}
Matrix::~Matrix() {
	delete[] this->con;
}
std::ostream& operator <<(std::ostream& os, Matrix m) {
	
	return os;
}

Matrix& Matrix::operator = (Matrix m) {

}
Matrix& Matrix::operator *(Matrix m) {

}
Matrix& Matrix::operator *(float k) {

}
float& operator *(Matrix m) {

}

void Matrix:: test() {
	cout << rows << endl;
}
int main() {
	Matrix a(1,5);
	a.test();
}