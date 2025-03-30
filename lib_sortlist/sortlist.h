// Copyright 2025 Artem Vdovin

#ifndef MERGE_SORTED_LISTS_H_
#define MERGE_SORTED_LISTS_H_

#include "../lib_List/List.h"

template <typename T>
TList<T> mergeSortedLists(const TList<T>& list1, const TList<T>& list2) {
    TList<T> result;
    TNode<T>* node1 = list1.getHead();
    TNode<T>* node2 = list2.getHead();

    while (node1 && node2) {
        if (node1->getValue() < node2->getValue()) {
            result.insertBack(node1->getValue());
            node1 = node1->getNext();
        }
        else {
            result.insertBack(node2->getValue());
            node2 = node2->getNext();
        }
    }

    while (node1) {
        result.insertBack(node1->getValue());
        node1 = node1->getNext();
    }

    while (node2) {
        result.insertBack(node2->getValue());
        node2 = node2->getNext();
    }

    return result;
}

#endif  // MERGE_SORTED_LISTS_H_