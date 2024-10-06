// Copyright 2024 Artem Vdovin

#include "gtest/gtest.h"
#include "queue.h"

// Тест для проверки пустой очереди
TEST(TQueueTest, Empty) {
	TQueue<int> queue;
	ASSERT_TRUE(queue.empty());
}

// Тест для проверки размера пустой очереди
TEST(TQueueTest, SizeEmpty) {
	TQueue<int> queue;
	ASSERT_EQ(queue.size(), 0);
}

// Тест для проверки добавления элемента в очередь
TEST(TQueueTest, Push) {
	TQueue<int> queue;
	queue.push(1);
	ASSERT_EQ(queue.size(), 1);
	ASSERT_EQ(queue.front(), 1);
}

// Тест для проверки извлечения элемента из очереди
TEST(TQueueTest, Pop) {
	TQueue<int> queue;
	queue.push(1);
	queue.push(2);
	ASSERT_EQ(queue.pop(), 1);
	ASSERT_EQ(queue.size(), 1);
	ASSERT_EQ(queue.front(), 2);
}

// Тест для проверки извлечения элемента из пустой очереди
TEST(TQueueTest, PopEmpty) {
	TQueue<int> queue;
	ASSERT_THROW(queue.pop(), std::out_of_range);
}

// Тест для проверки получения элемента из начала очереди
TEST(TQueueTest, Front) {
	TQueue<int> queue;
	queue.push(1);
	queue.push(2);
	ASSERT_EQ(queue.front(), 1);
	ASSERT_EQ(queue.size(), 2);
}

// Тест для проверки получения элемента из пустой очереди
TEST(TQueueTest, FrontEmpty) {
	TQueue<int> queue;
	ASSERT_THROW(queue.front(), std::out_of_range);
}

// Тест для проверки очистки очереди
TEST(TQueueTest, Clear) {
	TQueue<int> queue;
	queue.push(1);
	queue.push(2);
	queue.clear();
	ASSERT_TRUE(queue.empty());
	ASSERT_EQ(queue.size(), 0);
}

// Тест для проверки оператора вывода
TEST(TQueueTest, OperatorOutput) {
	TQueue<int> queue;
	queue.push(1);
	queue.push(2);
	std::stringstream ss;
	ss << queue;
	ASSERT_EQ(ss.str(), "1 2 ");
}

// Тест для проверки конструктора копирования
TEST(TQueueTest, CopyConstructor) {
	TQueue<int> queue1;
	queue1.push(1);
	queue1.push(2);
	TQueue<int> queue2(queue1);
	ASSERT_EQ(queue2.size(), 2);
	ASSERT_EQ(queue2.front(), 1);
	ASSERT_EQ(queue2.pop(), 1);
	ASSERT_EQ(queue2.pop(), 2);
}

// Тест для проверки оператора присваивания
TEST(TQueueTest, OperatorAssign) {
	TQueue<int> queue1;
	queue1.push(1);
	queue1.push(2);
	TQueue<int> queue2;
	queue2 = queue1;
	ASSERT_EQ(queue2.size(), 2);
	ASSERT_EQ(queue2.front(), 1);
	ASSERT_EQ(queue2.pop(), 1);
	ASSERT_EQ(queue2.pop(), 2);
}

