#include <gtest/gtest.h>
#include "strutil/strutil.hpp"

// ---------- Split ----------

TEST(Split, BasicSpaceSplit) {
    auto result = strutil::Split("hello world foo");
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "hello");
    EXPECT_EQ(result[1], "world");
    EXPECT_EQ(result[2], "foo");
}

TEST(Split, MultiCharSeparator) {
    auto result = strutil::Split("a::b::c", "::");
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "b");
    EXPECT_EQ(result[2], "c");
}

TEST(Split, EmptyString) {
    auto result = strutil::Split("", ",");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "");
}

TEST(Split, EmptySeparatorReturnsEmptyVector) {
    auto result = strutil::Split("hello", "");
    EXPECT_TRUE(result.empty());
}

TEST(Split, EmptySeparatorWithEmptyParam) {
    auto result = strutil::Split("", "");
    EXPECT_TRUE(result.empty());
}

TEST(Split, SeparatorNotFoundReturnsWholeString) {
    auto result = strutil::Split("hello", ",");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "hello");
}

TEST(Split, CountLimitsSplits) {
    auto result = strutil::Split("a,b,c,d", ",", 2);
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "b");
    EXPECT_EQ(result[2], "c,d");
}

TEST(Split, CountZeroReturnsWholeString) {
    auto result = strutil::Split("a,b,c", ",", 0);
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "a,b,c");
}

TEST(Split, ConsecutiveSeparatorsProduceEmptyStrings) {
    auto result = strutil::Split("a,,b", ",");
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "");
    EXPECT_EQ(result[2], "b");
}

// ---------- RSplit ----------

TEST(RSplit, BasicSpaceSplit) {
    auto result = strutil::RSplit("hello world foo");
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "hello");
    EXPECT_EQ(result[1], "world");
    EXPECT_EQ(result[2], "foo");
}

TEST(RSplit, MultiCharSeparator) {
    auto result = strutil::RSplit("a::b::c", "::");
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "b");
    EXPECT_EQ(result[2], "c");
}

TEST(RSplit, CountLimitsFromTheRight) {
    auto result = strutil::RSplit("a,b,c,d", ",", 2);
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "a,b");
    EXPECT_EQ(result[1], "c");
    EXPECT_EQ(result[2], "d");
}

TEST(RSplit, CountZeroReturnsWholeString) {
    auto result = strutil::RSplit("a,b,c", ",", 0);
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "a,b,c");
}

TEST(RSplit, SeparatorNotFoundReturnsWholeString) {
    auto result = strutil::RSplit("hello", ",");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "hello");
}

TEST(RSplit, EmptySeparatorReturnsEmptyVector) {
    auto result = strutil::RSplit("hello", "");
    EXPECT_TRUE(result.empty());
}

TEST(RSplit, EmptyString) {
    auto result = strutil::RSplit("", ",");
    ASSERT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "");
}