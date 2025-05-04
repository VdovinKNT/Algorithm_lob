// Copyright 2024 Artem Vdovin

#include <gtest.h>
#include "../lib_dsu/dsu.h"

TEST(DSU, can_create_dsu_with_positive_size) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(DSU dsu(10));
}

TEST(DSU, can_create_dsu_with_zero_size) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(DSU dsu(0));
}

TEST(DSU, can_make_set) {
    // Arrange
    DSU dsu(10);

    // Act & Assert
    ASSERT_NO_THROW(dsu.make_set(5));
}

TEST(DSU, throw_when_make_set_with_invalid_element_greater_than_size) {
    // Arrange
    DSU dsu(10);

    // Act & Assert
    ASSERT_ANY_THROW(dsu.make_set(11));
}

TEST(DSU, throw_when_make_set_with_invalid_element_less_than_one) {
    // Arrange
    DSU dsu(10);

    // Act & Assert
    ASSERT_ANY_THROW(dsu.make_set(0));
}

TEST(DSU, throw_when_find_with_invalid_element_greater_than_size) {
    // Arrange
    DSU dsu(10);

    // Act & Assert
    ASSERT_ANY_THROW(dsu.find(11));
}

TEST(DSU, throw_when_find_with_invalid_element_less_than_one) {
    // Arrange
    DSU dsu(10);

    // Act & Assert
    ASSERT_ANY_THROW(dsu.find(0));
}

TEST(DSU, throw_when_unite_with_invalid_element_greater_than_size) {
    // Arrange
    DSU dsu(10);

    // Act & Assert
    ASSERT_ANY_THROW(dsu.unite(2, 11));
    ASSERT_ANY_THROW(dsu.unite(11, 2));
}

TEST(DSU, throw_when_unite_with_invalid_element_less_than_one) {
    // Arrange
    DSU dsu(10);

    // Act & Assert
    ASSERT_ANY_THROW(dsu.unite(2, 0));
    ASSERT_ANY_THROW(dsu.unite(0, 2));
}

TEST(DSU, unite_by_rank) {
    // Arrange
    DSU dsu(5);
    for (int i = 1; i <= 5; ++i) {
        dsu.make_set(i);
    }

    // Act
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    dsu.unite(1, 3);

    // Assert
    EXPECT_EQ(dsu.find(1), dsu.find(2));
    EXPECT_EQ(dsu.find(1), dsu.find(3));
    EXPECT_EQ(dsu.find(1), dsu.find(4));
    EXPECT_NE(dsu.find(1), dsu.find(5));
}

TEST(DSU, find_with_path_compression) {
    // Arrange
    DSU dsu(5);
    for (int i = 1; i <= 5; ++i) {
        dsu.make_set(i);
    }

    dsu.unite(1, 2);
    dsu.unite(2, 3);
    dsu.unite(3, 4);

    // Act
    int root = dsu.find(4);

    // Assert 
    EXPECT_EQ(root, dsu.find(2));
}
