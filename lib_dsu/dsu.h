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

#endif // DSU_H

