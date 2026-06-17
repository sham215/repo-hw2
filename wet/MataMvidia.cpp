//
// Created by HP on 17/06/2026.
//

#include "Matrix.h"
#include "MataMvidia.h"
#include "Utilities.h"
using std::endl ;
using std::string ;
using std::ostream ;


MataMvidia::MataMvidia( const string filmName , const string creator , const Matrix* frames , const int framesNum ) {
    this->filmName=filmName ;
    this->creator=creator;
    this->framesNum=framesNum;
    this->frames=new Matrix[framesNum] ;

    for (int index = 0 ; index < framesNum ; index ++) {
        this->frames[index]=frames[index];
    }
}
MataMvidia::~MataMvidia(){
    delete[] frames;
} ;
MataMvidia::MataMvidia(const MataMvidia& other) {
    filmName=other.filmName ;
    creator=other.creator ;
    framesNum=other.framesNum ;

    frames = new Matrix[framesNum];

    for (int index = 0 ; index <framesNum ; index++) {
        frames[index]=other.frames[index];
    }
}
    MataMvidia& MataMvidia::operator=(const MataMvidia& other) {
    if (this == &other) {
        return *this ;
    }
    this->filmName=other.filmName ;
    this->creator=other.creator ;
    this->framesNum=other.framesNum ;
    delete []frames ;
    frames=new Matrix[other.framesNum];
    for (int index = 0 ; index < other.framesNum ; index ++) {
        this->frames[index]=other.frames[index];
    }
    return *this;
}
const Matrix& MataMvidia::operator[](int indexPlace)const{
    if (indexPlace < 0 || indexPlace >= framesNum) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[indexPlace];

}
Matrix &MataMvidia::operator[](int indexPlace) {
    if (indexPlace < 0 || indexPlace >= framesNum) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[indexPlace];

}
MataMvidia& MataMvidia::operator+=(const MataMvidia& other) {
    Matrix* frames2 = new Matrix[framesNum+other.framesNum];

    for (int index = 0 ; index < framesNum ; index++) {
        frames2[index] = frames[index];
    }

    for ( int index = 0 ; index < other.framesNum ; index++) {
        frames2[framesNum+index] = other.frames[index] ;
    }
    delete[]frames ;
    frames = frames2 ;
    framesNum = framesNum + other.framesNum ;
    return *this ;
}

MataMvidia& MataMvidia::operator+=(const Matrix& other) {
    framesNum+=1;
    Matrix* newFrame = new Matrix[framesNum];
    for (int index=0 ; index < framesNum-1 ; index++) {
        newFrame[index] = frames[index] ;
    }
    newFrame[framesNum-1]=other ;
    delete[]frames;
    frames=newFrame ;
    return *this ;
}
MataMvidia MataMvidia::operator+(const MataMvidia& other)const {
    MataMvidia result(*this);   // copy constructor
    result += other;
    return result ;
}
    ostream& operator<<(ostream& os, const MataMvidia& movie) {
    os << "Movie Name: " << movie.filmName << std::endl ;
    os << "Author: " << movie.creator << endl ;
    os << endl ;
    for (int index = 0 ; index <movie.framesNum ; index ++) {
        os << "Frame " << index << ":" << endl;
        os << movie.frames[index] << endl;
    }
    os << "-----End of Movie-----" << endl;
    return os ;

};


