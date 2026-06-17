//
// Created by HP on 17/06/2026.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <ostream>
using std::ostream ;

class Matrix {
private:
    int cols ;
    int rows ;
    int* data ;

public:
    Matrix(int rows, int cols);
    Matrix(int rows , int cols , int data);
    Matrix();
    ~Matrix();

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    int& operator()(int row, int col);
    const int& operator()(int row, int col) const;

    bool operator==(const Matrix& other)const ;
    bool operator!=(const Matrix& other)const ;

    Matrix transpose() const ;

    Matrix rotateClockwise() const;
    Matrix rotateCounterClockwise() const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    Matrix operator-() const;

    Matrix operator* (int scalar) const ;
    friend Matrix operator*(int scalar, const Matrix& matrix);

    Matrix& operator*=(int scalar);

    friend ostream& operator<<(ostream& os, const Matrix& m);
    static double CalcFrobeniusNorm(const Matrix& matrix);
};


#endif