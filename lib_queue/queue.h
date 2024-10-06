// Copyright 2024 Artem Vdovin

#ifndef LIB_QUEUE_QUEUE_H_
#define LIB_QUEUE_QUEUE_H_

#include <iostream>
#include <stdexcept>
#include <string>

// ������ ������ TQueue
template <class T>
class TQueue {
public:
    // ����������� �� ���������
    TQueue() : head_(nullptr), tail_(nullptr) {}

    // ����������� �����������
    TQueue(const TQueue<T>& other) {
        // ���� ������ ������� �����, �� ���� ���� ����� �����
        if (other.head_ == nullptr) {
            head_ = tail_ = nullptr;
            return;
        }
        // �������� �������� �� ������ �������
        Node* current = other.head_;
        while (current != nullptr) {
            push(current->data);
            current = current->next;
        }
    }

    // ����������
    ~TQueue() {
        clear();
    }

    // �������� ������������
    TQueue<T>& operator=(const TQueue<T>& other) {
        if (this != &other) {
            clear();
            // �������� �������� �� ������ �������
            Node* current = other.head_;
            while (current != nullptr) {
                push(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // ���������� �������� � ����� �������
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

    // ���������� �������� �� ������ �������
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

    // ��������� �������� �� ������ �������
    T front() const {
        if (head_ == nullptr) {
            throw std::out_of_range("Queue is empty.");
        }
        return head_->data;
    }

    // �������� ������� �������
    bool empty() const {
        return head_ == nullptr;
    }

    // ��������� ������� �������
    size_t size() const {
        size_t count = 0;
        Node* current = head_;
        while (current != nullptr) {
            ++count;
            current = current->next;
        }
        return count;
    }

    // ������� �������
    void clear() {
        while (!empty()) {
            pop();
        }
    }

    // ���������� ��������� ������
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
    // ��������� ���� �������
    struct Node {
        T data;
        Node* next;

        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;
};

#endif  // LIB_QUEUE_QUEUE_H_

