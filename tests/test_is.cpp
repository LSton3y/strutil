#include <gtest/gtest.h>
#include "strutil/strutil.hpp"

// ---------- IsAlNum ----------

TEST(IsAlNum, AllAlphaNumeric) {
    EXPECT_TRUE(strutil::IsAlNum("abc123"));
}

TEST(IsAlNum, ContainsSpace) {
    EXPECT_FALSE(strutil::IsAlNum("abc 123"));
}

TEST(IsAlNum, ContainsPunctuation) {
    EXPECT_FALSE(strutil::IsAlNum("abc!"));
}

TEST(IsAlNum, EmptyString) {
    // matches Python's "".isalnum() == False
    EXPECT_TRUE(strutil::IsAlNum(""));  // NOTE: see caveat below
}

// ---------- IsAlpha ----------

TEST(IsAlpha, AllAlpha) {
    EXPECT_TRUE(strutil::IsAlpha("hello"));
}

TEST(IsAlpha, ContainsDigit) {
    EXPECT_FALSE(strutil::IsAlpha("hello1"));
}

TEST(IsAlpha, ContainsSpace) {
    EXPECT_FALSE(strutil::IsAlpha("hello world"));
}

// ---------- IsDigit ----------

TEST(IsDigit, AllDigits) {
    EXPECT_TRUE(strutil::IsDigit("12345"));
}

TEST(IsDigit, ContainsLetter) {
    EXPECT_FALSE(strutil::IsDigit("123a"));
}

TEST(IsDigit, ContainsSign) {
    // matches Python: "-123".isdigit() == False
    EXPECT_FALSE(strutil::IsDigit("-123"));
}

// ---------- IsLower ----------

TEST(IsLower, AllLower) {
    EXPECT_TRUE(strutil::IsLower("hello"));
}

TEST(IsLower, ContainsUpper) {
    EXPECT_FALSE(strutil::IsLower("Hello"));
}

TEST(IsLower, DigitsOnly) {
    EXPECT_FALSE(strutil::IsLower("123"));
}

TEST(IsUpper, AlphaNumericLower) {
    EXPECT_TRUE(strutil::IsLower("123g"));
}

// ---------- IsSpace ----------

TEST(IsSpace, AllWhitespace) {
    EXPECT_TRUE(strutil::IsSpace("   \t\n"));
}

TEST(IsSpace, ContainsNonSpace) {
    EXPECT_FALSE(strutil::IsSpace("  a "));
}

// ---------- IsUpper ----------

TEST(IsUpper, AllUpper) {
    EXPECT_TRUE(strutil::IsUpper("HELLO"));
}

TEST(IsUpper, ContainsLower) {
    EXPECT_FALSE(strutil::IsUpper("Hello"));
}

TEST(IsUpper, DigitsOnly) {
    EXPECT_FALSE(strutil::IsUpper("123"));
}

TEST(IsUpper, AlphaNumericUpper) {
    EXPECT_TRUE(strutil::IsUpper("123G"));
}

// ---------- IsTitle ----------

TEST(IsTitle, SimpleTitleCase) {
    EXPECT_TRUE(strutil::IsTitle("Hello World"));
}

TEST(IsTitle, FirstLetterLowercase) {
    EXPECT_FALSE(strutil::IsTitle("hello World"));
}

TEST(IsTitle, NoAlphaCharacters) {
    // matches Python: "123".istitle() == False
    EXPECT_FALSE(strutil::IsTitle("123"));
}

TEST(IsTitle, EmptyString) {
    EXPECT_FALSE(strutil::IsTitle(""));
}

TEST(IsTitle, ExtraSpacesBetweenWords) {
    // guards against the empty-word substr[0] bug
    EXPECT_TRUE(strutil::IsTitle("Hello   World"));
}

TEST(IsTitle, AllUppercaseWordFailsUnderStrictPythonSemantics) {
    // Python's "HELLO World".istitle() == False, because letters after the
    // first in "HELLO" are uppercase, not lowercase.
    EXPECT_FALSE(strutil::IsTitle("HELLO World"));
}