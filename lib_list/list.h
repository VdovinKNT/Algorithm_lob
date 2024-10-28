// Copyright 2024 Artem Vdovin

#ifndef LIB_LIST_LIST_H_
#define LIB_LIST_LIST_H_

#include <iostream>
#include <stdexcept> 

template <class T>
class TNode {
public:
    T data;           
    TNode* next;     

    TNode() : data(), next(nullptr) {}
    TNode(const T& data) : data(data), next(nullptr) {}
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

template <class T>
class TList {
public:
    TNode<T>* head;  
    TNode<T>* tail;  

    TList() : head(nullptr), tail(nullptr) {}

    // Конструктор копирования
    TList(const TList<T>& other) : head(nullptr), tail(nullptr) {
        if (other.head == nullptr) {
            return; 
        }
        TNode<T>* current = other.head;
        while (current != nullptr) {
            insert_tail(current->data);
            current = current->next;
        }
    }

    ~TList() {
        clear(); 
    }

    // Оператор присваивания
    TList<T>& operator=(const TList<T>& other) {
        if (this != &other) {
            clear(); 
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
    void insert_tail(const T& data) {
        TNode<T>* new_node = new TNode<T>(data);
        if (is_empty()) {
            head = tail = new_node; 
        }
        else {
            tail->next = new_node; 
            tail = new_node;       
        }
    }

    // Вставка элемента в начало списка
    void insert_head(const T& data) {
        TNode<T>* new_node = new TNode<T>(data);
        if (is_empty()) {
            head = tail = new_node; 
        }
        else {
            new_node->next = head; 
            head = new_node;       
        }
    }

    // Вставка элемента после указанного узла
    void insert_after(TNode<T>* node, const T& data) {
        if (node == nullptr) {
            throw std::runtime_error("Узел равен nullptr.");
        }
        TNode<T>* new_node = new TNode<T>(data);
        new_node->next = node->next; 
        node->next = new_node;       
        if (node == tail) {
            tail = new_node; 
        }
    }

    // Вставка элемента на указанную позицию
    void insert_at(size_t position, const T& data) {
        if (position > size()) {
            throw std::out_of_range("Позиция вне диапазона.");
        }
        if (position == 0) {
            insert_head(data);
            return;
        }
        TNode<T>* current = head;
        size_t count = 0;
        while (count < position - 1) {
            current = current->next;
            ++count;
        }
        insert_after(current, data); 
    }

    // Поиск элемента по значению
    TNode<T>* find(const T& data) const {
        TNode<T>* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return current; 
            }
            current = current->next; 
        }
        return nullptr; 
    }

    // Удаление элемента из конца списка
    void remove_tail() {
        if (is_empty()) {
            throw std::out_of_range("Список пуст.");
        }
        if (head == tail) {
            delete head; 
            head = tail = nullptr;
            return;
        }
        TNode<T>* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail; 
        tail = current; 
        tail->next = nullptr; 
    }

    // Удаление элемента из начала списка
    void remove_head() {
        if (is_empty()) {
            throw std::out_of_range("Список пуст.");
        }
        TNode<T>* temp = head;
        head = head->next; 
        delete temp; 
        if (head == nullptr) {
            tail = nullptr; 
        }
    }

    // Удаление указанного узла
    void remove(TNode<T>* node) {
        if (node == nullptr) {
            throw std::runtime_error("Узел равен nullptr.");
        }
        if (node == head) {
            remove_head(); 
            return;
        }
        if (node == tail) {
            remove_tail();
            return;
        }
        TNode<T>* current = head;
        while (current->next != node) {
            current = current->next;
        }
        current->next = node->next; 
        delete node; 
    }

    // Удаление узла по указанной позиции
    void remove_at(size_t position) {
        if (position >= size()) {
            throw std::out_of_range("Позиция вне диапазона.");
        }
        if (position == 0) {
            remove_head(); 
            return;
        }
        TNode<T>* current = head;
        size_t count = 0;
        while (count < position - 1) { 
            current = current->next;
            ++count;
        }
        remove(current->next); 
    }

    // Замена значения указанного узла
    void replace(TNode<T>* node, const T& new_data) {
        if (node == nullptr) {
            throw std::runtime_error("Узел равен nullptr.");
        }
        node->data = new_data; 
    }

    // Замена значения узла по указанной позиции
    void replace_at(size_t position, const T& new_data) {
        if (position >= size()) {
            throw std::out_of_range("Позиция вне диапазона.");
        }
        TNode<T>* current = head;
        size_t count = 0;
        while (count < position) { 
            current = current->next;
            ++count;
        }
        replace(current, new_data);
    }

    // Очистка списка
    void clear() {
        while (!is_empty()) {
            remove_head(); 
        }
    }

    // Получение размера списка
    size_t size() const {
        size_t count = 0;
        TNode<T>* current = head;
        while (current != nullptr) {
            ++count; 
            current = current->next; 
        }
        return count; 
    }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const TList<T>& list) {
        if (list.is_empty()) {
            out << "Список пуст.";
            return out;
        }
        TNode<T>* current = list.head;
        while (current != nullptr) {
            out << current->data << " "; 
            current = current->next; 
        }
        return out; 
    }
};

#endif  // LIB_LIST_LIST_H_
