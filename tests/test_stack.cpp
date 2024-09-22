#include "gtest/gtest.h"
#include "stack.h"

TEST(TStackTest, Empty) {
    TStack<int> stack;
    ASSERT_TRUE(stack.empty());
}

TEST(TStackTest, Size) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(stack.size(), 2);
}

TEST(TStackTest, Push) {
    TStack<int> stack;
    stack.push(1);
    ASSERT_EQ(stack.top(), 1);
}

TEST(TStackTest, Pop) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(stack.pop(), 2);
    ASSERT_EQ(stack.pop(), 1);
}

TEST(TStackTest, PopEmpty) {
    TStack<int> stack;
    ASSERT_THROW(stack.pop(), std::out_of_range);
}

TEST(TStackTest, Top) {
    TStack<int> stack;
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(stack.top(), 2);
}

TEST(TStackTest, TopEmpty) {
    TStack<int> stack;
    ASSERT_THROW(stack.top(), std::out_of_range);
}
