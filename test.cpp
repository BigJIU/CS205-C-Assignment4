#include<iostream>
#include "head.h"
using namespace std;
int main() {
    float** arr = new float* [2];
    for (int i = 0; i < 2; i++)
        arr[i] = new float[3];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
        {
            arr[i][j] = i*4 + j;
        }


    Matrix a(2, 3, arr);
    Matrix b(2, 3);

    cout << a << endl;//"a:"<<endl<<
    b = a;
    cout << b<<endl;

    Matrix c(a);
    cout << c << endl;
    c = 2.0f * c;
    cout << c << endl;
    Matrix d(3, 2);
    cin >> d;
    cout << d<<endl;

    Matrix e = a * d;
    cout << e << endl;

    float k = 0;
    cin >> k;
    b = k * b;
    cout << b;


}