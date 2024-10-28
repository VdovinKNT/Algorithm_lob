#ifndef TVECTOR_H
#define TVECTOR_H

#include "../lib_dmassive/dmassive.h"
#include <cstddef>
#include <stdexcept>
#include <iostream>

template<typename T>
class TVector {
private:
    DMassive<T> _data;       // Вектор данных, теперь с шаблонным параметром
    size_t _start_index;     // Индекс, с которого начинается вектор

public:
    // Конструктор
    TVector(size_t size, size_t start_index = 0)
        : _data(size), _start_index(start_index) {}

    TVector(const TVector& other)
        : _data(other._data), _start_index(other._start_index) {}

    TVector(TVector&& other) noexcept
        : _data(std::move(other._data)), _start_index(other._start_index) {
        other._start_index = 0; // обнуление переменной
    }

    // Деструктор
    ~TVector() {}

    // Операторы доступа
    T& operator[](size_t index) {
        if (index < _start_index || index >= _start_index + _data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index - _start_index]; // корректировка индекса
    }

    const T& operator[](size_t index) const {
        if (index < _start_index || index >= _start_index + _data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return _data[index - _start_index];
    }

    // Операторы сложения
    TVector operator+(const TVector& other) const {
        if (this->size() != other.size()) {
            throw std::invalid_argument("Vectors must be the same size for addition");
        }

        TVector result(this->size());
        for (size_t i = 0; i < this->size(); ++i) {
            result[i + _start_index] = (*this)[i + _start_index] + other[i + _start_index];
        }
        return result;
    }

    // Оператор вычитания
    TVector operator-(const TVector& other) const {
        if (this->size() != other.size()) {
            throw std::invalid_argument("Vectors must be the same size for subtraction");
        }

        TVector result(this->size());
        for (size_t i = 0; i < this->size(); ++i) {
            result[i + _start_index] = (*this)[i + _start_index] - other[i + _start_index];
        }
        return result;
    }

    // Оператор умножения на скаляр
    TVector operator*(T scalar) const {
        TVector result(this->size());
        for (size_t i = 0; i < this->size(); ++i) {
            result[i + _start_index] = (*this)[i + _start_index] * scalar;
        }
        return result;
    }

    // Операторы присваивания
    TVector& operator+=(const TVector& other) {
        if (this->size() != other.size()) {
            throw std::invalid_argument("Vectors must be the same size for addition");
        }

        for (size_t i = 0; i < this->size(); ++i) {
            (*this)[i + _start_index] += other[i + _start_index];
        }
        return *this;
    }

    TVector& operator-=(const TVector& other) {
        if (this->size() != other.size()) {
            throw std::invalid_argument("Vectors must be the same size for subtraction");
        }

        for (size_t i = 0; i < this->size(); ++i) {
            (*this)[i + _start_index] -= other[i + _start_index];
        }
        return *this;
    }

    TVector& operator*=(T scalar) {
        for (size_t i = 0; i < this->size(); ++i) {
            (*this)[i + _start_index] *= scalar;
        }
        return *this;
    }

    // Операторы сравнения
    bool operator==(const TVector& other) const {
        if (this->size() != other.size()) {
            return false;
        }
        for (size_t i = 0; i < this->size(); ++i) {
            if ((*this)[i + _start_index] != other[i + _start_index]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const TVector& other) const {
        return !(*this == other);
    }

    bool operator<(const TVector& other) const {
        size_t minSize = std::min(this->size(), other.size());
        for (size_t i = 0; i < minSize; ++i) {
            if ((*this)[i + _start_index] < other[i + _start_index]) {
                return true;
            }
            else if ((*this)[i + _start_index] > other[i + _start_index]) {
                return false;
            }
        }
        return this->size() < other.size(); // Меньший по размеру
    }

    bool operator<=(const TVector& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>(const TVector& other) const {
        return !(*this <= other);
    }

    bool operator>=(const TVector& other) const {
        return !(*this < other);
    }

    // Другие методы
    size_t size() const {
        return _data.size(); // Здесь предполагается, что метод size() корректен в DMassive
    }

    size_t start_index() const {
        return _start_index;
    }

    void print() const {
        for (size_t i = 0; i < size(); ++i) {
            std::cout << (*this)[i + _start_index] << " ";
        }
        std::cout << std::endl;
    }
};

#endif // TVECTOR_H
