// Copyright 2024 Artem Vdovin

#include "gtest.h"
#include "../lib_list/list.h" 

// Тест для проверки пустого списка
TEST(TListTest, Empty) {
    TList<int> list;
    ASSERT_TRUE(list.is_empty());
}

// Тест для проверки размера пустого списка
TEST(TListTest, SizeEmpty) {
    TList<int> list;
    ASSERT_EQ(list.size(), 0);
}

// Тест для проверки вставки элемента в конец списка
TEST(TListTest, InsertTail) {
    TList<int> list;
    list.insert_tail(1);
    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(list.head->data, 1);
    ASSERT_EQ(list.tail->data, 1);
}

// Тест для проверки вставки элемента в начало списка
TEST(TListTest, InsertHead) {
    TList<int> list;
    list.insert_head(1);
    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(list.head->data, 1);
    ASSERT_EQ(list.tail->data, 1);
}

// Тест для проверки вставки элемента после указанного узла
TEST(TListTest, InsertAfter) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_after(list.head, 3);
    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list.head->data, 1);
    ASSERT_EQ(list.head->next->data, 3);
    ASSERT_EQ(list.tail->data, 2);
}

// Тест для проверки вставки элемента на указанную позицию
TEST(TListTest, InsertAt) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_at(1, 3);
    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list.head->data, 1);
    ASSERT_EQ(list.head->next->data, 3);
    ASSERT_EQ(list.tail->data, 2);
}

// Тест для проверки вставки элемента на первую позицию
TEST(TListTest, InsertAtFirst) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_at(0, 3);
    ASSERT_EQ(list.size(), 3);
    ASSERT_EQ(list.head->data, 3);
    ASSERT_EQ(list.head->next->data, 1);
    ASSERT_EQ(list.tail->data, 2);
}

// Тест для проверки вставки элемента на позицию за пределами диапазона
TEST(TListTest, InsertAtOutOfRange) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    ASSERT_THROW(list.insert_at(3, 3), std::out_of_range);
}

// Тест для проверки поиска элемента по значению
TEST(TListTest, Find) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    TNode<int>* node = list.find(2);
    ASSERT_NE(node, nullptr);
    ASSERT_EQ(node->data, 2);
}

// Тест для проверки поиска несуществующего элемента
TEST(TListTest, FindNotFound) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    TNode<int>* node = list.find(4);
    ASSERT_EQ(node, nullptr);
}

// Тест для проверки удаления элемента из конца списка
TEST(TListTest, RemoveTail) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    list.remove_tail();
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.tail->data, 2);
}

// Тест для проверки удаления элемента из начала списка
TEST(TListTest, RemoveHead) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    list.remove_head();
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.head->data, 2);
}

// Тест для проверки удаления указанного узла
TEST(TListTest, Remove) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    list.remove(list.head->next);
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.head->data, 1);
    ASSERT_EQ(list.tail->data, 3);
}

// Тест для проверки удаления узла по указанной позиции
TEST(TListTest, RemoveAt) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    list.remove_at(1);
    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.head->data, 1);
    ASSERT_EQ(list.tail->data, 3);
}

// Тест для проверки удаления узла из пустого списка
TEST(TListTest, RemoveFromEmptyList) {
    TList<int> list;
    ASSERT_THROW(list.remove_tail(), std::out_of_range);
    ASSERT_THROW(list.remove_head(), std::out_of_range);
}

// Тест для проверки удаления узла за пределами диапазона
TEST(TListTest, RemoveAtOutOfRange) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    ASSERT_THROW(list.remove_at(4), std::out_of_range);
}

// Тест для проверки замены значения указанного узла
TEST(TListTest, Replace) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    list.replace(list.head->next, 4);
    ASSERT_EQ(list.head->next->data, 4);
}

// Тест для проверки замены значения узла по указанной позиции
TEST(TListTest, ReplaceAt) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    list.replace_at(1, 4);
    ASSERT_EQ(list.head->next->data, 4);
}

// Тест для проверки замены значения узла за пределами диапазона
TEST(TListTest, ReplaceAtOutOfRange) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    ASSERT_THROW(list.replace_at(4, 4), std::out_of_range);
}

// Тест для проверки очистки списка
TEST(TListTest, Clear) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    list.clear();
    ASSERT_TRUE(list.is_empty());
    ASSERT_EQ(list.size(), 0);
}

// Тест для проверки оператора вывода
TEST(TListTest, OperatorOutput) {
    TList<int> list;
    list.insert_tail(1);
    list.insert_tail(2);
    list.insert_tail(3);
    std::stringstream ss;
    ss << list;
    ASSERT_EQ(ss.str(), "1 2 3 ");
}

// Тест для проверки конструктора копирования
TEST(TListTest, CopyConstructor) {
    TList<int> list1;
    list1.insert_tail(1);
    list1.insert_tail(2);
    list1.insert_tail(3);
    TList<int> list2(list1);
    ASSERT_EQ(list2.size(), 3);
    ASSERT_EQ(list2.head->data, 1);
    ASSERT_EQ(list2.head->next->data, 2);
    ASSERT_EQ(list2.tail->data, 3);
}

// Тест для проверки оператора присваивания
TEST(TListTest, OperatorAssign) {
    TList<int> list1;
    list1.insert_tail(1);
    list1.insert_tail(2);
    list1.insert_tail(3);
    TList<int> list2;
    list2 = list1;
    ASSERT_EQ(list2.size(), 3);
    ASSERT_EQ(list2.head->data, 1);
    ASSERT_EQ(list2.head->next->data, 2);
    ASSERT_EQ(list2.tail->data, 3);
}

