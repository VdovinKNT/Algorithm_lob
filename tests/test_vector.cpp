#include "gtest/gtest.h"
#include "vector.h"

TEST(TVectorTest, Constructor) {
    TVector<int> v1;
    ASSERT_EQ(v1.size(), 0);

    TVector<int> v2(5);
    ASSERT_EQ(v2.size(), 5);
}

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

TEST(TVectorTest, AccessOperatorOutOfRange) {
    TVector<int> v(5);
    ASSERT_THROW(v[5], std::out_of_range);
}

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

TEST(TVectorTest, AdditionDifferentSizes) {
    TVector<int> v1(3);
    TVector<int> v2(4);
    ASSERT_THROW(v1 + v2, std::logic_error);
}

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

TEST(TVectorTest, SubtractionDifferentSizes) {
    TVector<int> v1(3);
    TVector<int> v2(4);
    ASSERT_THROW(v1 - v2, std::logic_error);
}

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

TEST(TVectorTest, AdditionAssignDifferentSizes) {
    TVector<int> v1(3);
    TVector<int> v2(4);
    ASSERT_THROW(v1 += v2, std::logic_error);
}

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

TEST(TVectorTest, SubtractionAssignDifferentSizes) {
    TVector<int> v1(3);
    TVector<int> v2(4);
    ASSERT_THROW(v1 -= v2, std::logic_error);
}

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

TEST(TVectorTest, Size) {
    TVector<int> v1(3);
    ASSERT_EQ(v1.size(), 3);
}

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

TEST(TVectorTest, DotProductDifferentSizes) {
    TVector<int> v1(3);
    TVector<int> v2(4);
    ASSERT_THROW(v1.dotProduct(v2), std::logic_error);
}

