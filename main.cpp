#include <iostream>
#include "head.h"

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
    this->con = new float* [row];
    float** pbr = data,  * pb, * endb,
            ** par = this->con, ** endar = this->con + this->rows, * pa, * enda;
    do
    {
        pa = *(par++) = new float[column];
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
    if (this->cols != m.rows) {
        cout << "Doesn't Match!" << endl;
        return m;
    }
    else
    {
        Matrix result (this->rows, m.cols);
        int n = this->cols;
        int r = result.rows;
        int c = result.cols;
        float s = 0;
        result.con = new float* [result.rows];
        for (int i = 0; i < result.rows; i++)
        {
            result.con[i] = new float[result.cols];
            for (int j = 0; j < result.cols; j++)
            {
                result.con[i][j] = 0;
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int k = 0; k < n; k++)
            {
                s = this->con[i][k];
                for (int j = 0; j < c; j++)
                {
                    result.con[i][j] += s * m.con[k][j];
                }
            }
        }
        return result;
    }

}
float* Matrix:: toArray(Matrix m) {
    float* ans = new float[sizeof(m.rows)*sizeof(m.cols) / (sizeof(float)*sizeof(float*))];
    return ans;
}

Matrix& operator *(float k,Matrix in) {

    for (int  i = 0; i < in.rows; i++)
    {
        for (int j = 0; j < in.cols; j++)
        {
            in.con[i][j] *= k;
        }
    }
    return in;
}


istream& operator>>(istream& is, Matrix &m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            is >> *(*(m.con+i)+j);
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


    return os;
}


