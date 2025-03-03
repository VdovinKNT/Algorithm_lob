#ifndef SORTLISTS_H_
#define SORTLISTS_H_

#include "../lib_list/list.h" 

template <class T>
TList<T> mergeSortedLists(const TList<T>& list1, const TList<T>& list2) {
    TList<T> mergedList;
    TNode<T>* node1 = list1.getHead();
    TNode<T>* node2 = list2.getHead();

    while (node1 && node2) {
        if (node1->getValue() < node2->getValue()) {
            mergedList.insertBack(node1->getValue());
            node1 = node1->getNext();
        }
        else {
            mergedList.insertBack(node2->getValue());
            node2 = node2->getNext();
        }
    }

    while (node1) {
        mergedList.insertBack(node1->getValue());
        node1 = node1->getNext();
    }

    while (node2) {
        mergedList.insertBack(node2->getValue());
        node2 = node2->getNext();
    }

    return mergedList;
}

#endif  // SORTLISTS_H_
