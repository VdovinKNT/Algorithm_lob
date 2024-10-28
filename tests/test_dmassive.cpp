#include <gtest.h>
#include "dmassive.h"

TEST(DMassiveTest, DefaultConstructor) {
    DMassive<int> array;
    EXPECT_TRUE(array.empty());
    EXPECT_EQ(array.size(), 0);
}

TEST(DMassiveTest, PushBack) {
    DMassive<int> array;
    array.push_back(10);
    EXPECT_EQ(array.size(), 1);
    EXPECT_EQ(array.data()[0], 10);
}

TEST(DMassiveTest, PopBack) {
    DMassive<int> array;
    array.push_back(10);
    array.pop_back();
    EXPECT_TRUE(array.empty());
}

TEST(DMassiveTest, PushFront) {
    DMassive<int> array;
    array.push_front(10);
    EXPECT_EQ(array.size(), 1);
    EXPECT_EQ(array.data()[0], 10);
}

TEST(DMassiveTest, PopFront) {
    DMassive<int> array;
    array.push_front(10);
    array.pop_front();
    EXPECT_TRUE(array.empty());
}

// Добавьте больше тестов для остальных функций

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
