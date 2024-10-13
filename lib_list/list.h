// Copyright 2024 Artem Vdovin

#ifndef LIB_LIST_LIST_H_
#define LIB_LIST_LIST_H_

#include <iostream>
#include <stdexcept>

// Шаблон класса TNode
template <class T>
class TNode {
public:
    // Данные узла
    T data;

    // Указатель на следующий узел
    TNode* next;

    // Конструктор по умолчанию
    TNode() : data(), next(nullptr) {}

    // Параметризированный конструктор
    TNode(const T& data) : data(data), next(nullptr) {}

    // Конструктор копирования
    TNode(const TNode<T>& other) : data(other.data), next(other.next) {}

    // Оператор присваивания
    TNode<T>& operator=(const TNode<T>& other) {
        if (this != &other) {
            data = other.data;
            next = other.next;
        }
        return *this;
    }

    // Оператор сравнения на равенство
    bool operator==(const TNode<T>& other) const {
        return data == other.data;
    }

    // Оператор сравнения на неравенство
    bool operator!=(const TNode<T>& other) const {
        return !(*this == other);
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const TNode<T>& node) {
        out << node.data;
        return out;
    }
};

// Шаблон класса TList
template <class T>
class TList {
public:
    // Указатель на головной узел
    TNode<T>* head;

    // Указатель на хвостовой узел
    TNode<T>* tail;

    // Конструктор по умолчанию
    TList() : head(nullptr), tail(nullptr) {}

    // Конструктор копирования
    TList(const TList<T>& other) : head(nullptr), tail(nullptr) {
        // Если другой список пуст, то наш тоже будет пуст
        if (other.head == nullptr) {
            return;
        }
        // Копируем элементы из другого списка
        TNode<T>* current = other.head;
        while (current != nullptr) {
            insert_tail(current->data);
            current = current->next;
        }
    }

    // Деструктор
    ~TList() {
        clear();
    }

    // Оператор присваивания
    TList<T>& operator=(const TList<T>& other) {
        if (this != &other) {
            clear();
            // Копируем элементы из другого списка
            TNode<T>* current = other.head;
            while (current != nullptr) {
                insert_tail(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // Проверка пустоты списка
    bool is_empty() const {
        return head == nullptr;
    }

    // Вставка элемента в конец списка

