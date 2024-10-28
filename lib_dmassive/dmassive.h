// Copyright 2024 Ivan Karpich

#ifndef LIB_DMASSIVE_DMASSIVE_H_
#define LIB_DMASSIVE_DMASSIVE_H_

#include <iostream>
#include <stdexcept>
#include <utility>
#include <algorithm>

#define STEP_CAPACITY 15

// Определяем состояние элемента: пустой, занят, удален
enum State { empty, busy, deleted };

namespace algorithms {

    // Функция для обмена значениями
    template<typename T>
    inline void swap(T& val_1, T& val_2) noexcept {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }

    // Функция для нахождения максимума
    template<typename T>
    inline T max(const T& val_1, const T& val_2) {
        return (val_1 > val_2) ? val_1 : val_2;
    }

}  // namespace algorithms

template <typename T>
class DMassive {
    T* _data;             // Указатель на массив данных
    State* _states;       // Указатель на массив состояний
    size_t _capacity;     // Вместимость массива
    size_t _size;         // Текущий размер массива
    size_t _deleted;      // Количество удаленных элементов

public:
    // Конструкторы
    DMassive();
    DMassive(const DMassive& archive);
    DMassive(const T* arr, size_t n);
    DMassive(size_t n, T value);
    DMassive(const DMassive& archive, size_t pos, size_t len);

    // Перегрузка оператора присваивания
    DMassive& operator=(const DMassive& other);

    // Перегрузка оператора доступа по индексу
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    bool is_busy(size_t index) const noexcept;

    void compact();

    ~DMassive();

    // Функция для вывода массива
    void print() const noexcept;

    // Проверка на пустоту и полноту
    inline bool empty() const noexcept;
    inline bool full() const noexcept;

    // Методы для получения размера и вместимости
    size_t size() const noexcept;
    size_t capacity() const noexcept;
    const T* data() const noexcept;

    // Функция для обмена содержимым массивов
    void swap(DMassive& archive);

    // Очищаем массив
    void clear();

    // Управление памятью
    void reserve(size_t n);
    void resize(size_t n, T value);
    void repack();

    // Присваивание значений
    DMassive& assign(const DMassive& archive);

    // Методы для добавления элементов
    void push_back(T value);
    void pop_back();
    void push_front(T value);
    void pop_front();

    // Вставка элементов
    DMassive& insert(const T* arr, size_t n, size_t pos);
    DMassive& insert(T value, size_t pos);

    // Замена элементов
    DMassive& replace(size_t pos, T new_value);

    // Удаление элементов
    DMassive& remove_by_index(size_t pos);
    DMassive& erase(size_t pos, size_t n);
    DMassive& remove_all(T value);
    DMassive& remove_first(T value);
    DMassive& remove_last(T value);

    // Поиск элементов
    size_t find_first(T value) const noexcept;
    size_t find_last(T value) const noexcept;

private:
    // Вспомогательная функция для проверки индекса
    void check_index(size_t pos) const;
};

// Реализация методов

template <typename T>
DMassive<T>::DMassive() : _size(0), _capacity(STEP_CAPACITY), _deleted(0) {
    _data = new T[_capacity];
    _states = new State[_capacity];
    std::fill_n(_states, _capacity, State::empty);
}

template <typename T>
DMassive<T>::DMassive(const DMassive& archive) : _size(archive._size), _capacity(archive._capacity), _deleted(archive._deleted) {
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = archive._data[i];
        _states[i] = archive._states[i];
    }
    std::fill_n(_states + _size, _capacity - _size, State::empty);
}

template <typename T>
DMassive<T>::DMassive(const T* arr, size_t n) : _size(n), _capacity(n + STEP_CAPACITY), _deleted(0) {
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < n; i++) {
        _data[i] = arr[i];
        _states[i] = State::busy;
    }
    std::fill_n(_states + n, _capacity - n, State::empty);
}

template <typename T>
DMassive<T>::DMassive(size_t n, T value) : _size(n), _capacity(n + STEP_CAPACITY), _deleted(0) {
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < n; i++) {
        _data[i] = value;
        _states[i] = State::busy;
    }
    std::fill_n(_states + n, _capacity - n, State::empty);
}

template <typename T>
DMassive<T>::DMassive(const DMassive& archive, size_t pos, size_t len) {
    if (pos + len > archive._size) {
        throw std::out_of_range("Range exceeds the size of the array.");
    }
    _size = len;
    _capacity = len + STEP_CAPACITY;
    _deleted = 0;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < len; i++) {
        _data[i] = archive._data[pos + i];
        _states[i] = State::busy;
    }
    std::fill_n(_states + len, _capacity - len, State::empty);
}

template <typename T>
DMassive<T>::~DMassive() {
    delete[] _data;
    delete[] _states;
}

// Функция для вывода содержимого массива
template <typename T>
void DMassive<T>::print() const noexcept {
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::busy) {
            std::cout << _data[i] << " ";
        }
    }
    std::cout << std::endl;
}

template <typename T>
inline bool DMassive<T>::empty() const noexcept {
    return _size == 0;
}

template <typename T>
inline bool DMassive<T>::full() const noexcept {
    return _size == _capacity;
}

template <typename T>
size_t DMassive<T>::size() const noexcept {
    return _size;
}

template <typename T>
size_t DMassive<T>::capacity() const noexcept {
    return _capacity;
}

template <typename T>
const T* DMassive<T>::data() const noexcept {
    return _data;
}

template <typename T>
void DMassive<T>::swap(DMassive& archive) {
    std::swap(_data, archive._data);
    std::swap(_states, archive._states);
    std::swap(_capacity, archive._capacity);
    std::swap(_size, archive._size);
    std::swap(_deleted, archive._deleted);
}

template <typename T>
void DMassive<T>::clear() {
    _size = 0;
    _deleted = 0;
    std::fill_n(_states, _capacity, State::empty);
}

template <typename T>
void DMassive<T>::reserve(size_t n) {
    if (_capacity >= _size + n) return;
    size_t new_capacity = _capacity + algorithms::max<size_t>(n, STEP_CAPACITY);
    T* new_data = new T[new_capacity];
    State* new_states = new State[new_capacity];

    for (size_t i = 0; i < _size; i++) {
        new_data[i] = _data[i];
        new_states[i] = _states[i];
    }
    std::fill_n(new_states + _size, new_capacity - _size, State::empty);

    delete[] _data;
    delete[] _states;

    _data = new_data;
    _states = new_states;
    _capacity = new_capacity;
}

template <typename T>
void DMassive<T>::resize(size_t n, T value) {
    reserve(n);
    for (size_t i = _size; i < n; i++) {
        _data[i] = value;
        _states[i] = State::busy;
    }
    _size = n;
}

template <typename T>
void DMassive<T>::repack() {
    if (_deleted == 0) return;

    size_t new_size = 0;
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::busy) {
            _data[new_size++] = _data[i];
            _states[new_size - 1] = State::busy;
        }
    }
    _size = new_size;
    _deleted = 0;
    std::fill_n(_states + new_size, _capacity - new_size, State::empty);
}

template <typename T>
DMassive<T>& DMassive<T>::assign(const DMassive& archive) {
    if (this != &archive) {
        delete[] _data;
        delete[] _states;

        _size = archive._size;
        _capacity = archive._capacity;
        _deleted = archive._deleted;

        _data = new T[_capacity];
        _states = new State[_capacity];

        for (size_t i = 0; i < _size; i++) {
            _data[i] = archive._data[i];
            _states[i] = archive._states[i];
        }
        std::fill_n(_states + _size, _capacity - _size, State::empty);
    }
    return *this;
}

template <typename T>
DMassive<T>& DMassive<T>::operator=(const DMassive& other) {
    return assign(other);
}

template <typename T>
T& DMassive<T>::operator[](size_t index) {
    check_index(index);
    return _data[index];
}

template <typename T>
const T& DMassive<T>::operator[](size_t index) const {
    check_index(index);
    return _data[index];
}

template <typename T>
void DMassive<T>::check_index(size_t pos) const {
    if (pos >= _size || _states[pos] != State::busy) {
        throw std::out_of_range("Index is out of bounds or element is deleted.");
    }
}

template <typename T>
bool DMassive<T>::is_busy(size_t index) const noexcept {
    return _states[index] == State::busy;
}

template <typename T>
void DMassive<T>::push_back(T value) {
    if (full()) {
        reserve(STEP_CAPACITY);
    }
    _data[_size] = value;
    _states[_size++] = State::busy;
}

template <typename T>
void DMassive<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("Array is empty.");
    }
    _states[--_size] = State::deleted;
    _deleted++;
}

template <typename T>
void DMassive<T>::push_front(T value) {
    if (full()) {
        reserve(STEP_CAPACITY);
    }
    std::move_backward(_data, _data + _size, _data + _size + 1);
    _data[0] = value;
    _states[0] = State::busy;
    _size++;
}

template <typename T>
void DMassive<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("Array is empty.");
    }
    _states[0] = State::deleted;
    _deleted++;
    std::move(_data + 1, _data + _size, _data);
    _size--;
}

template <typename T>
DMassive<T>& DMassive<T>::insert(const T* arr, size_t n, size_t pos) {
    if (pos > _size) {
        throw std::out_of_range("Position is out of bounds.");
    }
    reserve(n);
    std::move_backward(_data + pos, _data + _size, _data + _size + n);
    for (size_t i = 0; i < n; i++) {
        _data[pos + i] = arr[i];
        _states[pos + i] = State::busy;
    }
    _size += n;
    return *this;
}

template <typename T>
DMassive<T>& DMassive<T>::insert(T value, size_t pos) {
    return insert(&value, 1, pos);
}

template <typename T>
DMassive<T>& DMassive<T>::replace(size_t pos, T new_value) {
    if (pos >= _size || _states[pos] != State::busy) {
        throw std::out_of_range("Index is out of bounds or element is deleted.");
    }
    _data[pos] = new_value;
    return *this;
}

template <typename T>
DMassive<T>& DMassive<T>::remove_by_index(size_t pos) {
    if (pos >= _size) {
        throw std::out_of_range("Index is out of bounds.");
    }
    _states[pos] = State::deleted;
    _deleted++;
    return *this;
}

template <typename T>
DMassive<T>& DMassive<T>::erase(size_t pos, size_t n) {
    if (pos + n > _size) {
        throw std::out_of_range("Range exceeds the size of the array.");
    }
    for (size_t i = pos; i < pos + n; i++) {
        _states[i] = State::deleted;
        _deleted++;
    }
    return *this;
}

template <typename T>
DMassive<T>& DMassive<T>::remove_all(T value) {
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::busy && _data[i] == value) {
            _states[i] = State::deleted;
            _deleted++;
        }
    }
    return *this;
}

template <typename T>
DMassive<T>& DMassive<T>::remove_first(T value) {
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::busy && _data[i] == value) {
            _states[i] = State::deleted;
            _deleted++;
            break;
        }
    }
    return *this;
}

template <typename T>
DMassive<T>& DMassive<T>::remove_last(T value) {
    for (size_t i = _size; i-- > 0;) {
        if (_states[i] == State::busy && _data[i] == value) {
            _states[i] = State::deleted;
            _deleted++;
            break;
        }
    }
    return *this;
}

template <typename T>
size_t DMassive<T>::find_first(T value) const noexcept {
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] == State::busy && _data[i] == value) {
            return i;
        }
    }
    return _size; 
}

template <typename T>
size_t DMassive<T>::find_last(T value) const noexcept {
    for (size_t i = _size; i-- > 0;) {
        if (_states[i] == State::busy && _data[i] == value) {
            return i;
        }
    }
    return _size; 
}

#endif // LIB_DMASSIVE_DMASSIVE_H_
