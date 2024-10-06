// Copyright 2024 <Artem Vdovin>

#include "gtest/gtest.h"
#include "vector.h"

// ѕроверка конструктора
TEST(TVectorTest, Constructor) {
    TVector<int> v1;
    ASSERT_EQ(v1.size(), 0);

    TVector<int> v2(5);
    ASSERT_EQ(v2.size(), 5);
}

// ѕроверка оператора доступа
TEST(TVectorTest, AccessOperator) {
    TVector<int> v(5);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    ASSERT_EQ(v[0], 1);
    ASSERT_EQ(v[1], 2);
    ASSERT_EQ(v[2], 3);
    ASSERT_EQ(v[3], 4);
    ASSERT_EQ(v[4], 5);
}

// ѕроверка выхода за пределы диапазона
TEST(TVectorTest, AccessOperatorOutOfRange) {
    TVector<int> v(5);
    ASSERT_THROW(v[5], std::out_of_range);
}

// ѕроверка сложени€
TEST(TVectorTest, Addition) {
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(3);
    v2[0] = 4;
    v2[1] = 5;
    v2[2] = 6;
    TVector<int> v3 = v1 + v2;
    ASSERT_EQ(v3[0], 5);
    ASSERT_EQ(v3[1], 7);
    ASSERT_EQ(v3[2], 9);
}

// ѕроверка сложени€ векторов с разными размерами
TEST(TVectorTest, AdditionDifferentSizes) {
    TVector<int> v1(3);
    TVector<int> v2(4);
    ASSERT_THROW(v1 + v2, std::logic_error);
}

// ѕроверка вычитани€
TEST(TVectorTest, Subtraction) {
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(3);
    v2[0] = 4;
    v2[1] = 5;
    v2[2] = 6;
    TVector<int> v3 = v1 - v2;
    ASSERT_EQ(v3[0], -3);
    ASSERT_EQ(v3[1], -3);
    ASSERT_EQ(v3[2], -3);
}

// ѕроверка вычитани€ векторов с разными размерами
TEST(TVectorTest, SubtractionDifferentSizes) {
    TVector<int> v1(3);
    TVector<int> v2(4);
    ASSERT_THROW(v1 - v2, std::logic_error);
}

// ѕроверка умножени€ на скал€р
TEST(TVectorTest, MultiplicationScalar) {
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2 = v1 * 2;
    ASSERT_EQ(v2[0], 2);
    ASSERT_EQ(v2[1], 4);
    ASSERT_EQ(v2[2], 6);
}

// ѕроверка сложени€ с присваиванием
TEST(TVectorTest, AdditionAssign) {
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(3);
    v2[0] = 4;
    v2[1] = 5;
    v2[2] = 6;
    v1 += v2;
    ASSERT_EQ(v1[0], 5);
    ASSERT_EQ(v1[1], 7);
    ASSERT_EQ(v1[2], 9);
}

// ѕроверка сложени€ с присваиванием дл€ разных размеров
TEST(TVectorTest, AdditionAssignDifferentSizes) {
    TVector<int> v1(3);
    TVector<int> v2(4);
    ASSERT_THROW(v1 += v2, std::logic_error);
}

// ѕроверка вычитани€ с присваиванием
TEST(TVectorTest, SubtractionAssign) {
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(3);
    v2[0] = 4;
    v2[1] = 5;
    v2[2] = 6;
    v1 -= v2;
    ASSERT_EQ(v1[0], -3);
    ASSERT_EQ(v1[1], -3);
    ASSERT_EQ(v1[2], -3);
}

// ѕроверка вычитани€ с присваиванием дл€ разных размеров
TEST(TVectorTest, SubtractionAssignDifferentSizes) {
    TVector<int> v1(3);
    TVector<int> v2(4);
    ASSERT_THROW(v1 -= v2, std::logic_error);
}

// ѕроверка умножени€ на скал€р с присваиванием
TEST(TVectorTest, MultiplicationAssignScalar) {
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    v1 *= 2;
    ASSERT_EQ(v1[0], 2);
    ASSERT_EQ(v1[1], 4);
    ASSERT_EQ(v1[2], 6);
}

// ѕроверка сравнени€ на равенство
TEST(TVectorTest, Equality) {
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(3);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;
    ASSERT_TRUE(v1 == v2);
}

// ѕроверка сравнени€ на неравенство
TEST(TVectorTest, Inequality) {
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(3);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 4;
    ASSERT_FALSE(v1 == v2);
}

// ѕроверка получени€ размера
TEST(TVectorTest, Size) {
    TVector<int> v1(3);
    ASSERT_EQ(v1.size(), 3);
}

// ѕроверка скал€рного произведени€
TEST(TVectorTest, DotProduct) {
    TVector<int> v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;
    TVector<int> v2(3);
    v2[0] = 4;
    v2[1] = 5;
    v2[2] = 6;
    ASSERT_EQ(v1.dotProduct(v2), 32);
}

// ѕроверка скал€рного произведени€ дл€ разных размеров
TEST(TVectorTest, DotProductDifferentSizes) {
    TVector<int> v1(3);
    TVector<int> v2(4);
    ASSERT_THROW(v1.dotProduct(v2), std::logic_error);
}
