// Copyright 2024 Artem Vdovin

#ifndef LIB_QUEUE_QUEUE_H_
#define LIB_QUEUE_QUEUE_H_

#include <iostream>
#include <stdexcept>
#include <string>

template <class T>
class TQueue {
public:
    TQueue() : head_(nullptr), tail_(nullptr), size_(0) {}  

    TQueue(const TQueue<T>& other) : head_(nullptr), tail_(nullptr), size_(0) {
        Node* current = other.head_;
        while (current != nullptr) {
            push(current->data); 
            current = current->next;
        }
    }

    ~TQueue() {
        clear();  
    }

    // Оператор присваивания
    TQueue<T>& operator=(const TQueue<T>& other) {
        if (this != &other) {  
            clear();  
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
        ++size_;  
    }

    // Извлечение элемента из начала очереди
    T pop() {
        if (head_ == nullptr) {  
            throw std::out_of_range("Очередь пуста.");  
        }
        T data = head_->data;  
        Node* temp = head_;  
        head_ = head_->next;  
        delete temp;  
        if (head_ == nullptr) {
            tail_ = nullptr;  
        }
        --size_;  
        return data;  
    }

    // Получение элемента из начала очереди
    T front() const {
        if (head_ == nullptr) {  
            throw std::out_of_range("Очередь пуста.");  
        }
        return head_->data;  
    }

    // Проверка пустоты очереди
    bool empty() const {
        return head_ == nullptr;  
    }

    // Получение размера очереди
    size_t size() const {
        return size_;  
    }

    // Очистка очереди
    void clear() {
        while (!empty()) {
            pop();  
        }
        size_ = 0; 
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const TQueue<T>& queue) {
        if (queue.empty()) {  
            out << "Очередь пуста.";  
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
    struct Node {
        T data;  
        Node* next;  

        Node(const T& data) : data(data), next(nullptr) {}  
    };

    Node* head_;  
    Node* tail_;  
    size_t size_;  
};

#endif  // LIB_QUEUE_QUEUE_H_
