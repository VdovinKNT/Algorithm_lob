// Copyright 2024 Marina Usova
#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"
#include "../lib_pair/pair.h"
#include "../stack/stack.h" 
#include <stack>
#include "../lib_dmassive/dmassive.h" 
#include "../lib_vector/vector.h" 

int main() {
    int a, b;
    float result;

    a = 1; b = 4;

    try {
        result = division(a, b);
        std::cout << a << " / " << b << " = "
            << std::setprecision(2) << result << std::endl;
    }
    catch (std::exception err) {
        std::cerr << err.what() << std::endl;
    }

    a = 1; b = 0;

    try {
        result = division(a, b);
        std::cout << a << " / " << b << " = "
            << std::setprecision(2) << result << std::endl;
    }
    catch (std::exception err) {
        std::cerr << err.what() << std::endl;
    }

    Pair<int, double> p1(1, 3.14);
    Pair<int, double> p2(2, 2.71);

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;

    Pair<int, double> p3 = p1 + p2;
    std::cout << "p3: " << p3 << std::endl;

    TStack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Стек (ваш): ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    std::stack<int> stdStack;
    stdStack.push(1);
    stdStack.push(2);
    stdStack.push(3);

    std::cout << "Стек (стандартный): ";
    while (!stdStack.empty()) {
        std::cout << stdStack.top() << " ";
        stdStack.pop();
    }
    std::cout << std::endl;

    TDMassive<int> dMassive;
    dMassive.insert(0, 1);
    dMassive.insert(1, 2);
    dMassive.insert(2, 3);
    std::cout << "Динамический массив: " << dMassive << std::endl;

    TVector<int> vector(3);
    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;
    std::cout << "Вектор: " << vector[0] << " " << vector[1] << " " << vector[2] << std::endl;

    return 0;
}

#endif  // EASY_EXAMPLE

