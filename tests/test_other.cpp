#include <gtest/gtest.h>
#include "strutil/strutil.hpp"

// ---------- Count ----------

TEST(Count, BasicCount) {
    EXPECT_EQ(strutil::Count("abcabcabc", "abc"), 3);
}

TEST(Count, NoMatches) {
    EXPECT_EQ(strutil::Count("hello", "xyz"), 0);
}

TEST(Count, EmptyParamOrValue) {
    EXPECT_EQ(strutil::Count("", "a"), 0);
    EXPECT_EQ(strutil::Count("hello", ""), 0);
}

TEST(Count, OverlappingMatchesNotDoubleCounted) {
    // non-overlapping semantics, like std::string::find advancing by match length
    EXPECT_EQ(strutil::Count("aaaa", "aa"), 2);
}

TEST(Count, RespectsRange) {
    EXPECT_EQ(strutil::Count("abcabcabc", "abc", 0, 6), 2);
}

// ---------- Join ----------

TEST(Join, BasicJoin) {
    EXPECT_EQ(strutil::Join({"a", "b", "c"}, ", "), "a, b, c");
}

TEST(Join, EmptyVectorReturnsEmptyString) {
    EXPECT_EQ(strutil::Join({}, ", "), "");
}

TEST(Join, SingleElement) {
    EXPECT_EQ(strutil::Join({"a"}, ", "), "a");
}

TEST(Join, EmptySeparator) {
    EXPECT_EQ(strutil::Join({"a", "b", "c"}, ""), "abc");
}

// ---------- Replace ----------

TEST(Replace, ReplacesAllOccurrencesByDefault) {
    EXPECT_EQ(strutil::Replace("aaa", "a", "b"), "bbb");
}

TEST(Replace, RespectsCountLimit) {
    EXPECT_EQ(strutil::Replace("aaa", "a", "b", 2), "bba");
}

TEST(Replace, EmptyValue1ReturnsUnchanged) {
    EXPECT_EQ(strutil::Replace("hello", "", "x"), "hello");
}

TEST(Replace, NoMatchReturnsUnchanged) {
    EXPECT_EQ(strutil::Replace("hello", "xyz", "abc"), "hello");
}

TEST(Replace, ReplacementLongerThanOriginal) {
    EXPECT_EQ(strutil::Replace("a-a-a", "-", "---"), "a---a---a");
}

// ---------- Repeat ----------

TEST(Repeat, BasicRepeat) {
    EXPECT_EQ(strutil::Repeat("ab", 3), "ababab");
}

TEST(Repeat, ZeroCountReturnsEmpty) {
    EXPECT_EQ(strutil::Repeat("ab", 0), "");
}

TEST(Repeat, EmptyStringRepeated) {
    EXPECT_EQ(strutil::Repeat("", 5), "");
}

// ---------- Reverse ----------

TEST(Reverse, BasicReverse) {
    EXPECT_EQ(strutil::Reverse("hello"), "olleh");
}

TEST(Reverse, EmptyString) {
    EXPECT_EQ(strutil::Reverse(""), "");
}

TEST(Reverse, SingleChar) {
    EXPECT_EQ(strutil::Reverse("a"), "a");
}

// ---------- ToString ----------

TEST(ToString, Integer) {
    EXPECT_EQ(strutil::ToString(42), "42");
}

TEST(ToString, Bool) {
    EXPECT_EQ(strutil::ToString(true), "true");
    EXPECT_EQ(strutil::ToString(false), "false");
}

TEST(ToString, Char) {
    EXPECT_EQ(strutil::ToString('x'), "x");
}

TEST(ToString, StringLiteral) {
    EXPECT_EQ(strutil::ToString("hello"), "hello");
}

// ---------- Format ----------

TEST(Format, BasicSubstitution) {
    EXPECT_EQ(strutil::Format("{} + {} = {}", 1, 2, 3), "1 + 2 = 3");
}

TEST(Format, NoPlaceholders) {
    EXPECT_EQ(strutil::Format("hello"), "hello");
}

TEST(Format, MixedTypes) {
    EXPECT_EQ(strutil::Format("{} is {}", "flag", true), "flag is true");
}