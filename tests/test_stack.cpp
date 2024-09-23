// Copyright 2024 <Artem Vdovin>

#include "gtest.h"
#include "stack.h"

// Проверка пустого стека
TEST(TStackTest, Empty) {
    TStack<int> stack;
    ASSERT_TRUE(stack.empty());
}

// Проверка размера стека
TEST(TStackTest, Size) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(stack.size(), 2);
}

// Проверка добавления элемента в стек
TEST(TStackTest, Push) {
    TStack<int> stack;
    stack.push(1);
    ASSERT_EQ(stack.top(), 1);
}

// Проверка извлечения элемента из стека
TEST(TStackTest, Pop) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(stack.pop(), 2);
    ASSERT_EQ(stack.pop(), 1);
}

// Проверка извлечения элемента из пустого стека
TEST(TStackTest, PopEmpty) {
    TStack<int> stack;
    ASSERT_THROW(stack.pop(), std::out_of_range);
}

// Проверка получения верхушки стека
TEST(TStackTest, Top) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(stack.top(), 2);
}

// Проверка получения верхушки пустого стека
TEST(TStackTest, TopEmpty) {
    TStack<int> stack;
    ASSERT_THROW(stack.top(), std::out_of_range);
}
