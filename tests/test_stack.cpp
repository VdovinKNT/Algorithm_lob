#include "gtest.h"
#include "../stack/stack.h"

// Проверка пустого стека
TEST(TStackTest, Empty) {
    TStack<int> stack;
    ASSERT_TRUE(stack.empty());
    ASSERT_EQ(stack.size(), 0);
}

// Проверка добавления элемента в стек
TEST(TStackTest, Push) {
    TStack<int> stack;
    stack.push(1);
    ASSERT_FALSE(stack.empty());
    ASSERT_EQ(stack.size(), 1);
    ASSERT_EQ(stack.top(), 1);
}

// Проверка добавления нескольких элементов в стек
TEST(TStackTest, PushMultiple) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    ASSERT_EQ(stack.size(), 3);
    ASSERT_EQ(stack.top(), 3);
}

// Проверка удаления элемента из стека
TEST(TStackTest, Pop) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.pop();
    ASSERT_EQ(stack.top(), 1);
    ASSERT_EQ(stack.size(), 1);
}

// Проверка удаления элемента из пустого стека 
TEST(TStackTest, PopEmpty) {
    TStack<int> stack;
    ASSERT_THROW(stack.pop(), std::runtime_error);
}

// Проверка получения значения вершины стека
TEST(TStackTest, Top) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(stack.top(), 2);
}

// Проверка получения значения вершины пустого стека 
TEST(TStackTest, TopEmpty) {
    TStack<int> stack;
    ASSERT_THROW(stack.top(), std::runtime_error);
}

// Проверка конструктора копирования
TEST(TStackTest, CopyConstructor) {
    TStack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    TStack<int> stack2(stack1);
    ASSERT_EQ(stack2.size(), 2);
    ASSERT_EQ(stack2.top(), 2);
}

// Проверка оператора присваивания
TEST(TStackTest, CopyAssignment) {
    TStack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    TStack<int> stack2;
    stack2 = stack1;
    ASSERT_EQ(stack2.size(), 2);
    ASSERT_EQ(stack2.top(), 2);
}

// Проверка конструктора перемещения
TEST(TStackTest, MoveConstructor) {
    TStack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    TStack<int> stack2(std::move(stack1));
    ASSERT_EQ(stack2.size(), 2);
    ASSERT_EQ(stack2.top(), 2);
    ASSERT_TRUE(stack1.empty());
}

// Проверка оператора перемещения
TEST(TStackTest, MoveAssignment) {
    TStack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    TStack<int> stack2;
    stack2 = std::move(stack1);
    ASSERT_EQ(stack2.size(), 2);
    ASSERT_EQ(stack2.top(), 2);
    ASSERT_TRUE(stack1.empty());
}



