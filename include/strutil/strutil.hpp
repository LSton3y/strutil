#pragma once

#include <string>
#include <string_view>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cctype>
#include <type_traits>


namespace strutil {

/*
    Forward declarations
*/
// Case methods
std::string Capitalize(std::string param);
std::string Lower(std::string param);
std::string SwapCase(std::string param);
std::string Title(std::string_view param);
std::string Upper(std::string param);
bool EqualsIgnoreCase(std::string_view param1, std::string_view param2);

// Align methods
std::string Center(std::string_view param, std::size_t length, char character = ' ');
std::string LJust(std::string_view param, std::size_t length, char character = ' ');
std::string RJust(std::string_view param, std::size_t length, char character = ' ');
std::string ZFill(std::string_view param, std::size_t nZero);

// Prefix and suffix methods
bool StartsWith(
    std::string_view param, 
    std::string_view value, 
    std::size_t start = 0, 
    std::size_t end = std::string::npos
);
bool EndsWith(
    std::string_view param, 
    std::string_view value, 
    std::size_t start = 0, 
    std::size_t end = std::string::npos
);

std::string RemovePrefix(
    std::string_view param,
    std::string_view value
);

std::string RemoveSuffix(
    std::string_view param,
    std::string_view value
);

// Find methods
std::size_t Find(
    std::string_view param,
    std::string_view value,
    std::size_t start = 0,
    std::size_t end = std::string::npos
);
std::size_t RFind(
    std::string_view param,
    std::string_view value,
    std::size_t start = 0,
    std::size_t end = std::string::npos
);

std::size_t Index(
    std::string_view param,
    std::string_view value,
    std::size_t start = 0,
    std::size_t end = std::string::npos
);
std::size_t RIndex(
    std::string_view param,
    std::string_view value,
    std::size_t start = 0,
    std::size_t end = std::string::npos
);

bool Contains(
    std::string_view param,
    std::string_view value,
    std::size_t start = 0,
    std::size_t end = std::string::npos
);

// Is methods
bool IsAlNum(std::string_view param);
bool IsAlpha(std::string_view param);
bool IsDigit(std::string_view param);
bool IsLower(std::string_view param);
bool IsSpace(std::string_view param);
bool IsTitle(std::string_view param);
bool IsUpper(std::string_view param);

// Partition methods
std::vector<std::string> Partition(std::string_view param, std::string_view value);
std::vector<std::string> RPartition(std::string_view param, std::string_view value);

// Split methods
std::vector<std::string> Split(
    std::string_view param, 
    std::string_view separator = " ", 
    std::size_t count = std::string::npos
);
std::vector<std::string> RSplit(
    std::string_view param, 
    std::string_view separator = " ", 
    std::size_t count = std::string::npos
);

// Strip methods
std::string Strip(std::string_view param, std::string_view value = " ");
std::string LStrip(std::string_view param, std::string_view value = " ");
std::string RStrip(std::string_view param, std::string_view value = " ");

std::string Trim(std::string_view param, std::string_view value = " ");
std::string TrimStart(std::string_view param, std::string_view value = " ");
std::string TrimEnd(std::string_view param, std::string_view value = " ");

// Conversion methods
template <typename T>
std::string ToString(const T& val);

// Other methods
std::size_t Count(
    std::string_view param, 
    std::string_view value, 
    std::size_t start = 0, 
    std::size_t end = std::string::npos
);

template <typename... Args>
std::string Format(std::string param, Args... args);
std::string Join(const std::vector<std::string>& params, std::string_view separator);

std::string Replace(
    std::string param,
    std::string_view value1,
    std::string_view value2,
    std::size_t count = std::string::npos
);

std::string Repeat(std::string_view param, std::size_t count);
std::string Reverse(std::string_view param);


    
/*
    Case methods
*/
// Capitalize a string so only the first character is capital
inline std::string Capitalize(std::string param) {
    if (param.empty())
        return param;

    // Convert first character to uppercase
    param[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(param[0])));

    // Convert leading characters to lowercase
    for (std::size_t i = 1; i < param.size(); ++i) {
        param[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(param[i])));
    }

    return param;
}


// Converts a string to lowercase
inline std::string Lower(std::string param) {
    for (auto& c : param) {
        c = std::tolower(static_cast<unsigned char>(c));
    }

    return param;
}

// Converts a string to uppercase
inline std::string Upper(std::string param) {
    for (auto& c : param) {
        c = std::toupper(static_cast<unsigned char>(c));
    }

    return param;
}


// Swaps the case of each letter in a string
inline std::string SwapCase(std::string param) {
    for (std::size_t i = 0; i < param.length(); ++ i) {
        unsigned char c = static_cast<unsigned char>(param[i]);
        param[i] = std::isupper(c) ? static_cast<char>(std::tolower(c))
                                    : static_cast<char>(std::toupper(c));
    }

    return param;
}


// Converts the first character of each word to uppercase
inline std::string Title(std::string_view param) {
    std::vector<std::string> splitParam = Split(param);

    // Capitalize each word
    for (auto& word : splitParam) {
        word = Capitalize(word);
    }

    return Join(splitParam, " ");
}


// Checks if two strings are equal, regardless of case
[[nodiscard]] inline bool EqualsIgnoreCase(std::string_view param1, std::string_view param2) {
    return Lower(std::string(param1)) == Lower(std::string(param2));
}



/*
    Align methods
*/
// Center align a string with a specified character
inline std::string Center(std::string_view param, std::size_t length, char character) {
    if (length <= param.length())
        return std::string(param);
    
    // Calculate padding values
    std::size_t totalPadding = length - param.length();
    std::size_t leftPadding = totalPadding / 2 + (totalPadding % 2);
    std::size_t rightPadding = totalPadding / 2;

    // Return new constructed string
    return std::string(leftPadding, character) + std::string(param) + std::string(rightPadding, character);
}


// Returns a left justified version of the string
inline std::string LJust(std::string_view param, std::size_t length, char character) {
    return std::string(param) + std::string(length - std::min(length, param.length()), character);
}


// Returns a right justified version of the string
inline std::string RJust(std::string_view param, std::size_t length, char character) {
    return std::string(length - std::min(length, param.length()), character) + std::string(param);
}


// Fills a string with a specified number of zeros
inline std::string ZFill(std::string_view param, std::size_t nZero) {
    if (param.empty()) {
        return nZero == 0 ? "" : std::string(nZero, '0');
    }

    const std::string prefix = (param[0] == '-') ? "-" : ((param[0] == '+') ? "+" : "");
    const std::size_t valueStart = prefix.empty() ? 0U : 1U;
    const std::size_t valueLength = param.length() - valueStart;

    if (nZero <= valueLength) {
        return std::string(param);
    }

    return prefix + std::string(nZero - param.length(), '0') 
        + std::string(param.substr(valueStart));
}



/*
    Prefix and suffix methods
*/
// Returns whether a string starts with a specified value
[[nodiscard]] inline bool StartsWith(
    std::string_view param, 
    std::string_view value, 
    std::size_t start, 
    std::size_t end
) {
    std::size_t length = param.length();
    if (end > length) end = length;
    if (start > end) return false;

    // Create sub view of specified range
    std::string_view sub_view = std::string_view(param).substr(start, end - start);

    // Check if sub view starts with value
    return sub_view.starts_with(value);
}


// Returns whether a string ends with a specified value
[[nodiscard]] inline bool EndsWith(
    std::string_view param, 
    std::string_view value, 
    std::size_t start, 
    std::size_t end
) {
    std::size_t length = param.length();
    if (end > length) end = length;
    if (start > end) return false;

    // Create sub view of specified range
    std::string_view sub_view = std::string_view(param).substr(start, end - start);

    // Check if sub view ends with value
    return sub_view.ends_with(value);
}


// Removes the prefix of a string
inline std::string RemovePrefix(std::string_view param, std::string_view value) {
    if (!StartsWith(param, value))
        return std::string(param);
    
    return std::string(param.substr(value.length()));
}


// Removes the suffix of a string
inline std::string RemoveSuffix(std::string_view param, std::string_view value) {
    if (!EndsWith(param, value))
        return std::string(param);
    
    return std::string(param.substr(0, param.length() - value.length()));
}



/*
    Find methods
*/
// Returns the position of the first occurence of a value (returns std::string::npos if not found)
[[nodiscard]] inline std::size_t Find(
    std::string_view param,
    std::string_view value,
    std::size_t start,
    std::size_t end
) {
    if (value.empty()) {
        return (start <= param.length()) ? start : std::string::npos;
    }

    if (param.empty() || start >= param.length()) {
        return std::string::npos;
    }

    // Clamp the end boundary safely
    end = std::min(end, param.length());
    if (start >= end) {
        return std::string::npos;
    }


    // Find value
    std::size_t pos = param.find(value, start);

    // Ensure the found match does not exceed end boundary
    if (pos != std::string::npos && (pos + value.length()) <= end) {
        return pos;
    }

    return std::string::npos;
}


// Returns the position of the last occurence of a value (returns std::string::npos if not found)
[[nodiscard]] inline std::size_t RFind(
    std::string_view param,
    std::string_view value,
    std::size_t start,
    std::size_t end
) {
    if (param.empty() || start > param.length()) 
        return std::string::npos;

    // Clamp the end bound safetly
    end = std::min(end, param.length());
    if (start >= end || value.length() > end) 
        return std::string::npos;

    std::size_t pos = param.rfind(value, end - value.length());
    return (pos != std::string::npos && pos >= start) ? pos : std::string::npos;
}


// Returns the position of the first occurence of a value (throws an error if not found)
[[nodiscard]] inline std::size_t Index(
    std::string_view param,
    std::string_view value,
    std::size_t start,
    std::size_t end
) {
    std::size_t pos = Find(param, value, start, end);

    if (pos == std::string::npos) {
        throw std::invalid_argument("Value not found.");
    }

    return pos;
}


// Returns the position of the last occurence of a value (throws an error if not found)
[[nodiscard]] inline std::size_t RIndex(
    std::string_view param,
    std::string_view value,
    std::size_t start,
    std::size_t end
) {
    std::size_t pos = RFind(param, value, start, end);

    if (pos == std::string::npos) {
        throw std::invalid_argument("Value not found.");
    }

    return pos;
}


// Returns whether a string contains a value
[[nodiscard]] inline bool Contains(
    std::string_view param,
    std::string_view value,
    std::size_t start,
    std::size_t end
) {
    return Find(param, value, start, end) != std::string::npos;
}


/*
    Is methods
*/
// Returns whether all the characters in the string are alphanumeric
[[nodiscard]] inline bool IsAlNum(std::string_view param) {
    for (const auto& c : param) {
        if (!std::isalnum(static_cast<unsigned char>(c)))
            return false;
    }

    return true;
}

// Returns where all the characters in the string are in the alphabet
[[nodiscard]] inline bool IsAlpha(std::string_view param) {
    for (const auto& c : param) {
        if (!std::isalpha(static_cast<unsigned char>(c)))
            return false;
    }

    return true;
}

// Returns where all the characters in the string are digits
[[nodiscard]] inline bool IsDigit(std::string_view param) {
    for (const auto& c : param) {
        if (!std::isdigit(static_cast<unsigned char>(c)))
            return false;
    }

    return true;
}

// Returns where all the characters in the string are lowercase
[[nodiscard]] inline bool IsLower(std::string_view param) {
    bool hasAlpha = false;

    for (const auto& c : param) {
        unsigned char ch = c;

        if (std::isalpha(ch)) {
            hasAlpha = true;
            
            if (!std::islower(ch))
                return false;
        }
    }

    return hasAlpha;
}

// Returns where all the characters in the string are whitespaces
[[nodiscard]] inline bool IsSpace(std::string_view param) {
    for (const auto& c : param) {
        if (!std::isspace(static_cast<unsigned char>(c)))
            return false;
    }

    return true;
}

// Returns whether the string follows the rules of a title
[[nodiscard]] inline bool IsTitle(std::string_view param) {
    bool hasAlpha = false;

    for (const auto& word : Split(param)) {
        if (word.empty())
            continue;

        // Check first character
        unsigned char c0 = word[0];
        if (std::isalpha(c0)) {
            hasAlpha = true;

            // If in the alphabet and lowercase, return false
            if (std::islower(c0))
                return false;
        }

        // Check leading characters
        for (std::size_t i = 1; i < word.length(); ++i) {
            unsigned char c = static_cast<unsigned char>(word[i]);
            if (std::isalpha(c) && std::isupper(c))
                return false;
        }
    }

    return hasAlpha;
}

// Returns where all the characters in the string are uppercase
[[nodiscard]] inline bool IsUpper(std::string_view param) {
    bool hasAlpha = false;

    for (const auto& c : param) {
        unsigned char ch = c;

        if (std::isalpha(ch)) {
            hasAlpha = true;
            
            if (!std::isupper(ch))
                return false;
        }
    }

    return hasAlpha;
}



/*
    Partition methods
*/
// Returns a vector where the string is split into three parts
inline std::vector<std::string> Partition(std::string_view param, std::string_view value) {
    std::vector<std::string> v(3, "");
    if (param.length() < value.length()) {
        v[0] = param;
        return v;
    }
    
    // Find pos
    std::size_t pos = Find(param, value);

    // Check if value was not found
    if (pos == std::string::npos) {
        v[0] = param;
    }
    // Else partition vector
    else {
        v[0] = param.substr(0, pos);
        v[1] = param.substr(pos, value.length());
        v[2] = param.substr(pos + value.length());
    }

    return v;
}


// Returns a vector where the string is split into three parts (finds the last occurence)
inline std::vector<std::string> RPartition(std::string_view param, std::string_view value) {
    std::vector<std::string> v(3, "");
    if (param.length() < value.length()) {
        v[2] = param;
        return v;
    }
    
    // Find pos
    std::size_t pos = RFind(param, value);

    // Check if value was not found
    if (pos == std::string::npos) {
        v[2] = param; // Param is in last index
    }
    // Else partition vector
    else {
        v[0] = param.substr(0, pos);
        v[1] = param.substr(pos, value.length());
        v[2] = param.substr(pos + value.length());
    }

    return v;
}



/*
    Split methods
*/
// Splits a string into a vector at a specified separator
inline std::vector<std::string> Split(
    std::string_view param, 
    std::string_view separator, 
    std::size_t count
) {
    std::vector<std::string> v;

    if (separator.empty()) {
        return v;
    }

    // Find all occurences
    std::size_t pos = param.find(separator, 0);
    std::size_t lastPos = 0;

    while (pos != std::string::npos && count > 0) {
        // Push back splitted substring
        v.push_back(std::string(param.substr(lastPos, pos - lastPos)));

        lastPos = pos + separator.length();
        pos = param.find(separator, pos + separator.length());
        --count;
    }

    v.push_back(std::string(param.substr(lastPos)));

    return v;
}


// Splits a string into a vector at a specified separator (starts from the last occurences)
inline std::vector<std::string> RSplit(
    std::string_view param, 
    std::string_view separator, 
    std::size_t count
) {
    std::vector<std::string> v;

    if (separator.empty()) {
        return v;
    }

    // Find all occurences
    std::size_t endPos = param.length();
    
    while (count > 0) {
        // Find the rightmost occurrence of the separator before the current endPos
        std::size_t pos = param.rfind(separator, endPos == 0 ? std::string_view::npos : endPos - 1);
        
        if (pos == std::string_view::npos) {
            break;
        }

        // Extract the substring to the right of the separator up to endPos
        std::size_t tokenStart = pos + separator.length();
        v.insert(v.begin(), std::string(param.substr(tokenStart, endPos - tokenStart)));

        // Move the end tracking boundary to the left of the separator
        endPos = pos;
        --count;
    }

    // Insert the remaining leftmost piece at the front
    v.insert(v.begin(), std::string(param.substr(0, endPos)));

    return v;
}



/*
    Strip methods
*/
// Strips the whitespace from the start and end of a string
inline std::string Strip(std::string_view param, std::string_view value) {
    if (value.empty())
        return std::string(param);

    // Find first not of value for start and end
    std::size_t startPos = param.find_first_not_of(value);
    
    if (startPos == std::string::npos)
        return "";

    std::size_t endPos = param.find_last_not_of(value);

    // Return a substring
    return std::string(param.substr(startPos, endPos - startPos + 1));
}


// Strips the whitespace from the start of a string
inline std::string LStrip(std::string_view param, std::string_view value) {
    if (value.empty())
        return std::string(param);

    std::size_t startPos = param.find_first_not_of(value);
    
    if (startPos == std::string::npos)
        return "";

    // Return a substring
    return std::string(param.substr(startPos));
}

// Strips the whitespace from the end of a string
inline std::string RStrip(std::string_view param, std::string_view value) {
    if (value.empty())
        return std::string(param);

    std::size_t endPos = param.find_last_not_of(value);

    // Return a substring
    return std::string(param.substr(0, endPos + 1));
}


// Trims the whitespace from the start and end of a string
inline std::string Trim(std::string_view param, std::string_view value) {
    return Strip(param, value);
}

// Trims the whitespace from the start of a string
inline std::string TrimStart(std::string_view param, std::string_view value) {
    return LStrip(param, value);
}

// Trims the whitespace from the end of a string
inline std::string TrimEnd(std::string_view param, std::string_view value) {
    return RStrip(param, value);
}



/*
    Conversion methods
*/
// Convert to string
template <typename T>
std::string ToString(const T& val) {
    // If it's already a string type or string literal, cast it directly
    if constexpr (std::is_convertible_v<T, std::string>) {
        return std::string(val);
    }
    // If it's a character, cast it directly
    else if constexpr (std::is_same_v<T, char>) {
        return std::string(1, val); 
    }
    // If it's a boolean, use ternary check
    else if constexpr (std::is_same_v<T, bool>) {
        return val ? "true" : "false";
    }
    // If it's an integer or float, use std::to_string
    else if constexpr (std::is_arithmetic_v<T>) {
        return std::to_string(val);
    } 
    // Else throw error
    else {
        throw std::invalid_argument("Unable to cast to string."); 
    }
}



/*
    Other methods
*/
// Counts the number of times a specified value occurs in a string
[[nodiscard]] inline std::size_t Count(
    std::string_view param, 
    std::string_view value, 
    std::size_t start, 
    std::size_t end
) {
    if (param.empty() || value.empty())
        return 0;

    // Safely clamp the upper bound
    std::size_t length = param.length();
    if (end > length)
        end = length;

    // Extract the valid search substring boundary
    if (start >= end)
        return 0;
    std::string_view search_range = param.substr(start, end - start);


    // Count value occurrences in string
    std::size_t count = 0;
    std::size_t pos = search_range.find(value, 0);

    while (pos != std::string::npos) {
        ++count;
        pos = search_range.find(value, pos + value.length());
    }

    return count;
}


// Returns a formatted string
template <typename... Args>
inline std::string Format(std::string param, Args... args) {
    ((param = Replace(param, "{}", ToString(args), 1)), ...);
    return param;
}


// Joins together strings with a separator
inline std::string Join(const std::vector<std::string>& params, std::string_view separator) {
    if (params.empty())
        return "";

    std::string joinedString;
    std::size_t finalIndex = params.size() - 1;

    for (std::size_t i = 0; i <= finalIndex; ++i) {
        // Add string to the joined string
        joinedString += params[i];

        // Add separator if not final string
        if (i != finalIndex) {
            joinedString += separator;
        }
    }

    return joinedString;
}


// Replaces a specified value with a specified value
inline std::string Replace(
    std::string param,
    std::string_view value1,
    std::string_view value2,
    std::size_t count
) {
    if (value1.empty())
        return param;

    // Find all occurences
    std::size_t pos = param.find(value1, 0);

    while (pos != std::string::npos && count > 0) {
        // Replace string pos with new value
        param.replace(pos, value1.length(), value2);
        
        pos = param.find(value1, pos + value2.length());
        --count;
    }

    return param;
}


// Returns a repeated string a specified number of times
inline std::string Repeat(std::string_view param, std::size_t count) {
    std::string repeatedString;

    for (std::size_t i = 0; i < count; ++i) {
        repeatedString += param;
    }

    return repeatedString;
}


// Reverses a string
inline std::string Reverse(std::string_view param) {
    return std::string(param.rbegin(), param.rend());
}

}