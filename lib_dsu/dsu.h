#ifndef DSU_H
#define DSU_H

#include <iostream>
#include <stdexcept>

class DSU {
private:
    int _size;
    int* _parent;
    int* _rank;

public:
    DSU(int size = 0);
    ~DSU();

    void make_set(int elem);
    int find(int elem);
    void unite(int first, int second);
    void clear();
};

DSU::DSU(int size) : _size(size) {
    _parent = new int[size];
    _rank = new int[size];

    clear();
}

DSU::~DSU() {
    delete[] _parent;
    delete[] _rank;
}

void DSU::make_set(int elem) {
    if (elem <= 0 || elem > _size) {
        throw std::logic_error("Input Error: Element out of range.");
    }
    _parent[elem - 1] = elem;
    _rank[elem - 1] = 0;
}

int DSU::find(int elem) {
    if (elem <= 0 || elem > _size) {
        throw std::logic_error("Input Error: Element out of range.");
    }
    elem--;
    if (_parent[elem] != elem) {
        _parent[elem] = find(_parent[elem]); 
    }
    return _parent[elem];
}

void DSU::unite(int first, int second) {
    if (first <= 0 || first > _size || second <= 0 || second > _size) {
        throw std::logic_error("Input Error: Element out of range.");
    }

    int root_first = find(first);
    int root_second = find(second);

    if (root_first != root_second) {
        _parent[root_second - 1] = root_first;
    }
}

void DSU::clear() {
    for (int i = 0; i < _size; i++) {
        _parent[i] = i + 1;
        _rank[i] = 0;
    }
}



#endif // DSU_H

