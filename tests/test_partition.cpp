// Copyright (c) 2026 LSton3y
// SPDX-License-Identifier: MIT

#include <gtest/gtest.h>
#include "strutil/strutil.hpp"

// ---------- Partition ----------

TEST(Partition, BasicSplit) {
    auto result = strutil::Partition("hello=world", "=");
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "hello");
    EXPECT_EQ(result[1], "=");
    EXPECT_EQ(result[2], "world");
}

TEST(Partition, ValueNotFound) {
    auto result = strutil::Partition("hello", "=");
    ASSERT_EQ(result.size(), 3);
    EXPECT_EQ(result[0], "hello");
    EXPECT_EQ(result[1], "");
    EXPECT_EQ(result[2], "");
}

TEST(Partition, ValueLongerThanParam) {
    auto result = strutil::Partition("hi", "hello");
    EXPECT_EQ(result[0], "hi");
    EXPECT_EQ(result[1], "");
    EXPECT_EQ(result[2], "");
}

TEST(Partition, MultipleOccurrencesUsesFirst) {
    auto result = strutil::Partition("a=b=c", "=");
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "=");
    EXPECT_EQ(result[2], "b=c");
}

TEST(Partition, MultiCharValue) {
    auto result = strutil::Partition("a::b", "::");
    EXPECT_EQ(result[0], "a");
    EXPECT_EQ(result[1], "::");
    EXPECT_EQ(result[2], "b");
}

// ---------- RPartition ----------

TEST(RPartition, MultipleOccurrencesUsesLast) {
    auto result = strutil::RPartition("a=b=c", "=");
    EXPECT_EQ(result[0], "a=b");
    EXPECT_EQ(result[1], "=");
    EXPECT_EQ(result[2], "c");
}

TEST(RPartition, ValueNotFound) {
    auto result = strutil::RPartition("hello", "=");
    EXPECT_EQ(result[0], "");
    EXPECT_EQ(result[1], "");
    EXPECT_EQ(result[2], "hello");
}

TEST(RPartition, ValueLongerThanParam) {
    auto result = strutil::RPartition("hi", "hello");
    EXPECT_EQ(result[0], "");
    EXPECT_EQ(result[1], "");
    EXPECT_EQ(result[2], "hi");
}

TEST(RPartition, MultiCharValue) {
    auto result = strutil::RPartition("a::b::c", "::");
    EXPECT_EQ(result[0], "a::b");
    EXPECT_EQ(result[1], "::");
    EXPECT_EQ(result[2], "c");
}