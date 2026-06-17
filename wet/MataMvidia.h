//
// Created by HP on 17/06/2026.
//

#ifndef MATAMVIDIA_H
#define MATAMVIDIA_H
#include "matrix.h"
class MataMvidia {
    private :
        std::string filmName ;
    std::string creator ;
    int framesNum ;
    Matrix* frames ;

    public :
        MataMvidia(const std::string filmName, const std::string creator, const Matrix *frames, const int framesNum);
    ~MataMvidia();
    MataMvidia(const MataMvidia& other);
    MataMvidia& operator=(const MataMvidia& other);
    const Matrix& operator[](int indexPlace) const ;
    Matrix& operator[](int indexPlace) ;
    MataMvidia& operator+=(const MataMvidia& other);
    MataMvidia& operator+=(const Matrix& other);
    MataMvidia operator+(const MataMvidia& other)const;
    friend std::ostream& operator<<(std::ostream& os, const MataMvidia& movie);
} ;
#endif //MATAMVIDIA_H
