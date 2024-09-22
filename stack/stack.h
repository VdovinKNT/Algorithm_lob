#ifndef STACK_H
#define STACK_H

template <typename T>
class TStack {
public:
    TStack() : _data(nullptr), _size(0), _top(-1), _capacity(0) {}

    ~TStack() { delete[] _data; }

    bool empty() const {
        return _size == 0;
    }

    size_t size() const {
        return _size;
    }

    void push(const T& value) {
        if (_size == _capacity) {
            resize();
        }
        _data[++_top] = value;
        _size++;
    }

    T pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        _size--;
        return _data[_top--];
    }

    const T& top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return _data[_top];
    }

private:
    T* _data;     
    size_t _size;  
    size_t _top;   
    size_t _capacity; 

    void resize() {
        _capacity = _capacity == 0 ? 1 : _capacity * 2;
        T* new_data = new T[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
    }
};

#endif // STACK_H
