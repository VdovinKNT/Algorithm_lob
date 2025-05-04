// Copyright 2025 Artem Vdovin

#include <gtest.h>
#include "../lib_Heap/Heap.h"

#define EPSILON 0.000001

TEST(HeapTest, can_create_default_heap)
{
    // Arrange & Act
    Heap<int> heap;

    // Assert
    ASSERT_TRUE(heap.isEmpty());
}

TEST(HeapTest, can_create_heap_with_custom_comparator)
{
    // Arrange & Act
    Heap<int> heap(max<int>);

    // Assert
    ASSERT_TRUE(heap.isEmpty());
}

TEST(HeapTest, can_insert_elements_to_heap)
{
    // Arrange
    Heap<int> heap;

    // Act
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    // Assert
    EXPECT_EQ(heap.top(), 5);
}

TEST(HeapTest, can_insert_elements_to_max_heap)
{
    // Arrange
    Heap<int> heap(max<int>);

    // Act
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    // Assert
    EXPECT_EQ(heap.top(), 20);
}

TEST(HeapTest, throws_when_erasing_nonexistent_element)
{
    // Arrange
    Heap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    // Act & Assert
    ASSERT_THROW(heap.erase(30), std::logic_error);
}

TEST(HeapTest, can_get_top_element_from_heap)
{
    // Arrange
    Heap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    // Act & Assert
    EXPECT_EQ(heap.top(), 5);
}

TEST(HeapTest, throws_when_getting_top_from_empty_heap)
{
    // Arrange
    Heap<int> heap;

    // Act & Assert
    ASSERT_THROW(heap.top(), std::out_of_range);
}

TEST(HeapTest, can_find_element_in_heap)
{
    // Arrange
    Heap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    // Act
    size_t foundIdx = heap.find(20);

    // Assert
    EXPECT_NE(foundIdx, static_cast<size_t>(-1));
}

TEST(HeapTest, throws_when_finding_nonexistent_element)
{
    // Arrange
    Heap<int> heap;
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    // Act & Assert
    ASSERT_EQ(heap.find(30), static_cast<size_t>(-1));
}

TEST(HeapTest, can_heapify_unsorted_array)
{
    // Arrange
    int arr[] = { 10, 20, 5, 30, 25 };

    // Act
    Heap<int> heap(arr, 5);

    // Assert
    EXPECT_EQ(heap.top(), 5);
}

TEST(HeapTest, can_handle_large_number_of_elements)
{
    // Arrange
    Heap<int> heap;
    for (int i = 0; i < 10000; ++i)
    {
        heap.insert(i);
    }

    // Act & Assert
    EXPECT_EQ(heap.top(), 0);
}

TEST(HeapTest, can_handle_large_number_of_elements_in_max_heap)
{
    // Arrange
    Heap<int> heap(max<int>);
    for (int i = 0; i < 10000; ++i)
    {
        heap.insert(i);
    }

    // Act & Assert
    EXPECT_EQ(heap.top(), 9999);
}

TEST(HeapTest, can_erase_element_from_max_heap)
{
    // Arrange
    Heap<int> heap(max<int>);
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    // Act
    heap.erase(0);

    // Assert
    EXPECT_EQ(heap.top(), 10);
}

TEST(HeapTest, throws_when_erasing_from_empty_heap)
{
    // Arrange
    Heap<int> heap;

    // Act & Assert
    ASSERT_THROW(heap.erase(0), std::logic_error);
}

TEST(HeapTest, can_handle_erase_last_element_properly)
{
    // Arrange
    Heap<int> heap(max<int>);
    heap.insert(10);

    // Act
    heap.erase(0);

    // Assert
    ASSERT_TRUE(heap.isEmpty());
}

TEST(HeapTest, throws_when_erasing_out_of_range_index)
{
    // Arrange
    Heap<int> heap(max<int>);
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    // Act & Assert
    ASSERT_THROW(heap.erase(5), std::logic_error);
}

TEST(HeapTest, can_erase_multiple_elements)
{
    // Arrange
    Heap<int> heap(max<int>);
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    // Act
    heap.erase(0);
    heap.erase(1);

    // Assert
    EXPECT_EQ(heap.top(), 10);
}

TEST(HeapTest, can_erase_last_element)
{
    // Arrange
    Heap<int> heap(max<int>);
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    // Act
    heap.erase(2);

    // Assert
    EXPECT_EQ(heap.top(), 20);
}