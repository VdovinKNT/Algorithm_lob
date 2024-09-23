#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <typename T>
class TVector {
public:
    // ������������
    TVector() : _data(nullptr), _size(0), _capacity(0) {}

    TVector(size_t size) : _data(new T[size]), _size(size), _capacity(size) {}

    TVector(const TVector<T>& other) : _data(new T[other._size]),
        _size(other._size),
        _capacity(other._size) {
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }

    // ����������
    ~TVector() {
        delete[] _data;
    }

    // ��������� �������
    T& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index];
    }

    // ��������� �������� � ���������
    TVector<T> operator+(const TVector<T>& other) const {
        if (_size != other._size) {
            throw std::logic_error("Vectors have different sizes");
        }
        TVector<T> result(_size);
        for (size_t i = 0; i < _size; ++i) {
            result._data[i] = _data[i] + other._data[i];
        }
        return result;
    }

    TVector<T> operator-(const TVector<T>& other) const {
        if (_size != other._size) {
            throw std::logic_error("Vectors have different sizes");
        }
        TVector<T> result(_size);
        for (size_t i = 0; i < _size; ++i) {
            result._data[i] = _data[i] - other._data[i];
        }
        return result;
    }

    // �������� ��������� �� �����
    TVector<T> operator*(T scalar) const {
        TVector<T> result(_size);
        for (size_t i = 0; i < _size; ++i) {
            result._data[i] = _data[i] * scalar;
        }
        return result;
    }

    // ��������� ������������
    TVector<T>& operator+=(const TVector<T>& other) {
        if (_size != other._size) {
            throw std::logic_error("Vectors have different sizes");
        }
        for (size_t i = 0; i < _size; ++i) {
            _data[i] += other._data[i];
        }
        return *this;
    }

    TVector<T>& operator-=(const TVector<T>& other) {
        if (_size != other._size) {
            throw std::logic_error("Vectors have different sizes");
        }
        for (size_t i = 0; i < _size; ++i) {
            _data[i] -= other._data[i];
        }
        return *this;
    }

    TVector<T>& operator*=(T scalar) {
        for (size_t i = 0; i < _size; ++i) {
            _data[i] *= scalar;
        }
        return *this;
    }

    // ��������� ���������
    bool operator==(const TVector<T>& other) const {
        if (_size != other._size) {
            return false;
        }
        for (size_t i = 0; i < _size; ++i) {
            if (_data[i] != other._data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const TVector<T>& other) const {
        return !(*this == other);
    }

    // ��������� ������� �������
    size_t size() const {
        return _size;
    }

    // ��������� �������� ���������� ������������
    T dotProduct(const TVector<T>& other) const {
        if (_size != other._size) {
            throw std::logic_error("Vectors have different sizes");
        }
        T result = 0;
        for (size_t i = 0; i < _size; ++i) {
            result += _data[i] * other._data[i];
        }
        return result;
    }

private:
    T* _data; // ��������� �� ������
    size_t _size; // ������ �������
    size_t _capacity; // ����������� �������
};

#endif // VECTOR_H
