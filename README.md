# strutil

Header-only C++20 string utility library modeled on Python's `str` methods.

## Usage
```cpp
#include <strutil/strutil.hpp>
#include <iostream>

int main() {
    std::string s = "  Hello World  ";
    std::cout << strutil::Strip(s) << "\n"; // -> "Hello World"
    std::cout << strutil::Lower(strutil::Strip(s)) << "\n"; // -> "hello world"
}
```


## Installation
`strutil` is a single header with no dependencies beyond the C++20 standard library.

### Option 1: Copy the header

Copy `include/strutil/strutil.hpp` into your project and include it:

```cpp
#include "strutil.hpp"
```

### Option 2: CMake FetchContent

```cmake
include(FetchContent)

FetchContent_Declare(
    strutil
    GIT_REPOSITORY https://github.com/<you>/strutil.git
    GIT_TAG main
)

FetchContent_MakeAvailable(strutil)

target_link_libraries(your_target PRIVATE strutil)
```

Then:

```cpp
#include <strutil/strutil.hpp>
```

### Requirements
- C++20 (uses `std::string_view`, `starts_with`/`ends_with`, `if constexpr`)


## Building and running tests

Tests use GoogleTest, fetched automatically via CMake's `FetchContent` — no manual GTest install needed.

### Requirements
- CMake 3.14+
- A C++20 compiler (MSVC 2019 16.11+, GCC 10+, Clang 12+)

### Build

```bash
cmake -S . -B build
cmake --build build
```

### Run tests

```bash
cd build
ctest --output-on-failure
```

Or run the test binary directly:

```bash
./build/tests/strutil_tests        # Linux/macOS
.\build\tests\Debug\strutil_tests.exe   # Windows (MSVC multi-config)
```

## API Reference

### Case
- `Capitalize(param)` — Capitalizes the first character of a string
- `Lower(param)` / `Upper(param)` — Converts a string to lowercase / uppercase
- `SwapCase(param)` - Swaps the case of each character in a string
- `Title(param)` - Capitalizes the first character of each word in a string
- `EqualsIgnoreCase(param)` - Checks if two strings match, regardless of case

```cpp
strutil::Capitalize("helLO"); // -> "Hello"
strutil::Lower("HeLLo"); // -> "hello"
strutil::Upper("hELlO"); // -> "HELLO"
strutil::SwapCase("HellO"); // -> "hELLo"
strutil::Title("heLLo, worLD"); // -> "Hello World"
strutil::EqualsIgnoreCase("HELLO", "hello"); // -> true
```

### Align
- `Center(param, length, character)` - Centers a string by the specified length
- `LJust(param, length, character)` - Justifies a string to the left by the specified length
- `RJust(param, length, character)` - Justifies a string to the right by the specified length
- `ZFill(param, nZero)` - Fills a string with a specified number of "0"s at the beginning

```cpp
strutil::Center("hello", 7); // -> " hello "
strutil::LJust("hello", 7); // -> "hello  "
strutil::RJust("hello", 7); // -> "  hello"
strutil::ZFill("1010", 8); // -> "00001010"
```

### Prefix/Suffix
- `StartsWith(param, value, start, end)` - Returns whether a string starts with a specified value
- `EndsWith(param, value, start, end)` - Returns whether a string ends with a specified value
- `RemovePrefix(param, value)` - Removes the prefix from a string
- `RemoveSuffix(param, value)` - Removes the suffix from a string

```cpp
strutil::StartsWith("hello world", "hello"); // -> true
strutil::EndsWith("hello world", "world"); // -> true
strutil::RemovePrefix("hello", "he"); // -> "llo"
strutil::RemoveSuffix("hello", "lo"); // -> "hel
```

### Find
- `Find(param, value, start, end)` - Returns the index of the first occurence of a value (returns npos if not found)
- `RFind(param, value, start, end)` - Returns the index of the last occurence of a value (returns npos if not found)
- `Index(param, value, start, end)` - Returns the index of the first occurence of a value (throws an exception if not found)
- `RIndex(param, value, start, end)` - Returns the index of the last occurence of a value (throws an exception if not found)
- `Contains(param, value, start, end)` - Returns whether a string contains a value

```cpp
strutil::Find("foo bar foo bar", "bar"); // -> 4
strutil::RFind("foo bar foo bar", "bar"); // -> 12
strutil::Index("hello", "foo"); // -> Throws error: Value not found.
strutil::RIndex("foo bar foo", "foo"); // -> 8
strutil::Contains("hello", "ell"); // -> true
```

### Is
- `IsAlNum(param)` - Returns whether all the characters in a string are alphanumeric
- `IsAlpha(param)` - Returns whether all the characters in a string are in the alphabet
- `IsDigit(param)` - Returns whether all the characters in a string are digits
- `IsLower(param)` - Returns whether all the characters in a string are lowercase
- `IsSpace(param)` - Returns whether all the characters in a string are whitespaces
- `IsTitle(param)` - Returns whether a string follows the rules of a title
- `IsUpper(param)` - Returns whether all the characters in a string are uppercase

```cpp
strutil::IsAlNum("123abc"); // -> true
strutil::IsAlpha("abc"); // -> true
strutil::IsDigit("123"); // -> true
strutil::IsLower("hello"); // -> true
strutil::IsSpace(" "); // -> true
strutil::IsTitle("Hello World"); // -> true
strutil::IsUpper("HELLO"); // -> true
```

### Partition
- `Partition(param, value)` - Creates a vector where the string is parted into three parts
- `RPartition(param, value)` - Creates a vector where the string is parted into three parts (finds from right)

```cpp
strutil::Partition("hello=world"); // -> {"hello", "=", "world"}
strutil::RPartition("a=b=c"); // -> {"a=b", "=", "c"}
```

### Split
- `Split(param, separator, count)` - Splits the string at a specified separator
- `RSplit(param, separator, count)` - Splits the string at a specified separator (finds from right)

```cpp
strutil::Split("a::b::c", "::"); // -> {"a", "b", "c"}
strutil::RSplit("a,b,c,d", ",", 2); // -> {"a,b", "c", "d"}
```

### Strip
- `Strip(param, value)` - Trims the specified value from the start and end of a string
- `LStrip(param, value)` - Trims the specified value from the start of a string
- `RStrip(param, value)` - Trims the specified value from the end of a string

```cpp
strutil::Strip("  hello  "); // -> "hello"
strutil::LStrip("  hello  "); // -> "hello  "
strutil::RStrip("  hello  "); // -> "  hello"
```

### Other
- `Count(param, value, start, end)` - Returns the number of occurences of a value in a string
- `Format(param, ...)` - Formats values into a string
- `Join(params, separator)` - Joins a vector of strings together with a separator
- `Replace(param, value1, value2, count)` - Replaces all occurences of a value with another value
- `Repeat(param, count)` - Returns a string repeated a specified amount of times
- `Reverse(param)` - Returns a reversed string

```cpp
strutil::Count("foo bar bar", "bar"); // -> 2
strutil::Format("{} + {} = {}", 1, true, 3.0); // -> "1 + true = 3.0"
strutil::Join({"hello", "world"}, " "); // -> "hello world"
strutil::Replace("foo bar bar", "bar", "foo"); // -> "foo foo foo"
strutil::Repeat("hello", 3); // -> "hellohellohello"
strutil::Reverse("hello"); // -> "olleh"
```


## Design Notes

### IsLower / IsUpper
IsLower() and IsUpper() only checks the characters that are in the alphabet.

```cpp
// No letters
strutil::IsLower("123"); // -> false
// Letter included
strutil::IsLower("a123"); // -> true

// No letters
strutil::IsUpper("123"); // -> false
// Letter included
strutil::IsUpper("A123"); // -> true
```

### IsTitle
IsTitle() checks that the first letter of each word is uppercase and all leading letters are lowercase.

```cpp
// Follows title rule
strutil::IsTitle("Hello World") // -> true

// Doesn't follow rule (leading letters are uppercase)
strutil::IsTitle("Hello WoRld") // -> false
```

### ZFill
ZFill() handles signs by keeping them at the front and including them in the total string length.

```cpp
strutil::ZFill("+50", 4); // -> "+050"
strutil::ZFill("-50", 4); // -> "-050"
```