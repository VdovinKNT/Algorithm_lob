// Copyright 2024 Artem Vdovin

#include <gtest.h>
#include "../lib_stack_list/stack_List.h"

TEST(TStackOnList, can_create_stack_with_positive_capacity) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(TStackOnList<int> stack(10));
}

TEST(TStackOnList, throw_when_create_stack_with_zero_capacity) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(TStackOnList<int> stack(0));
}

TEST(TStackOnList, can_push_element) {
    // Arrange
    TStackOnList<int> stack(10);

    // Act & Assert
    ASSERT_NO_THROW(stack.push(5));
}

TEST(TStackOnList, throw_when_push_into_full_stack) {
    // Arrange
    TStackOnList<int> stack(2);
    stack.push(1);
    stack.push(2);

    // Act & Assert
    ASSERT_ANY_THROW(stack.push(3));
}

TEST(TStackOnList, can_pop_element) {
    // Arrange
    TStackOnList<int> stack(10);
    stack.push(5);

    // Act
    int value = stack.pop();

    // Assert
    EXPECT_EQ(value, 5);
}

TEST(TStackOnList, throw_when_pop_from_empty_stack) {
    // Arrange
    TStackOnList<int> stack(10);

    // Act & Assert
    ASSERT_ANY_THROW(stack.pop());
}

TEST(TStackOnList, can_get_top_element) {
    // Arrange
    TStackOnList<int> stack(10);
    stack.push(5);

    // Act
    int value = stack.top();

    // Assert
    EXPECT_EQ(value, 5);
}

TEST(TStackOnList, throw_when_get_top_from_empty_stack) {
    // Arrange
    TStackOnList<int> stack(10);

    // Act & Assert
    ASSERT_ANY_THROW(stack.top());
}

TEST(TStackOnList, is_empty_returns_true_for_empty_stack) {
    // Arrange
    TStackOnList<int> stack(10);

    // Act & Assert
    EXPECT_TRUE(stack.isEmpty());
}

TEST(TStackOnList, is_empty_returns_false_for_non_empty_stack) {
    // Arrange
    TStackOnList<int> stack(10);
    stack.push(5);

    // Act & Assert
    EXPECT_FALSE(stack.isEmpty());
}

TEST(TStackOnList, is_full_returns_false_for_non_full_stack) {
    // Arrange
    TStackOnList<int> stack(10);
    stack.push(5);

    // Act & Assert
    EXPECT_FALSE(stack.isFull());
}

TEST(TStackOnList, is_full_returns_true_for_full_stack) {
    // Arrange
    TStackOnList<int> stack(2);
    stack.push(1);
    stack.push(2);

    // Act & Assert
    EXPECT_TRUE(stack.isFull());
}

TEST(TStackOnList, size_returns_correct_value) {
    // Arrange
    TStackOnList<int> stack(10);
    stack.push(1);
    stack.push(2);

    // Act & Assert
    EXPECT_EQ(stack.size(), 2);
}

TEST(TStackOnList, capacity_returns_correct_value) {
    // Arrange
    TStackOnList<int> stack(10);

    // Act & Assert
    EXPECT_EQ(stack.capacity(), 10);
}

TEST(TStackOnList, supports_combined_operations) {
    // Arrange
    TStackOnList<int> stack(5);
    stack.push(1);
    stack.push(2);

    // Act
    int top1 = stack.top();
    stack.pop();
    int top2 = stack.top();
    stack.push(3);
    int size = stack.size();

    // Assert
    EXPECT_EQ(top1, 2);
    EXPECT_EQ(top2, 1);
    EXPECT_EQ(size, 2);
}
