// Copyright 2025 Artem Vdovin

#include <gtest.h>
#include "../lib_list/list.h"
#include "../lib_sortlist/sortlist.h"

TEST(TestMergeSortedListsLib, can_merge_two_sorted_lists) {
    // Arrange
    TList<int> list1;
    TList<int> list2;

    list1.insertBack(1);
    list1.insertBack(3);
    list1.insertBack(5);
    list1.insertBack(7);
    list1.insertBack(9);

    list2.insertBack(2);
    list2.insertBack(4);
    list2.insertBack(6);
    list2.insertBack(8);
    list2.insertBack(10);

    // Act
    TList<int> merged = mergeSortedLists(list1, list2);

    // Assert
    int expected[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int count = 0;
    for (auto it = merged.begin(); it != merged.end(); ++it) {
        EXPECT_EQ(expected[count], *it);
        count++;
    }
    EXPECT_EQ(count, 10);
}

TEST(TestMergeSortedListsLib, merging_empty_and_non_empty_lists) {
    // Arrange
    TList<int> emptyList;
    TList<int> nonEmptyList;

    nonEmptyList.insertBack(1);
    nonEmptyList.insertBack(2);
    nonEmptyList.insertBack(3);

    // Act
    TList<int> merged1 = mergeSortedLists(emptyList, nonEmptyList);
    TList<int> merged2 = mergeSortedLists(nonEmptyList, emptyList);

    // Assert
    int expected[] = { 1, 2, 3 };
    int count1 = 0, count2 = 0;

    for (auto it = merged1.begin(); it != merged1.end(); ++it) {
        EXPECT_EQ(expected[count1], *it);
        count1++;
    }
    for (auto it = merged2.begin(); it != merged2.end(); ++it) {
        EXPECT_EQ(expected[count2], *it);
        count2++;
    }

    EXPECT_EQ(count1, 3);
    EXPECT_EQ(count2, 3);
}

TEST(TestMergeSortedListsLib, merging_two_empty_lists) {
    // Arrange
    TList<int> emptyList1;
    TList<int> emptyList2;

    // Act
    TList<int> merged = mergeSortedLists(emptyList1, emptyList2);

    // Assert
    int count = 0;
    for (auto it = merged.begin(); it != merged.end(); ++it) {
        count++;
    }
    EXPECT_EQ(count, 0);
}

TEST(TestMergeSortedListsLib, merging_lists_with_duplicates) {
    // Arrange
    TList<int> list1;
    TList<int> list2;

    list1.insertBack(1);
    list1.insertBack(3);
    list1.insertBack(5);

    list2.insertBack(1);
    list2.insertBack(2);
    list2.insertBack(6);

    // Act
    TList<int> merged = mergeSortedLists(list1, list2);

    // Assert
    int expected[] = { 1, 1, 2, 3, 5, 6 };
    int idx = 0;
    for (auto it = merged.begin(); it != merged.end(); ++it) {
        EXPECT_EQ(expected[idx], *it);
        idx++;
    }
    EXPECT_EQ(idx, 6);
}


