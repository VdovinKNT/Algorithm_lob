#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

template <typename T>
class TVector {
public:
    // Конструкторы
    TVector() : _data(nullptr), _size(0), _capacity(0) {}

    TVector(size_t size) : _data(new T[size]), _size(size), _capacity(size) {}

    TVector(const TVector<T>& other) : _data(new T[other._size]),
        _size(other._size),
        _capacity(other._size) {
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }

    // Деструктор
    ~TVector() {
        delete[] _data;
    }

    // Операторы доступа
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

    // Операторы сложения и вычитания
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

    // Оператор умножения на число
    TVector<T> operator*(T scalar) const {
        TVector<T> result(_size);
        for (size_t i = 0; i < _size; ++i) {
            result._data[i] = _data[i] * scalar;
        }
        return result;
    }

    // Операторы присваивания
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

    // Операторы сравнения
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

    // Получение размера вектора
    size_t size() const {
        return _size;
    }

    // Получение значения скалярного произведения
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
    T* _data; // Указатель на массив
    size_t _size; // Размер вектора
    size_t _capacity; // Вместимость массива
};

#endif // VECTOR_H
