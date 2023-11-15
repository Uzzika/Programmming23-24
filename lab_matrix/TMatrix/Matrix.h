// Copyright (c) Dudchenko Olesya Victorovna

#ifndef INCLUDE_MATRIX_H_
#define INCLUDE_MATRIX_H_

#include <iostream>
#include "../TVector/Vector.h"

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

//шаблон матрицы
template<typename T>
class TMatrix : private TVector<TVector<T>> {
    using TVector<TVector<T>>::pMem;
    using TVector<TVector<T>>::size;
public:
    TMatrix(size_t s = 1) : TVector<TVector<T>>(s) {
        if (_size == 0)
            throw std::length_error("Matrix size should be greater than zero");
        if (_size > MAX_MATRIX_SIZE)
            throw std::length_error("Matrix size cannot be greater than MAX_MATRIX_SIZE = 10000");
        for (size_t i = 0; i < _size; i++)
            pMem[i] = TVector<T>(_size);
    }
    // почему можно сделать так? Объяснить.
    using TVector<TVector<T>>::operator[];

    // сравнение
    bool operator==(const TMatrix& m) const noexcept {
        if (_size != m._size) { throw std::logic_error("Sizes are not equal."); }
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                if (pMem[i][j] != m.pMem[i][j])
                    return 0;
            }
        }
        return 1;
    }
    bool operator!=(const TMatrix& m) const noexcept {
        return !(*this == m);
    }

    // матрично-скалярные операции
    TMatrix operator*(const T& val) {
        TMatrix scalar(*this);
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                pMem[i][j] *= val;
            }
        }
        return scalar;
    }

    // матрично-векторные операции
    TVector<T> operator*(const TVector<T>& v) {
        TVector<T> matrix_vector(_size);
        for (int i = 0; i < _size; i++) {
            matrix_vector[i] = 0;
            for (int k = 0; k < _size; k++) {
                matrix_vector[i] += this->pMem[k][i] * v.pMem[k];
            }
        }
        return matrix_vector;
    }

    // матрично-матричные операции
    TMatrix operator+(const TMatrix& m) {
        if (this->_size != m._size)
            throw std::length_error("Dimension error");
        TMatrix result(*this);
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                pMem[i][j] += m.pMem[i][j];
            }
        }
        return result;
    }
    TMatrix operator-(const TMatrix& m) {
        if (this->_size != m._size)
            throw std::length_error("Dimension error");
        TMatrix result(*this);
        for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                pMem[i][j] -= m.pMem[i][j];
            }
        }
        return result;
    }

    TMatrix operator*(const TMatrix& m){ //спорный моментик, чекнем, работает или нет
        if(_size != v._size)
        throw std::logic_error("Sizes are not equal"); 
        }
        TMatrix result(*this);
        for (size_t i = 0; i < size; i++) {
            for (size_t j = 0; j < size; j++) {
                for (int inner = 0; inner < size - 1; inner++) {
                    result[i][j] += m.pMem[i][inner] * bMatrix[inner][j];
                }
            }
        }
        return result;
    };

// ввод/вывод
template <class T>
std::istream& operator>>(std::istream& istr, TMatrix<T>& m) {
    for (int i = 0; i < m._size; i++) {
        for (int k = 0; k < m._size; k++) {
            istr >> m[i][k];
        }
    }
    return istr;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const TMatrix<T>& m) {
    for (int i = 0; i < m._size; i++) {
        for (int k = 0; k < m._size; k++) {
            ostr << m[i][k];
        }
    }
    return ostr;
}

#endif  // INCLUDE_MATRIX_H_
