#include <gtest/gtest.h>
#include "strutil/strutil.hpp"

// ---------- Center ----------

TEST(Center, EvenPadding) {
    EXPECT_EQ(strutil::Center("hi", 6), "  hi  ");
}

TEST(Center, OddPaddingFavorsLeft) {
    EXPECT_EQ(strutil::Center("hi", 5), "  hi ");
}

TEST(Center, LengthShorterThanParamReturnsUnchanged) {
    EXPECT_EQ(strutil::Center("hello", 3), "hello");
}

TEST(Center, LengthEqualsParamLength) {
    EXPECT_EQ(strutil::Center("hi", 2), "hi");
}

TEST(Center, CustomFillChar) {
    EXPECT_EQ(strutil::Center("hi", 6, '*'), "**hi**");
}

// ---------- LJust ----------

TEST(LJust, PadsOnRight) {
    EXPECT_EQ(strutil::LJust("hi", 5), "hi   ");
}

TEST(LJust, LengthShorterThanParamReturnsUnchanged) {
    EXPECT_EQ(strutil::LJust("hello", 3), "hello");
}

TEST(LJust, CustomFillChar) {
    EXPECT_EQ(strutil::LJust("hi", 5, '-'), "hi---");
}

// ---------- RJust ----------

TEST(RJust, PadsOnLeft) {
    EXPECT_EQ(strutil::RJust("hi", 5), "   hi");
}

TEST(RJust, LengthShorterThanParamReturnsUnchanged) {
    EXPECT_EQ(strutil::RJust("hello", 3), "hello");
}

TEST(RJust, CustomFillChar) {
    EXPECT_EQ(strutil::RJust("hi", 5, '-'), "---hi");
}

// ---------- ZFill ----------

TEST(ZFill, PadsWithLeadingZeros) {
    EXPECT_EQ(strutil::ZFill("5", 4), "0005");
}

TEST(ZFill, PreservesNegativeSignPosition) {
    EXPECT_EQ(strutil::ZFill("-5", 4), "-005");
    EXPECT_EQ(strutil::ZFill("-5-5", 5), "-05-5");
}

TEST(ZFill, PreservesPositiveSignPosition) {
    EXPECT_EQ(strutil::ZFill("+5", 4), "+005");
    EXPECT_EQ(strutil::ZFill("+5+5", 5), "+05+5");
}

TEST(ZFill, NoPaddingNeeded) {
    EXPECT_EQ(strutil::ZFill("12345", 4), "12345");
}

TEST(ZFill, EmptyStringWithNonZeroWidth) {
    EXPECT_EQ(strutil::ZFill("", 3), "000");
}

TEST(ZFill, EmptyStringWithZeroWidth) {
    EXPECT_EQ(strutil::ZFill("", 0), "");
}

TEST(ZFill, WidthEqualToLength) {
    EXPECT_EQ(strutil::ZFill("-5", 2), "-5");
}