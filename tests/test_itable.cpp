#include <gtest.h>
#include "itable.h"

TEST(TableTest, InsertWithoutKey) {
    Table<int, std::string> table;
    table.insert("One");
    table.insert("Two");

    EXPECT_NO_THROW(table.insert("Three"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
