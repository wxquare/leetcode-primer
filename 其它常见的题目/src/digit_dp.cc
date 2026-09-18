#include <array>
#include <cctype>
#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

namespace digit_dp {
constexpr int kMod = 1'000'000'007;

namespace {
std::string normalize(std::string value) {
    if (value.empty()) throw std::invalid_argument("bound must not be empty");
    for (char digit : value) {
        if (!std::isdigit(static_cast<unsigned char>(digit))) {
            throw std::invalid_argument("bound must contain decimal digits only");
        }
    }
    const std::size_t first = value.find_first_not_of('0');
    return first == std::string::npos ? "0" : value.substr(first);
}

bool less_than(const std::string& lhs, const std::string& rhs) {
    return lhs.size() != rhs.size() ? lhs.size() < rhs.size() : lhs < rhs;
}

std::string subtract_one(std::string value) {
    if (value == "0") return {};
    std::size_t index = value.size();
    while (index > 0 && value[index - 1] == '0') {
        value[index - 1] = '9';
        --index;
    }
    --value[index - 1];
    return normalize(value);
}

int count_up_to(const std::string& bound) {
    if (bound.empty()) return 0;
    const std::size_t length = bound.size();
    using MemoEntry = std::array<std::array<int, 2>, 11>;
    std::vector<MemoEntry> memo(length);
    for (auto& entry : memo) {
        for (auto& previous : entry) previous.fill(-1);
    }
    std::function<int(std::size_t, int, bool, bool)> search =
        [&](std::size_t position, int previous, bool started, bool tight) -> int {
            if (position == length) return 1;
            int& cached = memo[position][static_cast<std::size_t>(previous)][started ? 1U : 0U];
            if (!tight && cached != -1) return cached;
            const int upper = tight ? bound[position] - '0' : 9;
            long long result = 0;
            for (int digit = 0; digit <= upper; ++digit) {
                const bool next_tight = tight && digit == upper;
                if (!started && digit == 0) {
                    result += search(position + 1, 10, false, next_tight);
                } else if (!started || digit == previous - 1 || digit == previous + 1) {
                    result += search(position + 1, digit, true, next_tight);
                }
                result %= kMod;
            }
            if (!tight) cached = static_cast<int>(result);
            return static_cast<int>(result);
        };
    return search(0, 10, false, true);
}
}  // namespace

int count_stepping_numbers(std::string low, std::string high) {
    low = normalize(std::move(low));
    high = normalize(std::move(high));
    if (less_than(high, low)) throw std::invalid_argument("low must not exceed high");
    const int result = count_up_to(high) - count_up_to(subtract_one(low));
    return (result + kMod) % kMod;
}
}  // namespace digit_dp
