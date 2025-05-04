 
// Copyright 2024 Artem Vdovin

#ifndef LIB_STACKONLIST_STACKONLIST_H_
#define LIB_STACKONLIST_STACKONLIST_H_

#include <stdexcept>
#include "../lib_List/List.h"

template <typename T>
class TStackOnList {
private:
    TList<T> _list;
    size_t _capacity;

public:
    explicit TStackOnList(size_t capacity) {
        if (capacity == 0) {
            throw std::invalid_argument("Capacity must be greater than zero");
        }
        _capacity = capacity;
    }

    // метод для добавления элемента в стек
    void push(const T& value) {
        if (size() >= _capacity) {
            throw std::overflow_error("Stack overflow");
        }
        _list.insertFront(value);
    }

    // метод для удаления элемента из стека
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack underflow");
        }
        T topValue = _list.getHead()->getValue();
        _list.removeFront();
        return topValue;
    }

    // метод для получения верхнего элемента без удаления
    T top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return _list.getHead()->getValue();
    }

    // метод для проверки, пуст ли стек
    bool isEmpty() const {
        return _list.isEmpty();
    }

    // метод для получения текущего размера стека
    size_t size() const {
        size_t count = 0;
        TNode<T>* current = _list.getHead();
        while (current) {
            count++;
            current = current->getNext();
        }
        return count;
    }

    // метод для получения максимальной вместимости стека
    size_t capacity() const {
        return _capacity;
    }

    // метод для проверки, заполнен ли стек
    bool isFull() const {
        return size() >= _capacity;
    }
};

#endif  // LIB_STACKONLIST_STACKONLIST_H_