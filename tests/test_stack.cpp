#include "gtest.h"
#include "../stack/stack.h"

TEST(TStackTest, Empty) {
    TStack<int> stack(10);
    ASSERT_TRUE(stack.isEmpty());
    ASSERT_EQ(stack.size(), 0);
}

TEST(TStackTest, Push) {
    TStack<int> stack(10);
    stack.push(1);
    ASSERT_FALSE(stack.isEmpty());
    ASSERT_EQ(stack.size(), 1);
    ASSERT_EQ(stack.top(), 1);
}

TEST(TStackTest, PushMultiple) {
    TStack<int> stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    ASSERT_EQ(stack.size(), 3);
    ASSERT_EQ(stack.top(), 3);
}

TEST(TStackTest, Pop) {
    TStack<int> stack(10);
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(stack.pop(), 2);
    ASSERT_EQ(stack.top(), 1);
    ASSERT_EQ(stack.size(), 1);
}

TEST(TStackTest, PopEmpty) {
    TStack<int> stack(10);
    ASSERT_THROW(stack.pop(), std::underflow_error);
}

TEST(TStackTest, Top) {
    TStack<int> stack(10);
    stack.push(1);
    stack.push(2);
    ASSERT_EQ(stack.top(), 2);
}

TEST(TStackTest, TopEmpty) {
    TStack<int> stack(10);
    ASSERT_THROW(stack.top(), std::underflow_error);
}

TEST(TStackTest, Overflow) {
    TStack<int> stack(2);
    stack.push(1);
    stack.push(2);
    ASSERT_THROW(stack.push(3), std::overflow_error);
}

TEST(ExpressionValidationTest, ValidExpressions) {
    ASSERT_TRUE(isValidExpression("(a+b)*[c-d]"));
    ASSERT_TRUE(isValidExpression("{[()]}"));
    ASSERT_TRUE(isValidExpression("|a| + |b|"));
}

TEST(ExpressionValidationTest, InvalidExpressions) {
    ASSERT_FALSE(isValidExpression("(a+b]*c-d)"));
    ASSERT_FALSE(isValidExpression("{[(])}"));
    ASSERT_FALSE(isValidExpression("|a| + b|"));
}
