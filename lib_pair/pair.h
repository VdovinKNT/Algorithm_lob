// Copyright 2024 <Artem Vdovin>

#ifndef LIB_PAIR_PAIR_H_
#define LIB_PAIR_PAIR_H_

#include <iostream>
#include <string>

template <typename T1, typename T2>
class Pair {
 public:
    Pair() : first_(), second_() {}
    Pair(const T1& first, const T2& second) : first_(first),
        second_(second) {}
    Pair(const Pair& other) : first_(other.first_), second_(other.second_) {}
    Pair(Pair&& other) noexcept : first_(std::move(other.first_)),
        second_(std::move(other.second_)) {}

    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first_ = other.first_;
            second_ = other.second_;
        }
        return *this;
    }

    Pair& operator=(Pair&& other) noexcept {
        if (this != &other) {
            first_ = std::move(other.first_);
            second_ = std::move(other.second_);
        }
        return *this;
    }

    const T1& first() const { return first_; }
    const T2& second() const { return second_; }
    void setFirst(const T1& value) { first_ = value; }
    void setSecond(const T2& value) { second_ = value; }

    bool operator==(const Pair& other) const {
        return first_ == other.first_ && second_ == other.second_;
    }

    bool operator!=(const Pair& other) const {
        return !(*this == other);
    }

    bool operator<(const Pair& other) const {
        return first_ < other.first_ ||
            (first_ == other.first_ && second_ < other.second_);
    }

    bool operator>(const Pair& other) const {
        return other < *this;
    }

    bool operator<=(const Pair& other) const {
        return !(other < *this);
    }

    bool operator>=(const Pair& other) const {
        return !(*this < other);
    }

    Pair operator+(const Pair& other) const {
        return Pair(first_ + other.first_, second_ + other.second_);
    }

    Pair operator-(const Pair& other) const {
        return Pair(first_ - other.first_, second_ - other.second_);
    }

    Pair& operator+=(const Pair& other) {
        first_ += other.first_;
        second_ += other.second_;
        return *this;
    }

    Pair& operator-=(const Pair& other) {
        first_ -= other.first_;
        second_ -= other.second_;
        return *this;
    }

    std::string toString() const {
        return "(" + std::to_string(first_) +
            ", " + std::to_string(second_) + ")";
    }

    void swap(Pair& other) noexcept {
        std::swap(first_, other.first_);
        std::swap(second_, other.second_);
    }

 private:
    T1 first_;
    T2 second_;
};

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& os, const Pair<T1, T2>& pair) {
    return os << pair.toString();
}

#endif // LIB_PAIR_PAIR_H_



