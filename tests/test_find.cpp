#include <gtest/gtest.h>
#include "strutil/strutil.hpp"

// -- Find --

TEST(Find, BasicMatch) {
    EXPECT_EQ(strutil::Find("hello world", "world"), 6);
}

TEST(Find, NoMatch) {
    EXPECT_EQ(strutil::Find("hello world", "xyz"), std::string::npos);
}

TEST(Find, EmptyValueReturnsStart) {
    EXPECT_EQ(strutil::Find("hello", ""), 0);
    EXPECT_EQ(strutil::Find("hello", "", 3), 3);
}

TEST(Find, EmptyParam) {
    EXPECT_EQ(strutil::Find("", "a"), std::string::npos);
}

TEST(Find, StartBeyondLength) {
    EXPECT_EQ(strutil::Find("hello", "h", 10), std::string::npos);
}

TEST(Find, RespectsEndBoundary) {
    // "hello" - looking for "lo" but cut off before it completes
    EXPECT_EQ(strutil::Find("hello", "lo", 0, 4), std::string::npos);
    EXPECT_EQ(strutil::Find("hello", "lo", 0, 5), 3);
}

TEST(Find, StartEqualsEnd) {
    EXPECT_EQ(strutil::Find("hello", "h", 2, 2), std::string::npos);
}

TEST(Find, MultiCharValue) {
    EXPECT_EQ(strutil::Find("a::b::c", "::"), 1);
}

TEST(Find, WholeStringMatch) {
    EXPECT_EQ(strutil::Find("hello", "hello"), 0);
}

// -- RFind --

TEST(RFind, BasicLastMatch) {
    EXPECT_EQ(strutil::RFind("a::b::c", "::"), 4);
}

TEST(RFind, NoMatch) {
    EXPECT_EQ(strutil::RFind("hello world", "xyz"), std::string::npos);
}

TEST(RFind, SingleOccurrence) {
    EXPECT_EQ(strutil::RFind("hello world", "world"), 6);
}

TEST(RFind, EmptyParam) {
    EXPECT_EQ(strutil::RFind("", "a"), std::string::npos);
}

TEST(RFind, EmptyValueReturnsStart) {
    EXPECT_EQ(strutil::RFind("hello", ""), 5);
}

TEST(RFind, RespectsStartBoundary) {
    // last "l" in "hello" is at index 3, but start=4 should exclude it
    EXPECT_EQ(strutil::RFind("hello", "l", 4), std::string::npos);
    EXPECT_EQ(strutil::RFind("hello", "l", 3), 3);
}

TEST(RFind, RespectsEndBoundary) {
    // restrict search so the last "l" (at 3) is out of range
    EXPECT_EQ(strutil::RFind("hello", "l", 0, 3), 2);
}

TEST(RFind, ValueLongerThanParam) {
    EXPECT_EQ(strutil::RFind("hi", "hello"), std::string::npos);
}

// -- Index / RIndex --

TEST(Index, ReturnsPositionOnMatch) {
    EXPECT_EQ(strutil::Index("hello world", "world"), 6);
}

TEST(Index, ThrowsOnNoMatch) {
    EXPECT_THROW((void)strutil::Index("hello", "xyz"), std::invalid_argument);
}

TEST(RIndex, ReturnsLastPositionOnMatch) {
    EXPECT_EQ(strutil::RIndex("a::b::c", "::"), 4);
}

TEST(RIndex, ThrowsOnNoMatch) {
    EXPECT_THROW((void)strutil::RIndex("hello", "xyz"), std::invalid_argument);
}

// -- Contains --

TEST(Contains, ReturnsTrueOnMatch) {
    EXPECT_TRUE(strutil::Contains("hello world", "world"));
}

TEST(Contains, ReturnsFalseOnNoMatch) {
    EXPECT_FALSE(strutil::Contains("hello world", "xyz"));
}

TEST(Contains, EmptyValueIsTrue) {
    EXPECT_TRUE(strutil::Contains("hello", ""));
}

TEST(Contains, RespectsRange) {
    EXPECT_FALSE(strutil::Contains("hello", "lo", 0, 4));
    EXPECT_TRUE(strutil::Contains("hello", "lo", 0, 5));
}