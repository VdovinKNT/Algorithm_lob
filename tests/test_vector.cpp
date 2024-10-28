#include <gtest.h>
#include "vector.h"

// Тест конструктора с размером и значением по умолчанию
TEST(TVectorTest, ConstructorWithSizeAndDefaultValue) {
    TVector<int> vec(3, 1);
    ASSERT_EQ(vec.size(), 3);
    ASSERT_EQ(vec[0], 1);
    ASSERT_EQ(vec[1], 1);
    ASSERT_EQ(vec[2], 1);
}

// Тест доступа к элементам
TEST(TVectorTest, AccessElements) {
    int arr[] = { 1, 2, 3 };
    TVector<int> vec(3); // Изменен конструктор на корректный
    for (size_t i = 0; i < 3; ++i) {
        vec[i] = arr[i]; // Заполняем вектор значениями
    }
    ASSERT_EQ(vec[0], 1);
    ASSERT_EQ(vec[1], 2);
    ASSERT_EQ(vec[2], 3);
}

// Тест оператора сложения
TEST(TVectorTest, AdditionOperator) {
    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 4, 5, 6 };
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (size_t i = 0; i < 3; ++i) {
        vec1[i] = arr1[i]; // Заполняем первый вектор
        vec2[i] = arr2[i]; // Заполняем второй вектор
    }
    TVector<int> result = vec1 + vec2;
    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], 5);
    ASSERT_EQ(result[1], 7);
    ASSERT_EQ(result[2], 9);
}

// Тест оператора вычитания
TEST(TVectorTest, SubtractionOperator) {
    int arr1[] = { 4, 5, 6 };
    int arr2[] = { 1, 2, 3 };
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (size_t i = 0; i < 3; ++i) {
        vec1[i] = arr1[i]; // Заполняем первый вектор
        vec2[i] = arr2[i]; // Заполняем второй вектор
    }
    TVector<int> result = vec1 - vec2;
    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], 3);
    ASSERT_EQ(result[1], 3);
    ASSERT_EQ(result[2], 3);
}

// Тест умножения на скаляр
TEST(TVectorTest, ScalarMultiplication) {
    int arr[] = { 1, 2, 3 };
    TVector<int> vec(3);
    for (size_t i = 0; i < 3; ++i) {
        vec[i] = arr[i]; // Заполняем вектор значениями
    }
    TVector<int> result = vec * 2;
    ASSERT_EQ(result.size(), 3);
    ASSERT_EQ(result[0], 2);
    ASSERT_EQ(result[1], 4);
    ASSERT_EQ(result[2], 6);
}



// Тест оператора сравнения на равенство
TEST(TVectorTest, EqualityOperator) {
    int arr[] = { 1, 2, 3 };
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (size_t i = 0; i < 3; ++i) {
        vec1[i] = arr[i]; // Заполняем первый вектор
        vec2[i] = arr[i]; // Заполняем второй вектор
    }
    ASSERT_TRUE(vec1 == vec2);
}

// Тест оператора сравнения на неравенство
TEST(TVectorTest, InequalityOperator) {
    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 4, 5, 6 };
    TVector<int> vec1(3);
    TVector<int> vec2(3);
    for (size_t i = 0; i < 3; ++i) {
        vec1[i] = arr1[i]; // Заполняем первый вектор
        vec2[i] = arr2[i]; // Заполняем второй вектор
    }
    ASSERT_TRUE(vec1 != vec2);
}

// Запуск всех тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
