// Copyright 2024 <Artem Vdovin>

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template <typename T>
class TStack {
public:
    TStack() : _data(nullptr), _size(0), _top(0) {}

    ~TStack() {
        delete[] _data;
    }

    // Копирующий конструктор
    TStack(const TStack& other) {
        _size = other._size;
        _top = other._top;
        _data = new T[_size];
        for (size_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }

    // Оператор присваивания
    TStack& operator=(const TStack& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            _top = other._top;
            _data = new T[_size];
            for (size_t i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    // Добавление элемента в стек
    void push(const T& value) {
        if (_top == _size) {
            resize();
        }
        _data[_top++] = value;
    }

    // Извлечение элемента из стека
    void pop() {
        if (_top == 0) {
            throw std::logic_error("Stack is empty");
        }
        --_top;
    }

    // Получение значения верхушки стека
    T top() const {
        if (_top == 0) {
            throw std::logic_error("Stack is empty");
        }
        return _data[_top - 1];
    }

    // Проверка пустоты стека
    bool empty() const {
        return _top == 0;
    }

    // Размер стека
    size_t size() const {
        return _size;
    }

private:
    T* _data; 
    size_t _size;
    size_t _top; 

    // Увеличение размера массива в 2 раза
    void resize() {
        size_t newSize = _size == 0 ? 1 : _size * 2;
        T* newData = new T[newSize];
        for (size_t i = 0; i < _size; ++i) {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
        _size = newSize;
    }

    friend std::ostream& operator<<(std::ostream& os,const TStack<T>& stack){
        os << "Стек: ";
        for (size_t i = 0; i < stack._top; ++i) {
            os << stack._data[i] << " ";
        }
        return os;
    }
};

#endif // STACK_H
