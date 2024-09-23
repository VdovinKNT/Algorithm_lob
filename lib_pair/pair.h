// Copyright 2024 Marina Usova

#ifndef LIB_PAIR_PAIR_H_
#define LIB_PAIR_PAIR_H_

#include <iostream>
#include <string>
#include <stdexcept>

template <class T1, class T2> class TPair;
template <class T1, class T2>
std::ostream& operator<<(std::ostream& out, const TPair<T1, T2>& obj) noexcept;

template <class T1, class T2>
class TPair {
public:
    T1 first; // Убираем символ подчеркивания для соответствия стандарту
    T2 second; // Убираем символ подчеркивания для соответствия стандарту

    // Конструкторы
    TPair() : first(), second() {}
    TPair(const T1& first, const T2& second) : first(first), second(second) {}
    TPair(const TPair<T1, T2>& other) : first(other.first), second(other.second) {}

    // Операторы сравнения
    bool operator==(const TPair& other) const {
        return (first == other.first) && (second == other.second);
    }

    bool operator!=(const TPair& other) const {
        return !(*this == other);
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const TPair& pair) {
        out << "(" << pair.first << ", " << pair.second << ")";
        return out;
    }

    // Операторы арифметических действий
    TPair<T1, T2>& operator+=(const TPair<T1, T2>& other) {
        first += other.first;
        second += other.second;
        return *this;
    }

    TPair<T1, T2>& operator-=(const TPair<T1, T2>& other) {
        first -= other.first;
        second -= other.second;
        return *this;
    }

    TPair<T1, T2> operator+(const TPair<T1, T2>& other) const {
        TPair<T1, T2> temp(*this);
        temp += other;
        return temp;
    }

    TPair<T1, T2> operator-(const TPair<T1, T2>& other) const {
        TPair<T1, T2> temp(*this);
        temp -= other;
        return temp;
    }

    // Дружественные функции
    friend TPair<T1, T2>& operator-(const TPair<T1, T2>& pair1, const TPair<T1, T2>& pair2) {
        TPair<T1, T2> temp(pair1);
        temp -= pair2;
        return temp;
    }

    // Метод для преобразования в строку
    std::string to_string() const {
        std::string str = "(" + std::to_string(first) + ", " + std::to_string(second) + ")";
        return str;
    }
};

// Перегрузка оператора вывода
template <class T1, class T2>
std::ostream& operator<<(std::ostream& out, const TPair<T1, T2>& pair) noexcept {
    out << pair.to_string();
    return out;
}

#endif  // LIB_PAIR_PAIR_H_
