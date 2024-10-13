// Copyright 2024 Artem Vdovin

#ifndef LIB_LIST_LIST_H_
#define LIB_LIST_LIST_H_

#include <iostream>
#include <stdexcept>

// ������ ������ TNode
template <class T>
class TNode {
public:
    // ������ ����
    T data;

    // ��������� �� ��������� ����
    TNode* next;

    // ����������� �� ���������
    TNode() : data(), next(nullptr) {}

    // ������������������� �����������
    TNode(const T& data) : data(data), next(nullptr) {}

    // ����������� �����������
    TNode(const TNode<T>& other) : data(other.data), next(other.next) {}

    // �������� ������������
    TNode<T>& operator=(const TNode<T>& other) {
        if (this != &other) {
            data = other.data;
            next = other.next;
        }
        return *this;
    }

    // �������� ��������� �� ���������
    bool operator==(const TNode<T>& other) const {
        return data == other.data;
    }

    // �������� ��������� �� �����������
    bool operator!=(const TNode<T>& other) const {
        return !(*this == other);
    }

    // ���������� ��������� ������
    friend std::ostream& operator<<(std::ostream& out, const TNode<T>& node) {
        out << node.data;
        return out;
    }
};

// ������ ������ TList
template <class T>
class TList {
public:
    // ��������� �� �������� ����
    TNode<T>* head;

    // ��������� �� ��������� ����
    TNode<T>* tail;

    // ����������� �� ���������
    TList() : head(nullptr), tail(nullptr) {}

    // ����������� �����������
    TList(const TList<T>& other) : head(nullptr), tail(nullptr) {
        // ���� ������ ������ ����, �� ��� ���� ����� ����
        if (other.head == nullptr) {
            return;
        }
        // �������� �������� �� ������� ������
        TNode<T>* current = other.head;
        while (current != nullptr) {
            insert_tail(current->data);
            current = current->next;
        }
    }

    // ����������
    ~TList() {
        clear();
    }

    // �������� ������������
    TList<T>& operator=(const TList<T>& other) {
        if (this != &other) {
            clear();
            // �������� �������� �� ������� ������
            TNode<T>* current = other.head;
            while (current != nullptr) {
                insert_tail(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // �������� ������� ������
    bool is_empty() const {
        return head == nullptr;
    }

    // ������� �������� � ����� ������

