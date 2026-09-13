// Copyright (c) 2026 LSton3y
// SPDX-License-Identifier: MIT

#include <gtest/gtest.h>
#include "strutil/strutil.hpp"

// ---------- StartsWith ----------

TEST(StartsWith, BasicMatch) {
    EXPECT_TRUE(strutil::StartsWith("hello world", "hello"));
}

TEST(StartsWith, NoMatch) {
    EXPECT_FALSE(strutil::StartsWith("hello world", "world"));
}

TEST(StartsWith, RespectsStartOffset) {
    EXPECT_TRUE(strutil::StartsWith("hello world", "world", 6));
}

TEST(StartsWith, RespectsEndBoundary) {
    EXPECT_FALSE(strutil::StartsWith("hello", "hel", 0, 2));
}

TEST(StartsWith, EmptyValue) {
    EXPECT_TRUE(strutil::StartsWith("hello", ""));
}

TEST(StartsWith, StartGreaterThanEnd) {
    EXPECT_FALSE(strutil::StartsWith("hello", "h", 4, 2));
}

// ---------- EndsWith ----------

TEST(EndsWith, BasicMatch) {
    EXPECT_TRUE(strutil::EndsWith("hello world", "world"));
}

TEST(EndsWith, NoMatch) {
    EXPECT_FALSE(strutil::EndsWith("hello world", "hello"));
}

TEST(EndsWith, RespectsEndBoundary) {
    EXPECT_TRUE(strutil::EndsWith("hello world", "hello", 0, 5));
}

TEST(EndsWith, EmptyValue) {
    EXPECT_TRUE(strutil::EndsWith("hello", ""));
}

TEST(EndsWith, StartGreaterThanEnd) {
    EXPECT_FALSE(strutil::EndsWith("hello", "o", 4, 2));
}

// ---------- RemovePrefix ----------

TEST(RemovePrefix, RemovesMatchingPrefix) {
    EXPECT_EQ(strutil::RemovePrefix("hello world", "hello "), "world");
}

TEST(RemovePrefix, NoMatchReturnsUnchanged) {
    EXPECT_EQ(strutil::RemovePrefix("hello world", "world"), "hello world");
}

TEST(RemovePrefix, EmptyPrefix) {
    EXPECT_EQ(strutil::RemovePrefix("hello", ""), "hello");
}

TEST(RemovePrefix, EntireStringIsPrefix) {
    EXPECT_EQ(strutil::RemovePrefix("hello", "hello"), "");
}

// ---------- RemoveSuffix ----------

TEST(RemoveSuffix, RemovesMatchingSuffix) {
    EXPECT_EQ(strutil::RemoveSuffix("hello world", " world"), "hello");
}

TEST(RemoveSuffix, NoMatchReturnsUnchanged) {
    EXPECT_EQ(strutil::RemoveSuffix("hello world", "hello"), "hello world");
}

TEST(RemoveSuffix, EmptySuffix) {
    EXPECT_EQ(strutil::RemoveSuffix("hello", ""), "hello");
}

TEST(RemoveSuffix, EntireStringIsSuffix) {
    EXPECT_EQ(strutil::RemoveSuffix("hello", "hello"), "");
}