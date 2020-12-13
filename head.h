#pragma once
#include <ostream>
using namespace std;
class Matrix {
private:
    int rows;
    int cols;
    float** con;
public:
    Matrix(int row, int col);
    Matrix(int row, int col, float** in);
    Matrix(const Matrix& B);
    ~Matrix();

    Matrix  operator =(const Matrix&);
    float* toArray(Matrix m);
    Matrix& operator *(Matrix m);
    //Matrix& operator *(float k);
    friend Matrix& operator *(float k,Matrix m);

    friend istream& operator>>(istream& is, Matrix& m);
    friend std::ostream& operator <<(std::ostream& os, Matrix& m);
};