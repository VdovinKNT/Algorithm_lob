// Copyright 2024 <Artem Vdovin>

#include "gtest.h"
#include "../lib_pair/pair.h"

// Проверка конструктора по умолчанию
TEST(TPairTest, DefaultConstructor) {
    TPair<int, std::string> p;
    ASSERT_EQ(p.first, 0);
    ASSERT_EQ(p.second, "");
}

// Проверка параметризированного конструктора
TEST(TPairTest, ParameterizedConstructor) {
    TPair<int, std::string> p(10, "Hello");
    ASSERT_EQ(p.first, 10);
    ASSERT_EQ(p.second, "Hello");
}

// Проверка копирующего конструктора
TEST(TPairTest, CopyConstructor) {
    TPair<int, std::string> p1(5, "World");
    TPair<int, std::string> p2(p1);
    ASSERT_EQ(p2.first, 5);
    ASSERT_EQ(p2.second, "World");
}

// Проверка оператора равенства
TEST(TPairTest, EqualityOperator) {
    TPair<int, std::string> p1(1, "A");
    TPair<int, std::string> p2(1, "A");
    ASSERT_TRUE(p1 == p2);
}

// Проверка оператора неравенства
TEST(TPairTest, InequalityOperator) {
    TPair<int, std::string> p1(1, "A");
    TPair<int, std::string> p2(2, "B");
    ASSERT_TRUE(p1 != p2);
}

// Проверка оператора вывода
TEST(TPairTest, OutputOperator) {
    TPair<int, std::string> p(3, "Test");
    std::stringstream ss;
    ss << p;
    ASSERT_EQ(ss.str(), "(3, Test)");
}

// Проверка арифметических операторов
TEST(TPairTest, ArithmeticOperators) {
    TPair<int, int> p1(1, 2);
    TPair<int, int> p2(3, 4);
    TPair<int, int> p3 = p1 + p2;
    ASSERT_EQ(p3.first, 4);
    ASSERT_EQ(p3.second, 6);
    p1 += p2;
    ASSERT_EQ(p1.first, 4);
    ASSERT_EQ(p1.second, 6);
    p3 = p1 -= p2;
    ASSERT_EQ(p3.first, 1);
    ASSERT_EQ(p3.second, 2);
    p1 -= p2;
    ASSERT_EQ(p1.first, 1);
    ASSERT_EQ(p1.second, 2);
}