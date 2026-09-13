// Copyright (c) 2026 LSton3y
// SPDX-License-Identifier: MIT

#include <gtest/gtest.h>
#include "strutil/strutil.hpp"

// ---------- Capitalize ----------

TEST(Capitalize, LowercasesRestAndUppersFirst) {
    EXPECT_EQ(strutil::Capitalize("hELLO"), "Hello");
}

TEST(Capitalize, EmptyString) {
    EXPECT_EQ(strutil::Capitalize(""), "");
}

TEST(Capitalize, SingleChar) {
    EXPECT_EQ(strutil::Capitalize("a"), "A");
}

TEST(Capitalize, AlreadyCapitalized) {
    EXPECT_EQ(strutil::Capitalize("Hello"), "Hello");
}

// ---------- Lower / Upper ----------

TEST(Lower, MixedCase) {
    EXPECT_EQ(strutil::Lower("HeLLo"), "hello");
}

TEST(Lower, EmptyString) {
    EXPECT_EQ(strutil::Lower(""), "");
}

TEST(Upper, MixedCase) {
    EXPECT_EQ(strutil::Upper("HeLLo"), "HELLO");
}

TEST(Upper, EmptyString) {
    EXPECT_EQ(strutil::Upper(""), "");
}

// ---------- SwapCase ----------

TEST(SwapCase, MixedCase) {
    EXPECT_EQ(strutil::SwapCase("Hello World"), "hELLO wORLD");
}

TEST(SwapCase, EmptyString) {
    EXPECT_EQ(strutil::SwapCase(""), "");
}

TEST(SwapCase, DigitsAndSymbolsUnaffected) {
    EXPECT_EQ(strutil::SwapCase("abc123!"), "ABC123!");
}

// ---------- Title ----------

TEST(Title, BasicSentence) {
    EXPECT_EQ(strutil::Title("hello world"), "Hello World");
}

TEST(Title, EmptyString) {
    EXPECT_EQ(strutil::Title(""), "");
}

TEST(Title, AlreadyTitleCase) {
    EXPECT_EQ(strutil::Title("Hello World"), "Hello World");
}

TEST(Title, SingleWord) {
    EXPECT_EQ(strutil::Title("hello"), "Hello");
}

// ---------- EqualsIgnoreCase ----------

TEST(EqualsIgnoreCase, DifferentCaseSameContent) {
    EXPECT_TRUE(strutil::EqualsIgnoreCase("Hello", "hello"));
}

TEST(EqualsIgnoreCase, DifferentContent) {
    EXPECT_FALSE(strutil::EqualsIgnoreCase("Hello", "World"));
}

TEST(EqualsIgnoreCase, DifferentLengths) {
    EXPECT_FALSE(strutil::EqualsIgnoreCase("Hello", "Hell"));
}

TEST(EqualsIgnoreCase, BothEmpty) {
    EXPECT_TRUE(strutil::EqualsIgnoreCase("", ""));
}