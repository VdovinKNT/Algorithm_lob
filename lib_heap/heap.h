// Copyright 2025 Artem Vdovin

#ifndef LIB_HEAP_HEAP_H_
#define LIB_HEAP_HEAP_H_

#include <functional>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

#include "../lib_dmassive/dmassive.h"

enum heapType
{
    MAX,
    MIN
};

template <class T>
bool max(T val1, T val2)
{
    return val1 > val2;
}

template <class T>
bool min(T val1, T val2)
{
    return val1 < val2;
}

template <class T>
class Heap
{
private:
    DMassive<T> _data;
    bool (*SrFunc)(T val1, T val2);

public:
    Heap() : SrFunc(min) {}
    Heap(bool (*Funk)(T val1, T val2)) : SrFunc(Funk), _data() {}
    Heap(T* mas, size_t size, bool (*Funk)(T val1, T val2) = min) : _data(mas, size), SrFunc(Funk) { heapify(); }

    size_t left(size_t pos);
    size_t right(size_t pos);
    size_t parent(size_t pos);
    T top()
    {
        if (_data.empty())
        {
            throw std::out_of_range("Heap is empty");
        }
        return _data[0];
    }

    void print() { printTree(0, 0); }
    void printMass() { _data.print(); }
    void printTree(size_t index, int indent);

    bool isEmpty();

    void insert(T val);
    size_t find(T val);
    void erase(size_t idx);

private:
    void heapify();
    void shift_up(size_t pos);
    void shift_down(size_t pos);
};

template <class T>
bool Heap<T>::isEmpty()
{
    return _data.empty();
}

template <class T>
size_t Heap<T>::parent(size_t pos)
{
    return (pos - 1) / 2;
}

template <class T>
size_t Heap<T>::right(size_t pos)
{
    return (2 * pos) + 2;
}

template <class T>
size_t Heap<T>::left(size_t pos)
{
    return (2 * pos) + 1;
}

template <class T>
void Heap<T>::shift_down(size_t pos)
{
    size_t extremum = pos;
    while (true)
    {
        size_t left_child = left(pos);
        size_t right_child = right(pos);

        if (left_child < _data.size() && SrFunc(_data[left_child], _data[extremum]))
        {
            extremum = left_child;
        }
        if (right_child < _data.size() && SrFunc(_data[right_child], _data[extremum]))
        {
            extremum = right_child;
        }
        if (extremum == pos)
        {
            break;
        }

        std::swap(_data[pos], _data[extremum]);
        pos = extremum;
    }
}

template <class T>
void Heap<T>::shift_up(size_t pos)
{
    size_t _pos = pos;
    while (_pos > 0 && SrFunc(_data[_pos], _data[parent(_pos)]))
    {
        std::swap(_data[parent(_pos)], _data[_pos]);
        _pos = parent(_pos);
    }
}

template <class T>
void Heap<T>::insert(T val)
{
    _data.push_back(val);
    size_t pos = _data.size() - 1;
    shift_up(pos);
}

template <class T>
size_t Heap<T>::find(T val)
{
    return _data.find_first(val);
}

template <class T>
void Heap<T>::heapify()
{
    for (int i = _data.size() - 1; i >= 0; --i)
    {
        shift_down(i);
    }
}

template <class T>
void Heap<T>::printTree(size_t index, int indent)
{
    if (index >= _data.size())
        return;

    printTree(right(index), indent + 4);

    if (indent)
    {
        std::cout << std::setw(indent) << ' ';
    }
    std::cout << _data[index] << "\n";

    printTree(left(index), indent + 4);
}

template <class T>
void Heap<T>::erase(size_t idx)
{
    if (isEmpty())
    {
        throw std::logic_error("Heap is Empty");
    }

    if (idx >= _data.size())
    {
        throw std::logic_error("Index out of range");
    }

    _data[idx] = _data[_data.size() - 1];
    _data.remove_by_index(_data.size() - 1);

    if (idx < _data.size())
    {
        shift_up(idx);
        shift_down(idx);
    }
}

#endif // LIB_HEAP_HEAP_H_