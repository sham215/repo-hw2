//
// Created by HP on 17/06/2026.
#include "Matrix.h"
#include <cmath>
#include "Utilities.h"
using std::endl ;

Matrix::Matrix(const int rows , const int cols) {
    data = new int[rows*cols];
    this->rows=rows ;
    this->cols=cols;
    for (int i = 0 ; i < rows*cols ; i++) {
        data[i] = 0 ;
    }
}

Matrix::Matrix(const int rows , const int cols , const int dataVal) {
    this->rows = rows ;
    this->cols = cols ;
    data = new int[rows*cols] ;
    for (int i = 0 ; i < rows*cols ; i++) {
        data[i] = dataVal ;
    }
}

Matrix::Matrix() {
    rows = 0 ;
    cols = 0 ;
    data = nullptr ;
}
// בונה מערך עם  0 שורות ו 0 עמודות
Matrix::~Matrix() {
    delete[] data;
}


Matrix::Matrix(const Matrix& other) {
    this->cols = other.cols ;
    this->rows= other.rows ;
    if ((rows == 0) || (cols == 0)) {
        data = nullptr ;
        return ;
    }
    data = new int[rows * cols];
    for (int i = 0 ; i < rows*cols ; i++) {
        data[i]= other.data[i];
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }
    delete[] data;
    cols = other.cols ;
    rows = other.rows ;

    if ((rows == 0) || (cols == 0)) {
        data = nullptr ;
        return *this ;
    }

    data = new int [rows*cols] ;

    for (int i = 0 ; i < cols*rows ; i++) {
        data[i] = other.data[i] ;
    }
    return *this ;
}

// גישה לאיבר במטריצה לכתיבה
int& Matrix::operator()(const int row , const int col) {
    if (row < 0 || row >= rows ) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    if (col < 0 || col >= cols) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return data[row * cols + col];
}
const int& Matrix::operator()(int row , int col)const {
    if (row < 0 || row >= rows ) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    if (col < 0 || col >= cols) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return data[row * cols + col] ;
}

ostream& operator<<(ostream& os, const Matrix& matrix) {
    if (matrix.rows == 0 || matrix.cols == 0 ) {
        return os;
    }
    for (int i = 0 ; i < matrix.rows ; i++) {
        os << "|" ;
        for ( int j = 0 ; j < matrix.cols ; j++) {
            os << matrix.data[i * matrix.cols + j];
            os << "|" ;
        }
        os << endl ;
    }
    return os ;
}

bool Matrix::operator==(const Matrix& other) const {
    if ((this->cols != other.cols) || (this->rows != other.rows)) {
        return false ;
    }
    for (int i = 0 ; i < cols*rows ; i++) {
        if (data[i] != other.data[i]) {
            return false ;
        }
    }
    return true ;
}

bool Matrix::operator!=(const Matrix& other) const {
    return (!(*this == other)) ;
}

Matrix Matrix::transpose() const {
    Matrix transposed(cols,rows);

    for (int i = 0 ; i < rows; i ++) {
        for ( int j = 0 ; j < cols ; j++) {
            transposed(j, i) = data[i * cols + j];
        }
    }
    return transposed ;
}

Matrix Matrix::rotateClockwise() const {
    Matrix rotated(cols, rows);
    for (int i = 0 ; i < rows; i ++) {
        for ( int j = 0 ; j < cols ; j++) {
            rotated(j, rows - 1 - i) = data[i * cols + j];
        }
    }
    return rotated ;
}

Matrix Matrix::rotateCounterClockwise() const {
    Matrix rotated(cols, rows);
    for (int i = 0 ; i < rows; i ++) {
        for ( int j = 0 ; j < cols ; j++) {
            rotated(cols - 1 - j, i) = data[i * cols + j];
        }
    }
    return rotated ;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if ((cols != other.cols ) || ( rows != other.rows)) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    Matrix Sum(rows,cols);
    for (int index = 0 ; index < rows*cols ; index ++) {
        Sum.data[index] = data[index] + other.data[index] ;
    }
    return Sum ;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if ((cols != other.cols ) || ( rows != other.rows)) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    Matrix Sum(rows,cols);
    for (int index = 0 ; index < rows*cols ; index ++) {
        Sum.data[index] = data[index] - other.data[index] ;
    }
    return Sum ;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        exitWithError(MatamErrorType::UnmatchedSizes) ;
    }
    Matrix result (rows , other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            int sum = 0;
            for (int k = 0; k < cols; k++) {
                sum += data[i * cols + k] *
                       other.data[k * other.cols + j];
            }
            result.data[i * other.cols + j] = sum;
        }
    }
    return result ;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other ;
    return *this ;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other ;
    return *this ;
}

Matrix& Matrix::operator*=(const Matrix &other) {
    *this = *this * other ;
    return *this ;
}

Matrix Matrix::operator-() const {
    Matrix result (rows , cols );
    for (int index = 0 ; index <rows*cols ; index ++) {
        result.data[index] = data[index]*(-1);
    }
    return result ;
}
Matrix Matrix::operator*(int scalar) const {
    Matrix result(rows,cols);
    for (int index = 0 ; index < rows*cols ; index++){
        result.data[index] = data[index]*scalar;
    }
    return result ;
}

  Matrix operator*(const int scalar , const Matrix& matrix) {
    Matrix result (matrix.rows , matrix.cols) ;
    for ( int index = 0 ; index < matrix.rows*matrix.cols ; index ++) {
        result.data[index] = matrix.data[index] * scalar;
    }
    return result ;
}

 Matrix& Matrix::operator*=(int scalar) {

    *this = *this * scalar ;
    return *this ;
}


double Matrix::CalcFrobeniusNorm(const Matrix& matrix) {
    long long sum = 0;

    for (int index = 0; index < matrix.rows * matrix.cols; index++) {
        int value = matrix.data[index];
        sum += value * value;
    }
    return sqrt(static_cast<double>(sum));
}
