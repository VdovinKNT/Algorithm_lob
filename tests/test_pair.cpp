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

// Проверка оператора присваивания
TEST(TPairTest, AssignmentOperator) {
    TPair<int, std::string> p1(7, "Assign");
    TPair<int, std::string> p2;
    p2 = p1;
    ASSERT_EQ(p2.first, 7);
    ASSERT_EQ(p2.second, "Assign");
}

// Проверка функции swap
TEST(TPairTest, SwapFunction) {
    TPair<int, std::string> p1(8, "First");
    TPair<int, std::string> p2(9, "Second");
    p1.swap(p2);
    ASSERT_EQ(p1.first, 9);
    ASSERT_EQ(p1.second, "Second");
    ASSERT_EQ(p2.first, 8);
    ASSERT_EQ(p2.second, "First");
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

// Проверка функции make_pair
TEST(TPairTest, MakePairFunction) {
    auto p = make_pair(42, std::string("Hello MakePair"));
    ASSERT_EQ(p.first, 42);
    ASSERT_EQ(p.second, "Hello MakePair");
}