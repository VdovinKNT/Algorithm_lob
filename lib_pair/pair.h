// Copyright 2024 Marina Usova

#ifndef LIB_PAIR_PAIR_H_
#define LIB_PAIR_PAIR_H_

#include <iostream>
#include <string>
#include <utility> 

template <class T1, class T2> class TPair;

template <class T1, class T2>
std::ostream& operator<<(std::ostream& out, const TPair<T1, T2>& obj) noexcept;

template <class T1, class T2>
class TPair {
public:
    T1 first;
    T2 second;

    // Конструкторы
    TPair() : first(), second() {}
    TPair(const T1& first, const T2& second) : first(first), second(second) {}
    TPair(const TPair<T1, T2>& other) : first(other.first), second(other.second) {}

    // Оператор присваивания
    TPair& operator=(const TPair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    // Функция обмена значениями (swap)
    void swap(TPair& other) noexcept {
        std::swap(first, other.first);
        std::swap(second, other.second);
    }

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

    // Преобразование в строку
    std::string to_string() const {
        return "(" + std::to_string(first) + ", " + std::to_string(second) + ")";
    }
};

// Шаблон перегрузки оператора вывода для TPair
template <class T1, class T2>
std::ostream& operator<<(std::ostream& out, const TPair<T1, T2>& pair) noexcept {
    out << pair.to_string();
    return out;
}

// Функция создания пары
template <class T1, class T2>
TPair<T1, T2> make_pair(const T1& first, const T2& second) {
    return TPair<T1, T2>(first, second);
}

#endif  // LIB_PAIR_PAIR_H_