#ifndef VECTOR_H
#define VECTOR_H

#include "dmassive.h"

template <typename T>
class TVector {
public:
    TVector() : _data(), _start_index(0) {}
    TVector(size_t size) : _data(size), _start_index(0) {}
    TVector(const TVector<T>& other) : _data(other._data), _start_index(other._start_index) {}

    T& operator[](size_t index) {
        if (index >= _data.size() || index < _start_index) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index - _start_index];
    }

    const T& operator[](size_t index) const {
        if (index >= _data.size() || index < _start_index) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index - _start_index];
    }

    TVector<T> operator+(const TVector<T>& other) const {
        if (_data.size() - _start_index != other._data.size() - other._start_index) {
            throw std::logic_error("Vectors have different sizes");
        }
        TVector<T> result;
        result._data.resize(_data.size() - _start_index);
        for (size_t i = 0; i < _data.size() - _start_index; ++i) {
            result._data[i] = _data[i + _start_index] + other._data[i + other._start_index];
        }
        return result;
    }

    TVector<T> operator-(const TVector<T>& other) const {
        if (_data.size() - _start_index != other._data.size() - other._start_index) {
            throw std::logic_error("Vectors have different sizes");
        }
        TVector<T> result;
        result._data.resize(_data.size() - _start_index);
        for (size_t i = 0; i < _data.size() - _start_index; ++i) {
            result._data[i] = _data[i + _start_index] - other._data[i + other._start_index];
        }
        return result;
    }

    TVector<T> operator*(T scalar) const {
        TVector<T> result;
        result._data.resize(_data.size() - _start_index);
        for (size_t i = 0; i < _data.size() - _start_index; ++i) {
            result._data[i] = _data[i + _start_index] * scalar;
        }
        return result;
    }

    TVector<T>& operator+=(const TVector<T>& other) {
        if (_data.size() - _start_index != other._data.size() - other._start_index) {
            throw std::logic_error("Vectors have different sizes");
        }
        for (size_t i = 0; i < _data.size() - _start_index; ++i) {
            _data[i + _start_index] += other._data[i + other._start_index];
        }
        return *this;
    }

    TVector<T>& operator-=(const TVector<T>& other) {
        if (_data.size() - _start_index != other._data.size() - other._start_index) {
            throw std::logic_error("Vectors have different sizes");
        }
        for (size_t i = 0; i < _data.size() - _start_index; ++i) {
            _data[i + _start_index] -= other._data[i + other._start_index];
        }
        return *this;
    }

    TVector<T>& operator*=(T scalar) {
        for (size_t i = 0; i < _data.size() - _start_index; ++i) {
            _data[i + _start_index] *= scalar;
        }
        return *this;
    }

    bool operator==(const TVector<T>& other) const {
        if (_data.size() - _start_index != other._data.size() - other._start_index) {
            return false;
        }
        for (size_t i = 0; i < _data.size() - _start_index; ++i) {
            if (_data[i + _start_index] != other._data[i + other._start_index]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const TVector<T>& other) const {
        return !(*this == other);
    }

    size_t size() const {
        return _data.size() - _start_index;
    }

    T dotProduct(const TVector<T>& other) const {
        if (_data.size() - _start_index != other._data.size() - other._start_index) {
            throw std::logic_error("Vectors have different sizes");
        }
        T result = 0;
        for (size_t i = 0; i < _data.size() - _start_index; ++i) {
            result += _data[i + _start_index] * other._data[i + other._start_index];
        }
        return result;
    }

private:
    TDMassive<T> _data; 
    size_t _start_index; 
};

#endif // VECTOR_H

