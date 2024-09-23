// Copyright 2024 Marina Usova
#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <locale>
#include "../lib_easy_example/easy_example.h"
#include "../lib_pair/pair.h"
#include "../stack/stack.h" 
#include <stack>
#include "../lib_dmassive/dmassive.h" 
#include "../lib_vector/vector.h" 

int main() {
    std::locale::global(std::locale(""));

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
    std::locale::global(std::locale(""));
    // ������������ ������ � Pair
    std::cout << "\n������������ Pair:" << std::endl;
    TPair<int, double> p1(1, 3.14);
    TPair<int, double> p2(2, 2.71);

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;

    TPair<int, double> p3 = p1 + p2;
    std::cout << "p3 (p1 + p2): " << p3 << std::endl;

    p1 += p2;
    std::cout << "p1 (p1 += p2): " << p1 << std::endl;

    p3 = p1 -= p2;
    std::cout << "p3 (p1 - p2): " << p3 << std::endl;

    p1 -= p2;
    std::cout << "p1 (p1 -= p2): " << p1 << std::endl;

    // ������������ ������ �� ������
    std::cout << "\n������������ �����:" << std::endl;
    TStack<int> myStack;
    myStack.push(1);
    std::cout << "���� (���) ����� push(1): " << myStack << std::endl;
    myStack.push(2);
    std::cout << "���� (���) ����� push(2): " << myStack << std::endl;
    myStack.push(3);
    std::cout << "���� (���) ����� push(3): " << myStack << std::endl;
    std::cout << "���� (���) top: " << myStack.top() << std::endl;

    std::cout << "���� (���) pop: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    // ������������ ������ �� ����������� ������
    std::cout << "\n������������ ������������ �����:" << std::endl;
    std::stack<int> stdStack;
    stdStack.push(1);
    std::cout << "���� (�����������) ����� push(1): ";
    while (!stdStack.empty()) {
        std::cout << stdStack.top() << " ";
        stdStack.pop();
    }
    std::cout << std::endl;
    stdStack.push(2);
    std::cout << "���� (�����������) ����� push(2): ";
    while (!stdStack.empty()) {
        std::cout << stdStack.top() << " ";
        stdStack.pop();
    }
    std::cout << std::endl;
    stdStack.push(3);
    std::cout << "���� (�����������) ����� push(3): ";
    while (!stdStack.empty()) {
        std::cout << stdStack.top() << " ";
        stdStack.pop();
    }
    std::cout << std::endl;

    // ������������ ������ � ������������ ��������
    std::cout << "\n������������ ������������� �������:" << std::endl;
    TDMassive<int> dMassive;
    std::cout << "������������ ������ (������): " <<
        dMassive << std::endl;
    dMassive.insert(0, 1);
    std::cout << "������������ ������ ����� insert(0, 1): " <<
        dMassive << std::endl;
    dMassive.insert(1, 2);
    std::cout << "������������ ������ ����� insert(1, 2): " <<
        dMassive << std::endl;
    dMassive.insert(2, 3);
    std::cout << "������������ ������ ����� insert(2, 3): " <<
        dMassive << std::endl;

    // ������������ ������ � ��������
    std::cout << "\n������������ �������:" << std::endl;
    TVector<int> vector(3);
    vector[0] = 1;
    vector[1] = 2;
    vector[2] = 3;
    std::cout << "������: " << vector[0] << " " << vector[1] << " " <<
        vector[2] << std::endl;

    return 0;
}

#endif  // EASY_EXAMPLE
