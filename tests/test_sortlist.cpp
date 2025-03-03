// Copyright 2024 Artem Vdovin

#include <gtest.h>
#include "../lib_list/list.h"
#include "../lib_sortlist/sortlist.h"

TEST(TestMergeSortedLists, MergeTwoNonEmptySortedLists) {
    TList<int> list1;
    list1.insertBack(1);
    list1.insertBack(3);
    list1.insertBack(5);

    TList<int> list2;
    list2.insertBack(2);
    list2.insertBack(4);
    list2.insertBack(6);

    TList<int> merged = mergeSortedLists(list1, list2);

    TList<int> expected;
    expected.insertBack(1);
    expected.insertBack(2);
    expected.insertBack(3);
    expected.insertBack(4);
    expected.insertBack(5);
    expected.insertBack(6);

    EXPECT_EQ(merged, expected);
}



