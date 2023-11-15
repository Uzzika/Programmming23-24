// Copyright (c) Dudchenko Olesya Victorovna

#ifndef INCLUDE_VECTOR_H_
#define INCLUDE_VECTOR_H_

#include <iostream>

const int MAX_VECTOR_SIZE = 100000000;

template<typename T>
class TVector {
protected:
    size_t _size;
    T* pMem;
public:
    TVector(size_t _size = 1) : _size(_size) {
        if (_size == 0)
            throw std::length_error("Vector size should be greater than zero");
        if (_size > MAX_VECTOR_SIZE)
            throw std::length_error("Vector size cannot be greater than MAX_VECTOR_SIZE = 100000000");
        pMem = new T[_size]();
    }

    TVector(T* data, size_t size) : _size(size) {
        // еще один способ ввода исключений
        assert(data != nullptr && "TVector constructor requires non-nullptr argument.");
        pMem = new T[size];
        // дл€ массивов можно использовать std-функции с условием, что вы знаете как они там реализованы!
        std::copy(data, data + size, pMem);
    }

    TVector(const TVector& v) {
        _size = v._size;
        pMem = v.pMem;
    }

    ~TVector() {
        delete[] pMem;
        pMem = nullptr;
    }

    TVector(TVector&& v) : _size(0), pMem(nullptr) {
        std::swap(_size, v._size);
        std::swap(pMem, v.pMem);
    }

    TVector& operator=(const TVector& v) {
        this->_size = v._size;
        this->pMem = new T[_size];
        std::copy(v.pMem, v.pMem + _size, pMem);
        return *this;
    }

    TVector& operator=(TVector&& v) {
        this->_size = 0;
        this->pMem = nullptr;
        std::swap(this->_size, v._size);
        std::swap(this->pMem, v.pMem);
        return *this;
    }

    size_t size() const noexcept {
        return _size;
    }

    // индексаци€
    T& operator[](size_t ind) {
        if (ind < 0 || ind > MAX_VECTOR_SIZE) {
            throw std::logic_error("The index cannot have this value.");
        }
        return this->pMem[ind];
    }
    const T& operator[](size_t ind) const {
        return pMem[ind];
    }

    // индексаци€ с контролем - почитать в чем разница и объ€снить при сдаче работы
    T& at(size_t ind) {
        if (ind < 0 || ind >= _size) {
            throw std::length_error("Vector[index] out of range");
        }
        else {
            return pMem[ind];
        }
    }
    const T& at(size_t ind) const {
        if (ind < 0 || ind >= _size) {
            throw std::length_error("Vector[index] out of range");
        }
        else {
            return pMem[ind];
        }
    }

    // сравнение
    bool operator==(const TVector& v)const noexcept {
        if (_size != v._size) {
            throw std::logic_error("Vectors have different sizes");
        }
        TVector<T> res(*this);
        for (auto i = 0; i < _size; i++) {
            res[i] == v[i];
        }
    }
    bool operator!=(const TVector& v) const noexcept {
        return !(*this == v);
    }

    TVector operator+(T val) {
        TVector<T> Ret(*this);
        for (int i = 0; i < _size; i++) {
            Ret[i] += val;
        }
        return Ret;
    }
    TVector operator-(T val) {
        TVector<T> Ret(*this);
        for (int i = 0; i < _size; i++) {
            Ret[i] -= val;
        }
        return Ret;
    }
    TVector operator*(T val) {
        TVector<T> Ret(*this);
        for (int i = 0; i < _size; i++) {
            Ret[i] *= val;
        }
        return Ret;
    }

    TVector operator*(T val) {
        TVector<T> Ret(*this);
        for (int i = 0; i < _size; i++) {
            Ret[i] *= val;
        }
        return Ret;
    }

    TVector operator+(const TVector& v) {
        if (_size != v._size)
            throw std::length_error("Dimension error");
        TVector<T> Ret(*this);
        for (int i = 0; i < _size; i++) {
            Ret[i] += v[i];
        }
        return Ret;
    }
    TVector operator-(const TVector& v) {
        if (_size != v._size)
            throw std::length_error("Dimension error");
        TVector<T> Ret(*this);
        for (int i = 0; i < _size; i++) {
            Ret[i] -= v[i];
        }
        return Ret;
    }
    //нифига не понимаю, но надо разобратьс€

    // почитать о noexcept(noexcept(T())) - объ€снить назначение при сдаче
    T operator*(const TVector& v) noexcept(noexcept(T())) {
        if (_size != v._size)
            throw std::length_error("Dimension error");
        T ScalarP = 0;
        for (int i = 0; i < _size; i++) {
            ScalarP += (*this)[i] * v[i];
        }
        return ScalarP;
    }

    friend void swap(TVector& lhs, TVector& rhs) noexcept;

    // ввод/вывод
    friend std::istream& operator>>(std::istream& istr, TVector& v);
    friend std::ostream& operator<<(std::ostream& ostr, const TVector& v);
};

template <class T>
void swap(TVector<T>& lhs, TVector<T>& rhs) noexcept {
    std::swap(lhs._size, rhs._size);
    std::swap(lhs.pMem, rhs.pMem);
}

// ввод/вывод
template <class T>
std::istream& operator>>(std::istream& istr, TVector<T>& v) {
    for (size_t i = 0; i < v._size; i++)
        istr >> v.pMem[i];
    return istr;
}
template <class T>
std::ostream& operator<<(std::ostream& ostr, const TVector<T>& v) {
    for (size_t i = 0; i < v._size; i++)
        ostr << v.pMem[i] << ' ';
    return ostr;
}

#endif INCLUDE_VECTOR_H_