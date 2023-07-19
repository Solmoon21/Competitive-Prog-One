#include "Matrix.h"

Matrix::Matrix(int n){
    len = n;
    matrix.reserve(n);
    for(int i=0;i<n;i++){
        matrix[i].reserve(n);
    }
}

Matrix Matrix::operator*(Matrix b){
    Matrix res = Matrix(len);
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            for(int k=0;k<len;k++){
                res.matrix[i][j] += matrix[i][k]*b.matrix[k][j];
            }
        }
    }
    return res;
}