#include <cctype>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <string>
#include <string_view>

namespace integer_conversion {
bool parse(std::string_view text, int& value) {
    std::size_t begin = 0;
    while (begin < text.size() && std::isspace(static_cast<unsigned char>(text[begin]))) ++begin;
    std::size_t end = text.size();
    while (end > begin && std::isspace(static_cast<unsigned char>(text[end - 1]))) --end;
    if (begin == end) return false;
    bool negative = false;
    if (text[begin] == '+' || text[begin] == '-') {
        negative = text[begin] == '-';
        if (++begin == end) return false;
    }
    const std::int64_t limit = negative
        ? -static_cast<std::int64_t>(std::numeric_limits<int>::min())
        : std::numeric_limits<int>::max();
    std::int64_t magnitude = 0;
    for (std::size_t index = begin; index < end; ++index) {
        const char character = text[index];
        if (character < '0' || character > '9') return false;
        const int digit = character - '0';
        if (magnitude > (limit - digit) / 10) return false;
        magnitude = magnitude * 10 + digit;
    }
    value = static_cast<int>(negative ? -magnitude : magnitude);
    return true;
}

std::string format(int value, unsigned base) {
    if (base < 2 || base > 36) throw std::invalid_argument("base must be in [2, 36]");
    const bool negative = value < 0;
    std::uint64_t magnitude = negative
        ? static_cast<std::uint64_t>(-static_cast<std::int64_t>(value))
        : static_cast<std::uint64_t>(value);
    std::string result;
    do {
        const unsigned digit = static_cast<unsigned>(magnitude % base);
        result.push_back(static_cast<char>(digit < 10 ? '0' + digit : 'a' + digit - 10));
        magnitude /= base;
    } while (magnitude != 0);
    if (negative) result.push_back('-');
    return std::string(result.rbegin(), result.rend());
}
}  // namespace integer_conversion
