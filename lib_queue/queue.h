// Copyright 2024 Artem Vdovin

#ifndef LIB_QUEUE_QUEUE_H_
#define LIB_QUEUE_QUEUE_H_

#include <iostream>
#include <stdexcept>
#include <string>

// Шаблон класса TQueue
template <class T>
class TQueue {
public:
    // Конструктор по умолчанию
    TQueue() : head_(nullptr), tail_(nullptr) {}

    // Конструктор копирования
    TQueue(const TQueue<T>& other) {
        // Если другая очередь пуста, то наша тоже будет пуста
        if (other.head_ == nullptr) {
            head_ = tail_ = nullptr;
            return;
        }
        // Копируем элементы из другой очереди
        Node* current = other.head_;
        while (current != nullptr) {
            push(current->data);
            current = current->next;
        }
    }

    // Деструктор
    ~TQueue() {
        clear();
    }

    // Оператор присваивания
    TQueue<T>& operator=(const TQueue<T>& other) {
        if (this != &other) {
            clear();
            // Копируем элементы из другой очереди
            Node* current = other.head_;
            while (current != nullptr) {
                push(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // Добавление элемента в конец очереди
    void push(const T& data) {
        Node* new_node = new Node(data);
        if (head_ == nullptr) {
            head_ = tail_ = new_node;
        }
        else {
            tail_->next = new_node;
            tail_ = new_node;
        }
    }

    // Извлечение элемента из начала очереди
    T pop() {
        if (head_ == nullptr) {
            throw std::out_of_range("Queue is empty.");
        }
        T data = head_->data;
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
        if (head_ == nullptr) {
            tail_ = nullptr;
        }
        return data;
    }

    // Получение элемента из начала очереди
    T front() const {
        if (head_ == nullptr) {
            throw std::out_of_range("Queue is empty.");
        }
        return head_->data;
    }

    // Проверка пустоты очереди
    bool empty() const {
        return head_ == nullptr;
    }

    // Получение размера очереди
    size_t size() const {
        size_t count = 0;
        Node* current = head_;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
        return count;
    }

    // Очистка очереди
    void clear() {
        while (!empty()) {
            pop();
        }
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const TQueue<T>& queue) {
        if (queue.empty()) {
            out << "Queue is empty.";
            return out;
        }
        Node* current = queue.head_;
        while (current != nullptr) {
            out << current->data << " ";
            current = current->next;
        }
        return out;
    }

private:
    // Структура узла очереди
    struct Node {
        T data;
        Node* next;

        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;
};

#endif  // LIB_QUEUE_QUEUE_H_

