#include "gtest/gtest.h"
#include "dmassive.h"

TEST(TDMassiveTest, Insert) {
    TDMassive<int> massive;
    massive.insert(0, 1);
    ASSERT_EQ(massive.find(1), 0);
}

TEST(TDMassiveTest, InsertAtEnd) {
    TDMassive<int> massive;
    massive.insert(0, 1);
    massive.insert(1, 2);
    ASSERT_EQ(massive.find(2), 1);
}

TEST(TDMassiveTest, InsertAtMiddle) {
    TDMassive<int> massive;
    massive.insert(0, 1);
    massive.insert(1, 3);
    massive.insert(1, 2);
    ASSERT_EQ(massive.find(2), 1);
    ASSERT_EQ(massive.find(3), 2);
}

TEST(TDMassiveTest, InsertOutOfRange) {
    TDMassive<int> massive;
    ASSERT_THROW(massive.insert(1, 1), std::out_of_range);
}

TEST(TDMassiveTest, Find) {
    TDMassive<int> massive;
    massive.insert(0, 1);
    ASSERT_EQ(massive.find(1), 0);
}

TEST(TDMassiveTest, FindNotFound) {
    TDMassive<int> massive;
    massive.insert(0, 1);
    ASSERT_EQ(massive.find(2), -1);
}

TEST(TDMassiveTest, Erase) {
    TDMassive<int> massive;
    massive.insert(0, 1);
    massive.insert(1, 2);
    massive.erase(1);
    ASSERT_EQ(massive.find(2), -1);
}

TEST(TDMassiveTest, EraseOutOfRange) {
    TDMassive<int> massive;
    ASSERT_THROW(massive.erase(1), std::out_of_range);
}

TEST(TDMassiveTest, Replace) {
    TDMassive<int> massive;
    massive.insert(0, 1);
    massive.replace(0, 2);
    ASSERT_EQ(massive.find(1), -1);
    ASSERT_EQ(massive.find(2), 0);
}

TEST(TDMassiveTest, ReplaceOutOfRange) {
    TDMassive<int> massive;
    ASSERT_THROW(massive.replace(1, 1), std::out_of_range);
}

TEST(TDMassiveTest, Clear) {
    TDMassive<int> massive;
    massive.insert(0, 1);
    massive.clear();
    ASSERT_EQ(massive.find(1), -1);
}

TEST(TDMassiveTest, Resize) {
    TDMassive<int> massive;
    for (int i = 0; i < 10; ++i) {
        massive.insert(i, i);
    }
    ASSERT_GT(massive.m_capacity, 10);
}

TEST(TDMassiveTest, OperatorOutput) {
    TDMassive<int> massive;
    massive.insert(0, 1);
    massive.insert(1, 2);
    std::stringstream ss;
    ss << massive;
    ASSERT_EQ(ss.str(), "1 2 ");
}

