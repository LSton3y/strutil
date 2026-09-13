// Copyright (c) 2026 LSton3y
// SPDX-License-Identifier: MIT

#include <gtest/gtest.h>
#include "strutil/strutil.hpp"

// ---------- Strip ----------

TEST(Strip, RemovesLeadingAndTrailingWhitespace) {
    EXPECT_EQ(strutil::Strip("  hello  "), "hello");
}

TEST(Strip, AllWhitespaceReturnsEmpty) {
    EXPECT_EQ(strutil::Strip("   "), "");
}

TEST(Strip, EmptyString) {
    EXPECT_EQ(strutil::Strip(""), "");
}

TEST(Strip, NoWhitespaceReturnsUnchanged) {
    EXPECT_EQ(strutil::Strip("hello"), "hello");
}

TEST(Strip, CustomCharSet) {
    EXPECT_EQ(strutil::Strip("xxhelloxx", "x"), "hello");
}

TEST(Strip, EmptyValueReturnsUnchanged) {
    EXPECT_EQ(strutil::Strip("  hello  ", ""), "  hello  ");
}

// ---------- LStrip ----------

TEST(LStrip, RemovesOnlyLeading) {
    EXPECT_EQ(strutil::LStrip("  hello  "), "hello  ");
}

TEST(LStrip, AllWhitespaceReturnsEmpty) {
    EXPECT_EQ(strutil::LStrip("   "), "");
}

TEST(LStrip, EmptyValueReturnsUnchanged) {
    EXPECT_EQ(strutil::LStrip("  hello", ""), "  hello");
}

// ---------- RStrip ----------

TEST(RStrip, RemovesOnlyTrailing) {
    EXPECT_EQ(strutil::RStrip("  hello  "), "  hello");
}

TEST(RStrip, AllWhitespaceReturnsEmpty) {
    EXPECT_EQ(strutil::RStrip("   "), "");
}

TEST(RStrip, EmptyValueReturnsUnchanged) {
    EXPECT_EQ(strutil::RStrip("hello  ", ""), "hello  ");
}

// ---------- Trim / TrimStart / TrimEnd (aliases) ----------

TEST(Trim, MatchesStrip) {
    EXPECT_EQ(strutil::Trim("  hello  "), strutil::Strip("  hello  "));
}

TEST(TrimStart, MatchesLStrip) {
    EXPECT_EQ(strutil::TrimStart("  hello  "), strutil::LStrip("  hello  "));
}

TEST(TrimEnd, MatchesRStrip) {
    EXPECT_EQ(strutil::TrimEnd("  hello  "), strutil::RStrip("  hello  "));
}